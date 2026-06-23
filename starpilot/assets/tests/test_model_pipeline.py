from openpilot.starpilot.assets import download_functions
from openpilot.starpilot.assets.model_manager import MANIFEST_CANDIDATES, ModelManager
from openpilot.starpilot.common.model_versions import UNIFIED_ARTIFACT_FORMAT


def test_v22_is_the_only_manifest_candidate():
  assert MANIFEST_CANDIDATES == ("v22",)


def test_behavior_version_does_not_control_artifact_layout():
  manager = object.__new__(ModelManager)
  assert manager._required_files("example", UNIFIED_ARTIFACT_FORMAT) == [
    "example_driving_tinygrad.pkl",
  ]
  assert manager._required_files("example", "") == [
    "example_driving_tinygrad.pkl",
  ]
  assert manager._required_files("example", "split") == []


def test_dropbox_urls_are_direct_downloads():
  url = "https://www.dropbox.com/scl/fi/id/model.pkl?rlkey=key&st=value&dl=0"
  normalized = download_functions.normalize_download_url(url)
  assert normalized.count("dl=1") == 1
  assert "dl=0" not in normalized
  assert "rlkey=key" in normalized


def test_download_verification_uses_manifest_size_and_sha(tmp_path, monkeypatch):
  artifact = tmp_path / "model.pkl"
  artifact.write_bytes(b"unified model")
  monkeypatch.setattr(download_functions, "get_remote_file_size", lambda *args, **kwargs: 0)

  assert download_functions.verify_download(
    artifact,
    "https://example.com/model.pkl",
    allow_unknown_size=True,
    expected_size=artifact.stat().st_size,
    expected_sha256="02f64c1311bd6392462fa9c7c929b002057f261fdcef2050554c08694e7d2120",
  )
  assert not download_functions.verify_download(
    artifact,
    "https://example.com/model.pkl",
    allow_unknown_size=True,
    expected_size=artifact.stat().st_size + 1,
  )
