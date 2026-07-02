#!/usr/bin/env python3
from dataclasses import asdict, dataclass
from functools import cache
import json
import os
import pathlib
import subprocess

from openpilot.common.basedir import BASEDIR
from openpilot.common.swaglog import cloudlog
from openpilot.common.git import get_commit, get_origin, get_branch, get_short_branch, get_commit_date

RELEASE_BRANCHES = ['StarPilot', 'StarPilot-Vetting']
TESTED_BRANCHES = RELEASE_BRANCHES + ['StarPilot-Staging', 'StarPilot-Testing']

BUILD_METADATA_FILENAME = "build.json"
BUILD_METADATA_CACHE_FILENAME = "starpilot_build_metadata_cache.json"

training_version: str = "0.2.0"
terms_version: str = "2"


def get_version(path: str = BASEDIR) -> str:
  with open(os.path.join(path, "common", "version.h")) as _versionf:
    version = _versionf.read().split('"')[1]
  return version


def get_release_notes(path: str = BASEDIR) -> str:
  with open(os.path.join(path, "RELEASES.md")) as f:
    return f.read().split('\n\n', 1)[0]


@cache
def is_prebuilt(path: str = BASEDIR) -> bool:
  return os.path.exists(os.path.join(path, 'prebuilt'))


@cache
def is_dirty(cwd: str = BASEDIR) -> bool:
  if not get_origin() or not get_short_branch():
    return True

  dirty = False
  try:
    # Actually check dirty files
    if not is_prebuilt(cwd):
      # This is needed otherwise touched files might show up as modified
      try:
        subprocess.check_call(["git", "update-index", "--refresh"], cwd=cwd)
      except subprocess.CalledProcessError:
        pass

      branch = get_branch()
      if not branch:
        return True
      dirty = (subprocess.call(["git", "diff-index", "--quiet", branch, "--"], cwd=cwd)) != 0
  except subprocess.CalledProcessError:
    cloudlog.exception("git subprocess failed while checking dirty")
    dirty = True

  return dirty


@dataclass
class OpenpilotMetadata:
  version: str
  release_notes: str
  git_commit: str
  git_origin: str
  git_commit_date: str
  build_style: str
  is_dirty: bool  # whether there are local changes

  @property
  def short_version(self) -> str:
    return self.version.split('-')[0]

  @property
  def comma_remote(self) -> bool:
    # note to fork maintainers, this is used for release metrics. please do not
    # touch this to get rid of the orange startup alert. there's better ways to do that
    return self.git_normalized_origin == "github.com/commaai/openpilot"

  @property
  def git_normalized_origin(self) -> str:
    return self.git_origin \
      .replace("git@", "", 1) \
      .replace(".git", "", 1) \
      .replace("https://", "", 1) \
      .replace(":", "/", 1)


@dataclass
class BuildMetadata:
  channel: str
  openpilot: OpenpilotMetadata

  @property
  def tested_channel(self) -> bool:
    return self.channel in TESTED_BRANCHES

  @property
  def release_channel(self) -> bool:
    return self.channel in RELEASE_BRANCHES

  @property
  def canonical(self) -> str:
    return f"{self.openpilot.version}-{self.openpilot.git_commit}-{self.openpilot.build_style}"

  @property
  def ui_description(self) -> str:
    return f"{self.openpilot.version} / {self.openpilot.git_commit[:6]} / {self.channel}"


def build_metadata_from_dict(build_metadata: dict) -> BuildMetadata:
  channel = build_metadata.get("channel", "unknown")
  openpilot_metadata = build_metadata.get("openpilot", {})
  version = openpilot_metadata.get("version", "unknown")
  release_notes = openpilot_metadata.get("release_notes", "unknown")
  git_commit = openpilot_metadata.get("git_commit", "unknown")
  git_origin = openpilot_metadata.get("git_origin", "unknown")
  git_commit_date = openpilot_metadata.get("git_commit_date", "unknown")
  build_style = openpilot_metadata.get("build_style", "unknown")
  return BuildMetadata(channel,
            OpenpilotMetadata(
              version=version,
              release_notes=release_notes,
              git_commit=git_commit,
              git_origin=git_origin,
              git_commit_date=git_commit_date,
              build_style=build_style,
              is_dirty=False))


def _read_text_file(path: pathlib.Path) -> str | None:
  try:
    return path.read_text(encoding="utf-8").strip()
  except OSError:
    return None


def _read_git_ref(git_folder: pathlib.Path, ref: str) -> str | None:
  ref_value = _read_text_file(git_folder / ref)
  if ref_value:
    return ref_value.splitlines()[0].strip()

  packed_refs = _read_text_file(git_folder / "packed-refs")
  if packed_refs is None:
    return None

  for line in packed_refs.splitlines():
    if not line or line.startswith(("#", "^")):
      continue

    parts = line.split()
    if len(parts) == 2 and parts[1] == ref:
      return parts[0]

  return None


def _read_git_config_value(git_folder: pathlib.Path, section: str, key: str) -> str | None:
  config = _read_text_file(git_folder / "config")
  if config is None:
    return None

  current_section = None
  for raw_line in config.splitlines():
    line = raw_line.strip()
    if not line or line.startswith(("#", ";")):
      continue

    if line.startswith("[") and line.endswith("]"):
      current_section = line[1:-1]
      continue

    if current_section != section or "=" not in line:
      continue

    config_key, value = line.split("=", 1)
    if config_key.strip() == key:
      return value.strip()

  return None


def _read_git_metadata(path: str) -> dict[str, str] | None:
  git_folder = pathlib.Path(path) / ".git"
  if not git_folder.is_dir():
    return None

  head = _read_text_file(git_folder / "HEAD")
  if not head:
    return None

  branch = "HEAD"
  commit = head.splitlines()[0].strip()
  if head.startswith("ref:"):
    ref = head.split(":", 1)[1].strip()
    branch = ref.rsplit("/", 1)[-1]
    commit = _read_git_ref(git_folder, ref)

  if not commit:
    return None

  remote = _read_git_config_value(git_folder, f'branch "{branch}"', "remote") or "origin"
  origin = _read_git_config_value(git_folder, f'remote "{remote}"', "url")
  if origin is None and remote != "origin":
    origin = _read_git_config_value(git_folder, 'remote "origin"', "url")

  return {
    "branch": branch,
    "commit": commit,
    "origin": origin or "",
  }


def _build_metadata_cache_path(path: str) -> pathlib.Path | None:
  if not (pathlib.Path(path) / ".git").is_dir():
    return None

  cache_root = pathlib.Path(os.environ.get("OPENPILOT_BUILD_METADATA_CACHE_ROOT", "/cache/starpilot"))
  return cache_root / BUILD_METADATA_CACHE_FILENAME


def _read_cached_build_metadata(path: str, git_metadata: dict[str, str]) -> BuildMetadata | None:
  cache_path = _build_metadata_cache_path(path)
  if cache_path is None:
    return None

  try:
    cache_payload = json.loads(cache_path.read_text(encoding="utf-8"))
  except (OSError, json.JSONDecodeError):
    return None

  if cache_payload.get("path") != str(pathlib.Path(path).resolve()) or cache_payload.get("git_metadata") != git_metadata:
    return None

  build_metadata = cache_payload.get("build_metadata")
  if not isinstance(build_metadata, dict):
    return None

  return build_metadata_from_dict(build_metadata)


def _write_cached_build_metadata(path: str, git_metadata: dict[str, str], build_metadata: BuildMetadata) -> None:
  cache_path = _build_metadata_cache_path(path)
  if cache_path is None:
    return

  try:
    cache_path.parent.mkdir(parents=True, exist_ok=True)
    cache_path.write_text(json.dumps({
      "path": str(pathlib.Path(path).resolve()),
      "git_metadata": git_metadata,
      "build_metadata": asdict(build_metadata),
    }, separators=(",", ":")), encoding="utf-8")
  except OSError:
    pass


def get_build_metadata(path: str = BASEDIR) -> BuildMetadata:
  build_metadata_path = pathlib.Path(path) / BUILD_METADATA_FILENAME

  if build_metadata_path.exists():
    build_metadata = json.loads(build_metadata_path.read_text())
    return build_metadata_from_dict(build_metadata)

  git_folder = pathlib.Path(path) / ".git"

  if git_folder.exists():
    prebuilt = is_prebuilt(path)
    git_metadata = _read_git_metadata(path)
    if prebuilt and git_metadata is not None:
      cached_metadata = _read_cached_build_metadata(path, git_metadata)
      if cached_metadata is not None:
        return cached_metadata

      build_metadata = BuildMetadata(git_metadata["branch"],
                      OpenpilotMetadata(
                        version=get_version(path),
                        release_notes=get_release_notes(path),
                        git_commit=git_metadata["commit"],
                        git_origin=git_metadata["origin"] or get_origin(path),
                        git_commit_date=get_commit_date(path, git_metadata["commit"]),
                        build_style="unknown",
                        is_dirty=False))
      _write_cached_build_metadata(path, git_metadata, build_metadata)
      return build_metadata

    return BuildMetadata(get_short_branch(path),
                         OpenpilotMetadata(
                           version=get_version(path),
                           release_notes=get_release_notes(path),
                           git_commit=get_commit(path),
                           git_origin=get_origin(path),
                           git_commit_date=get_commit_date(path),
                           build_style="unknown",
                           is_dirty=is_dirty(path)))

  cloudlog.exception("unable to get build metadata")
  raise Exception("invalid build metadata")


if __name__ == "__main__":
  print(get_build_metadata())
