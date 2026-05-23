from dataclasses import dataclass
import math
import pyray as rl
from openpilot.common.constants import CV
from openpilot.selfdrive.ui.ui_state import ui_state
from openpilot.system.ui.lib.text_measure import measure_text_cached
from openpilot.selfdrive.ui.onroad.starpilot.starpilot_border import _csc_state, _intensity, _glow_color

@dataclass
class AetherGaugeData:
  text: str
  unit: str = ""
  label: str = ""
  animation: str = "none" # e.g. "down_arrows"
  color: rl.Color = rl.WHITE

class AetherGaugeSource:
  def is_active(self) -> bool:
    return False

  def get_gauge_data(self) -> AetherGaugeData:
    raise NotImplementedError

class CurveSpeedSource(AetherGaugeSource):
  def is_active(self) -> bool:
    state = _csc_state()
    return state is not None and state['active']

  def get_gauge_data(self) -> AetherGaugeData:
    state = _csc_state()
    if state is None:
      return AetherGaugeData(text="")
      
    plan = ui_state.sm["starpilotPlan"]
    car_state = ui_state.sm["carState"]
    
    speed_conversion = CV.MS_TO_KPH if ui_state.is_metric else CV.MS_TO_MPH
    speed_unit = "km/h" if ui_state.is_metric else "mph"
    
    csc_speed = getattr(plan, "cscSpeed", 0.0)
    v_ego = car_state.vEgo if car_state else 0.0
    
    csc_speed_val = int(round(min(v_ego, csc_speed) * speed_conversion))
    
    intensity = _intensity(state['curvature'])
    color = _glow_color(intensity)
    
    return AetherGaugeData(
      text=str(csc_speed_val),
      unit=speed_unit,
      label="CURVE",
      animation="down_arrows",
      color=color
    )

class AetherGauge:
  def __init__(self):
    self.sources: list[AetherGaugeSource] = [CurveSpeedSource()]

  def get_active_data(self) -> AetherGaugeData | None:
    for source in self.sources:
      if source.is_active():
        return source.get_gauge_data()
    return None

  def render(self, rect: rl.Rectangle, font_bold: rl.Font, font_medium: rl.Font):
    data = self.get_active_data()
    if not data:
      return

    cx = rect.x + rect.width / 2
    cy = rect.y + 340

    if data.animation == "down_arrows":
      self._render_down_arrows(cx, cy, data.color)
      text_y = cy + 50
    else:
      text_y = cy

    self._render_text(cx, text_y, data, font_bold, font_medium)

  def _render_down_arrows(self, cx: float, cy: float, color: rl.Color):
    progress = (rl.get_time() * 1.5) % 1.0
    spacing = 16.0
    chevron_w = 20.0
    chevron_h = 10.0
    thickness = 4.0

    for i in range(3):
      y_off = (i + progress) * spacing
      y = cy + y_off

      dist_normalized = (i + progress) / 3.0
      alpha_factor = math.sin(dist_normalized * math.pi)
      alpha = int(color.a * alpha_factor)

      chevron_color = rl.Color(color.r, color.g, color.b, alpha)

      # Drop shadow (black with half of chevron's alpha)
      shadow_color = rl.Color(0, 0, 0, int(alpha * 0.5))
      rl.draw_line_ex(rl.Vector2(int(cx - chevron_w), int(y - chevron_h + 2)), rl.Vector2(int(cx), int(y + 2)), thickness, shadow_color)
      rl.draw_line_ex(rl.Vector2(int(cx + chevron_w), int(y - chevron_h + 2)), rl.Vector2(int(cx), int(y + 2)), thickness, shadow_color)

      # Main chevron lines
      rl.draw_line_ex(rl.Vector2(int(cx - chevron_w), int(y - chevron_h)), rl.Vector2(int(cx), int(y)), thickness, chevron_color)
      rl.draw_line_ex(rl.Vector2(int(cx + chevron_w), int(y - chevron_h)), rl.Vector2(int(cx), int(y)), thickness, chevron_color)

  def _render_text(self, cx: float, cy: float, data: AetherGaugeData, font_bold: rl.Font, font_medium: rl.Font):
    speed_text = data.text
    unit_text = data.unit

    speed_size = measure_text_cached(font_bold, speed_text, 48)
    unit_size = measure_text_cached(font_medium, unit_text, 24)

    gap = 6
    total_w = speed_size.x + gap + unit_size.x
    start_x = cx - total_w / 2

    # Draw outline for speed
    speed_pos = rl.Vector2(int(start_x), int(cy))
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(speed_pos.x - 1, speed_pos.y - 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(speed_pos.x + 1, speed_pos.y - 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(speed_pos.x - 1, speed_pos.y + 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(speed_pos.x + 1, speed_pos.y + 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, speed_text, speed_pos, 48, 0, rl.WHITE)

    # Draw outline for unit
    unit_y = cy + (speed_size.y - unit_size.y) - 2
    unit_pos = rl.Vector2(int(start_x + speed_size.x + gap), int(unit_y))

    rl.draw_text_ex(font_medium, unit_text, rl.Vector2(unit_pos.x - 1, unit_pos.y - 1), 24, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit_text, rl.Vector2(unit_pos.x + 1, unit_pos.y - 1), 24, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit_text, rl.Vector2(unit_pos.x - 1, unit_pos.y + 1), 24, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit_text, rl.Vector2(unit_pos.x + 1, unit_pos.y + 1), 24, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit_text, unit_pos, 24, 0, data.color)
