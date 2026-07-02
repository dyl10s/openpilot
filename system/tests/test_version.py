import json

from openpilot.system import version


def _write_minimal_git_checkout(path, branch="StarPilot", commit="1" * 40, origin="https://example.com/openpilot"):
  git_folder = path / ".git"
  git_folder.mkdir()
  (git_folder / "refs" / "heads").mkdir(parents=True)
  (git_folder / "HEAD").write_text(f"ref: refs/heads/{branch}\n", encoding="utf-8")
  (git_folder / "refs" / "heads" / branch).write_text(f"{commit}\n", encoding="utf-8")
  (git_folder / "config").write_text(
    f"""[remote "origin"]
  url = {origin}
[branch "{branch}"]
  remote = origin
  merge = refs/heads/{branch}
""",
    encoding="utf-8",
  )
  return {
    "branch": branch,
    "commit": commit,
    "origin": origin,
  }


def test_read_git_metadata_reads_head_ref_and_origin(tmp_path):
  git_metadata = _write_minimal_git_checkout(tmp_path, branch="Dom", commit="a" * 40)

  assert version._read_git_metadata(str(tmp_path)) == git_metadata


def test_get_build_metadata_uses_prebuilt_git_cache(tmp_path, monkeypatch):
  git_metadata = _write_minimal_git_checkout(tmp_path, branch="Dom", commit="b" * 40)
  cache_root = tmp_path / "cache"
  monkeypatch.setenv("OPENPILOT_BUILD_METADATA_CACHE_ROOT", str(cache_root))
  (tmp_path / "prebuilt").write_text("", encoding="utf-8")
  (tmp_path / "common").mkdir()
  (tmp_path / "common" / "version.h").write_text('#define COMMA_VERSION "1.2.3"\n', encoding="utf-8")
  (tmp_path / "RELEASES.md").write_text("Release notes\n\nOlder notes\n", encoding="utf-8")

  cached_payload = {
    "path": str(tmp_path.resolve()),
    "git_metadata": git_metadata,
    "build_metadata": {
      "channel": "Dom",
      "openpilot": {
        "version": "1.2.3",
        "release_notes": "Release notes",
        "git_commit": git_metadata["commit"],
        "git_origin": git_metadata["origin"],
        "git_commit_date": "123 1970-01-01 00:02:03 +0000",
        "build_style": "unknown",
        "is_dirty": False,
      },
    },
  }
  cache_root.mkdir()
  (cache_root / version.BUILD_METADATA_CACHE_FILENAME).write_text(json.dumps(cached_payload), encoding="utf-8")
  monkeypatch.setattr(version, "get_commit_date", lambda *args, **kwargs: (_ for _ in ()).throw(AssertionError("cache miss")))

  build_metadata = version.get_build_metadata(str(tmp_path))

  assert build_metadata.channel == "Dom"
  assert build_metadata.openpilot.git_commit == git_metadata["commit"]
  assert build_metadata.openpilot.git_commit_date == "123 1970-01-01 00:02:03 +0000"
