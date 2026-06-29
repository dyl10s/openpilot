from __future__ import annotations

import pyray as rl

from openpilot.system.hardware import HARDWARE
from openpilot.selfdrive.ui.lib.starpilot_state import starpilot_state
from openpilot.system.ui.lib.application import gui_app
from openpilot.system.ui.lib.multilang import tr
from openpilot.system.ui.widgets import DialogResult
from openpilot.system.ui.widgets.confirm_dialog import ConfirmDialog

from openpilot.selfdrive.ui.layouts.settings.starpilot.panel import _SettingsPage
from openpilot.selfdrive.ui.layouts.settings.starpilot.aethergrid import (
  AetherListMetrics,
  AetherSettingsView,
  AetherSliderDialog,
  BACK_BTN,
  DEFAULT_PANEL_STYLE,
  HubTile,
  SettingRow,
  SettingSection,
  TileGrid,
  _draw_back_button,
  _draw_rounded_fill,
  _draw_rounded_stroke,
  _point_hits,
)


def _confirm_reboot_toggle(params, key, state):
  params.put_bool(key, state)
  from openpilot.selfdrive.ui.ui_state import ui_state
  if ui_state.started:
    gui_app.push_widget(ConfirmDialog(
      tr("Reboot required. Reboot now?"), tr("Reboot"), tr("Cancel"),
      callback=lambda res: HARDWARE.reboot() if res == DialogResult.CONFIRM else None,
    ))


CUSTOM_METRICS = AetherListMetrics(
  max_content_width=1560,
  outer_margin_x=18,
  outer_margin_y=10,
  panel_padding_x=16,
  panel_padding_top=16,
  panel_padding_bottom=12,
  header_height=0,
  section_gap=12,
  section_header_height=28,
  section_header_gap=8,
  row_height=104,
  utility_row_height=88,
)

ROW_HEIGHT = CUSTOM_METRICS.row_height
PANEL_STYLE = DEFAULT_PANEL_STYLE

_LATERAL_TUNE_KEYS = ["TurnDesires", "NNFF", "NNFFLite", "ForceTorqueController"]
_ADVANCED_LATERAL_KEYS = ["ForceAutoTune", "ForceAutoTuneOff"]


def _sync_parent(params, parent_key, child_keys):
  if any(params.get_bool(k) for k in child_keys):
    if not params.get_bool(parent_key):
      params.put_bool(parent_key, True)
  else:
    if params.get_bool(parent_key):
      params.put_bool(parent_key, False)


class _BackButtonSettingsView(AetherSettingsView):
  """AetherSettingsView with a back button pill drawn in the scroll content header."""

  def __init__(self, *args, **kwargs):
    super().__init__(*args, **kwargs)
    self._back_btn_rect = None
    self._has_header = False

  def _target_at(self, mouse_pos):
    if self._back_btn_rect and _point_hits(mouse_pos, self._back_btn_rect, None, pad_x=8, pad_y=8):
      return BACK_BTN
    return super()._target_at(mouse_pos)

  def _activate_target(self, target_id):
    if target_id == BACK_BTN:
      self._controller._go_back()
    else:
      super()._activate_target(target_id)

  def _draw_scroll_content(self, rect, width):
    pill_h = 52
    y = rect.y + self._scroll_offset
    pill_rect = rl.Rectangle(rect.x, y, rect.width, pill_h)
    center_y = pill_rect.y + pill_h / 2

    _draw_rounded_fill(pill_rect, rl.Color(18, 16, 24, 200), radius_px=14)
    _draw_rounded_stroke(pill_rect, rl.Color(255, 255, 255, 22), radius_px=14)

    mouse_pos = gui_app.last_mouse_event.pos
    is_pressed = getattr(self, '_pressed_target', None) == BACK_BTN
    is_hovered = _point_hits(mouse_pos, pill_rect, None, pad_x=0, pad_y=0) and \
                 self._back_btn_rect and _point_hits(mouse_pos, self._back_btn_rect, None, pad_x=8, pad_y=8)
    self._back_btn_rect = _draw_back_button(pill_rect, center_y, is_pressed, is_hovered)

    crumb_x = pill_rect.x + 58
    crumb_w = pill_rect.width - (crumb_x - pill_rect.x) - 20
    crumb_rect = rl.Rectangle(crumb_x, pill_rect.y, crumb_w, pill_h)
    self._breadcrumbs.draw(crumb_rect)

    self._scroll_offset += pill_h + 12
    super()._draw_scroll_content(rect, width)


class SteeringManagerView(AetherSettingsView):
  """Hub view with 3 category tiles leading to sub-panels."""

  @property
  def vertical_scrolling_disabled(self) -> bool:
    return True

  def __init__(self, controller, sections, **kwargs):
    super().__init__(controller, sections, **kwargs)
    self._controller = controller
    self._hub_grid = TileGrid(columns=2, padding=12)
    self._hub_grid.set_touch_valid_callback(lambda: self._scroll_panel.is_touch_valid())
    self._child(self._hub_grid)
    self._init_hub()

  def show_event(self):
    super().show_event()
    starpilot_state.update(force=True)

  def _init_hub(self):
    hub_data = [
      {
        "key": "steering_behavior",
        "title": tr("Steering Behavior"),
        "desc": tr("Configure when steering engages, pauses, and resumes."),
        "icon": "steering",
        "color": "#8B5CF6",
      },
      {
        "key": "lane_changes",
        "title": tr("Lane Changes"),
        "desc": tr("Configure lane change behavior, speed thresholds, and timing."),
        "icon": "navigate",
        "color": "#8B5CF6",
      },
      {
        "key": "tuning",
        "title": tr("Advanced Lateral Tuning"),
        "desc": tr("Fine-tune steering response, feedforward, and auto-tuning."),
        "icon": "system",
        "color": "#8B5CF6",
      },
    ]

    self._hub_grid.clear()
    for d in hub_data:
      self._hub_grid.add_tile(HubTile(
        title=d["title"],
        desc=d["desc"],
        icon_key=d["icon"],
        on_click=lambda k=d["key"]: self._controller._navigate_to(k),
        bg_color=d["color"],
      ))

  def _render(self, rect: rl.Rectangle):
    self.set_rect(rect)
    self._interactive_rects.clear()

    margin_x = 18.0
    margin_y = 24.0

    grid_x = rect.x + margin_x
    grid_y = rect.y + margin_y
    grid_w = rect.width - margin_x * 2
    grid_h = rect.y + rect.height - grid_y - margin_y

    self._scroll_rect = rl.Rectangle(grid_x, grid_y, grid_w, grid_h)
    self._content_height = grid_h

    self._scroll_panel.set_enabled(self.is_visible)
    self._scroll_offset = self._scroll_panel.update(
      self._scroll_rect, self._scroll_rect.height
    )

    if self.vertical_scrolling_disabled:
      self._scroll_offset = 0.0

    self._draw_scroll_content(self._scroll_rect, self._scroll_rect.width)

  def _draw_scroll_content(self, rect: rl.Rectangle, width: float):
    y = rect.y + self._scroll_offset
    self._hub_grid.set_parent_rect(self._scroll_rect)
    self._hub_grid.render(rl.Rectangle(rect.x, y, width, rect.height))


# ═══════════════════════════════════════════════════════════════
# StarPilotLateralLayout — controller
# ═══════════════════════════════════════════════════════════════

class StarPilotLateralLayout(_SettingsPage):

  def __init__(self):
    super().__init__()
    self._build_sub_panels()
    self._manager_view = SteeringManagerView(
      self, [],
      header_title=tr("Steering"),
      header_subtitle=tr("Configure steering behavior, lane changes, and tuning parameters."),
      panel_style=PANEL_STYLE,
    )

  def _build_sub_panels(self):
    p = self._params
    cs = starpilot_state.car_state

    def alt_on():
      return p.get_bool("AdvancedLateralTune")

    def aol_on():
      return p.get_bool("AlwaysOnLateral")

    def lc_on():
      return p.get_bool("LaneChanges")

    def nlc_on():
      return lc_on() and p.get_bool("NudgelessLaneChange")

    def pos_on():
      return p.get_bool("PauseLateralOnSignal")

    def _show(key):
      return lambda: self._on_select(key)

    # ── Steering Behavior ──
    self._steering_behavior_rows = [
      SettingRow("AlwaysOnLateral", "toggle", tr("Always On Lateral"),
                 subtitle=tr("Steering stays active when ACC is off."),
                 get_state=lambda: p.get_bool("AlwaysOnLateral"),
                 set_state=lambda s: _confirm_reboot_toggle(p, "AlwaysOnLateral", s) if s else p.put_bool("AlwaysOnLateral", False)),
      SettingRow("PauseAOLOnBrake", "value", tr("Pause AOL On Brake"),
                 subtitle=tr("Pause AOL below this speed while brake is pressed."),
                 get_value=lambda: f"{p.get_int('PauseAOLOnBrake')} mph",
                 on_click=_show("PauseAOLOnBrake"),
                 visible=aol_on),
      SettingRow("PauseLateralOnSignal", "toggle", tr("Turn Signal Only"),
                 subtitle=tr("Only pause steering when turn signal is active."),
                 get_state=lambda: p.get_bool("PauseLateralOnSignal"),
                 set_state=lambda s: p.put_bool("PauseLateralOnSignal", s)),
      SettingRow("PauseLateralSpeed", "value", tr("Pause Lateral Below"),
                 subtitle=tr("Pause steering below the set speed."),
                 get_value=lambda: f"{p.get_int('PauseLateralSpeed')} mph",
                 on_click=_show("PauseLateralSpeed")),
      SettingRow("LateralResumeDelay", "value", tr("Resume Delay"),
                 subtitle=tr("Delay before lateral resumes after signal off. 0 = Off."),
                 get_value=lambda: tr("Off") if p.get_float("LateralResumeDelay") == 0 else f"{p.get_float('LateralResumeDelay'):.1f}s",
                 on_click=_show("LateralResumeDelay"),
                 visible=pos_on),
      SettingRow("NavDesiresAllowed", "toggle", tr("Use Route Desires"),
                 subtitle=tr("Allow navigation to request lane keep and turns."),
                 get_state=lambda: p.get_bool("NavDesiresAllowed"),
                 set_state=lambda s: p.put_bool("NavDesiresAllowed", s)),
    ]

    # ── Lane Changes ──
    self._lane_change_rows = [
      SettingRow("LaneChanges", "toggle", tr("Lane Changes"),
                 subtitle=tr("Allow openpilot to change lanes."),
                 get_state=lambda: p.get_bool("LaneChanges"),
                 set_state=lambda s: p.put_bool("LaneChanges", s)),
      SettingRow("NudgelessLaneChange", "toggle", tr("Auto Lane Changes"),
                 subtitle=tr("Signal triggers automatic lane change."),
                 get_state=lambda: p.get_bool("NudgelessLaneChange"),
                 set_state=lambda s: p.put_bool("NudgelessLaneChange", s),
                 visible=lc_on),
      SettingRow("OneLaneChange", "toggle", tr("One Per Signal"),
                 subtitle=tr("One lane change per signal activation."),
                 get_state=lambda: p.get_bool("OneLaneChange"),
                 set_state=lambda s: p.put_bool("OneLaneChange", s),
                 visible=nlc_on),
      SettingRow("MinimumLaneChangeSpeed", "value", tr("Min Lane Change Speed"),
                 subtitle=tr("Lowest speed at which openpilot will change lanes."),
                 get_value=lambda: f"{p.get_int('MinimumLaneChangeSpeed')} mph",
                 on_click=_show("MinimumLaneChangeSpeed"),
                 visible=lc_on),
      SettingRow("LaneChangeTime", "value", tr("Lane Change Delay"),
                 subtitle=tr("Delay before the start of an automatic lane change. 0 = Instant."),
                 get_value=lambda: tr("Instant") if p.get_float("LaneChangeTime") == 0 else f"{p.get_float('LaneChangeTime'):.1f}s",
                 on_click=_show("LaneChangeTime"),
                 visible=nlc_on),
      SettingRow("LaneDetectionWidth", "value", tr("Min Lane Width"),
                 subtitle=tr("Prevent lane changes into narrower lanes."),
                 get_value=lambda: f"{p.get_float('LaneDetectionWidth'):.1f} ft",
                 on_click=_show("LaneDetectionWidth"),
                 visible=nlc_on),
      SettingRow("LaneChangeSmoothing", "value", tr("Lane Change Smoothing"),
                 subtitle=tr("Smoothness of lane change commit. 10 = Stock, 1 = Smoothest."),
                 get_value=lambda: tr("Stock") if p.get_int("LaneChangeSmoothing") == 10 else f"{p.get_int('LaneChangeSmoothing')}",
                 on_click=_show("LaneChangeSmoothing"),
                 visible=lc_on),
    ]

    # ── Advanced Lateral Tuning ──
    self._tuning_rows = [
      SettingRow("AdvancedLateralTune", "toggle", tr("Advanced Lateral Tuning"),
                 subtitle=tr("Fine-tune steering response and auto-tuning."),
                 get_state=lambda: p.get_bool("AdvancedLateralTune"),
                 set_state=lambda s: p.put_bool("AdvancedLateralTune", s)),
      SettingRow("NNFF", "toggle", tr("NNFF"),
                 subtitle=tr("Neural net feedforward steering controller."),
                 get_state=lambda: p.get_bool("NNFF"),
                 set_state=lambda s: (p.put_bool("NNFF", s),
                                      s and p.put_bool("NNFFLite", False),
                                      _sync_parent(p, "LateralTune", _LATERAL_TUNE_KEYS)),
                 enabled=lambda: cs.hasNNFFLog and not cs.isAngleCar,
                 disabled_label=tr("Not Available"),
                 visible=alt_on),
      SettingRow("NNFFLite", "toggle", tr("NNFF Lite"),
                 subtitle=tr("Lightweight NNFF when full model is off."),
                 get_state=lambda: p.get_bool("NNFFLite"),
                 set_state=lambda s: (p.put_bool("NNFFLite", s),
                                      _sync_parent(p, "LateralTune", _LATERAL_TUNE_KEYS)),
                 enabled=lambda: not cs.isAngleCar,
                 disabled_label=tr("Not Available"),
                 visible=alt_on),
      SettingRow("ForceTorqueController", "toggle", tr("Force Torque Ctrl"),
                 subtitle=tr("Torque-based steering for smoother lane keeping."),
                 get_state=lambda: p.get_bool("ForceTorqueController"),
                 set_state=lambda s: (p.put_bool("ForceTorqueController", s),
                                      _sync_parent(p, "LateralTune", _LATERAL_TUNE_KEYS)),
                 enabled=lambda: not cs.isTorqueCar and not cs.isAngleCar,
                 disabled_label=tr("Not Available"),
                 visible=alt_on),
      SettingRow("TurnDesires", "toggle", tr("Force Turn Desires"),
                 subtitle=tr("Follow turn intent below min lane change speed."),
                 get_state=lambda: p.get_bool("TurnDesires"),
                 set_state=lambda s: (p.put_bool("TurnDesires", s),
                                      _sync_parent(p, "LateralTune", _LATERAL_TUNE_KEYS)),
                 visible=alt_on),
      SettingRow("ForceAutoTune", "toggle", tr("Force Auto-Tune On"),
                 subtitle=tr("Force-enable live auto-tuning for friction and lateral accel."),
                 get_state=lambda: p.get_bool("ForceAutoTune"),
                 set_state=lambda s: (p.put_bool("ForceAutoTune", s),
                                      s and p.put_bool("ForceAutoTuneOff", False),
                                      _sync_parent(p, "AdvancedLateralTune", _ADVANCED_LATERAL_KEYS)),
                 enabled=lambda: not cs.hasAutoTune and cs.isTorqueCar and not cs.isAngleCar,
                 disabled_label=tr("Not Available"),
                 visible=alt_on),
      SettingRow("ForceAutoTuneOff", "toggle", tr("Force Auto-Tune Off"),
                 subtitle=tr("Force-disable auto-tuning and use your set values."),
                 get_state=lambda: p.get_bool("ForceAutoTuneOff"),
                 set_state=lambda s: (p.put_bool("ForceAutoTuneOff", s),
                                      s and p.put_bool("ForceAutoTune", False),
                                      _sync_parent(p, "AdvancedLateralTune", _ADVANCED_LATERAL_KEYS)),
                 enabled=lambda: cs.hasAutoTune and cs.isTorqueCar and not cs.isAngleCar,
                 disabled_label=tr("Not Available"),
                 visible=alt_on),
      SettingRow("SteerDelay", "value", tr("Actuator Delay"),
                 subtitle=tr("Time between steering command and vehicle response."),
                 get_value=lambda: f"{p.get_float('SteerDelay'):.2f}s",
                 on_click=_show("SteerDelay"),
                 visible=lambda: alt_on() and cs.steerActuatorDelay != 0),
      SettingRow("SteerFriction", "value", tr("Friction"),
                 subtitle=tr("Compensates for steering friction around center."),
                 get_value=lambda: f"{p.get_float('SteerFriction'):.3f}",
                 on_click=_show("SteerFriction"),
                 visible=lambda: alt_on() and cs.friction != 0),
      SettingRow("SteerKP", "value", tr("Kp Factor"),
                 subtitle=tr("How strongly openpilot corrects lateral position."),
                 get_value=lambda: f"{p.get_float('SteerKP'):.2f}",
                 on_click=_show("SteerKP"),
                 visible=lambda: alt_on() and cs.steerKp != 0),
      SettingRow("SteerLatAccel", "value", tr("Lateral Acceleration"),
                 subtitle=tr("Maps steering torque to turning response."),
                 get_value=lambda: f"{p.get_float('SteerLatAccel'):.2f}",
                 on_click=_show("SteerLatAccel"),
                 visible=lambda: alt_on() and cs.latAccelFactor != 0),
      SettingRow("SteerRatio", "value", tr("Steer Ratio"),
                 subtitle=tr("Relationship between steering wheel and road-wheel angle."),
                 get_value=lambda: f"{p.get_float('SteerRatio'):.2f}",
                 on_click=_show("SteerRatio"),
                 visible=lambda: alt_on() and cs.steerRatio != 0),
    ]

    # ── Build sub-panels ──
    self._sub_panels["steering_behavior"] = _BackButtonSettingsView(
      self,
      [SettingSection(tr("Steering Behavior"), self._steering_behavior_rows, row_height=ROW_HEIGHT)],
      header_title=tr("Steering Behavior"),
      header_subtitle=tr("Configure when steering engages, pauses, and resumes."),
      panel_style=PANEL_STYLE,
      metrics=CUSTOM_METRICS,
    )

    self._sub_panels["lane_changes"] = _BackButtonSettingsView(
      self,
      [SettingSection(tr("Lane Changes"), self._lane_change_rows, row_height=ROW_HEIGHT)],
      header_title=tr("Lane Changes"),
      header_subtitle=tr("Configure lane change behavior, speed thresholds, and timing."),
      panel_style=PANEL_STYLE,
      metrics=CUSTOM_METRICS,
    )

    self._sub_panels["tuning"] = _BackButtonSettingsView(
      self,
      [SettingSection(tr("Advanced Lateral Tuning"), self._tuning_rows, row_height=ROW_HEIGHT)],
      header_title=tr("Advanced Lateral Tuning"),
      header_subtitle=tr("Fine-tune steering response, feedforward controllers, and auto-tuning."),
      panel_style=PANEL_STYLE,
      metrics=CUSTOM_METRICS,
    )

    self._wire_sub_panels()

  def _on_select(self, key: str):
    if key == "PauseAOLOnBrake":
      self._show_slider("PauseAOLOnBrake", 0, 100, unit=" mph")
    elif key == "PauseLateralSpeed":
      def on_speed_close(res, val):
        if res == DialogResult.CONFIRM:
          self._params.put_int("PauseLateralSpeed", int(val))
          self._params.put_bool("QOLLateral", int(val) > 0)
      current = self._params.get_int("PauseLateralSpeed")
      gui_app.push_widget(AetherSliderDialog(
        tr("Pause Lateral Below"), 0, 100, 1, current, on_speed_close,
        unit=" mph", color=self.SLIDER_COLOR))
    elif key == "LateralResumeDelay":
      self._show_slider("LateralResumeDelay", 0.0, 5.0, step=0.1, unit="s", value_type="float")
    elif key == "MinimumLaneChangeSpeed":
      self._show_slider("MinimumLaneChangeSpeed", 0, 100, unit=" mph")
    elif key == "LaneChangeTime":
      self._show_slider("LaneChangeTime", 0.0, 5.0, step=0.1, unit="s", value_type="float")
    elif key == "LaneDetectionWidth":
      self._show_slider("LaneDetectionWidth", 0.0, 15.0, step=0.1, unit=" ft", value_type="float")
    elif key == "LaneChangeSmoothing":
      self._show_lane_smoothing()
    elif key == "SteerDelay":
      self._show_slider("SteerDelay", 0.01, 1.0, step=0.01, unit="s", value_type="float")
    elif key == "SteerFriction":
      self._show_slider("SteerFriction", 0.0, max(1.0, starpilot_state.car_state.friction * 1.5), step=0.01, value_type="float")
    elif key == "SteerKP":
      self._show_slider("SteerKP", max(0.01, starpilot_state.car_state.steerKp) * 0.5, max(0.01, starpilot_state.car_state.steerKp) * 1.5, step=0.01, value_type="float")
    elif key == "SteerLatAccel":
      self._show_slider("SteerLatAccel", max(0.01, starpilot_state.car_state.latAccelFactor) * 0.5, max(0.01, starpilot_state.car_state.latAccelFactor) * 1.5, step=0.01, value_type="float")
    elif key == "SteerRatio":
      self._show_slider("SteerRatio", max(0.01, starpilot_state.car_state.steerRatio) * 0.5, max(0.01, starpilot_state.car_state.steerRatio) * 1.5, step=0.01, value_type="float")

  def _show_lane_smoothing(self):
    def on_close(res, val):
      if res == DialogResult.CONFIRM:
        self._params.put_int("LaneChangeSmoothing", int(val))
    current = self._params.get_int("LaneChangeSmoothing") if self._params.get_int("LaneChangeSmoothing") > 0 else 10
    gui_app.push_widget(AetherSliderDialog(tr("Lane Change Smoothing"), 1, 10, 1, current, on_close,
                                            color=self.SLIDER_COLOR))
