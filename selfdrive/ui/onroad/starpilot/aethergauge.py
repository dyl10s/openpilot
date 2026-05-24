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
  indicator_type: str = "none" # e.g. "road_curve"
  indicator_value: float = 0.0 # value used by indicator (e.g. curvature)
  stop_sign_confirmed: bool = False

class AetherGaugeSource:
  def is_active(self) -> bool:
    return False

  def get_gauge_data(self) -> AetherGaugeData:
    raise NotImplementedError

class ForceStopSource(AetherGaugeSource):
  def is_active(self) -> bool:
    if "starpilotPlan" not in ui_state.sm.valid or not ui_state.sm.valid["starpilotPlan"]:
      return False
    plan = ui_state.sm["starpilotPlan"]
    return getattr(plan, "forcingStop", False)

  def get_gauge_data(self) -> AetherGaugeData:
    plan = ui_state.sm["starpilotPlan"]
    
    distance_conversion = 1.0 if ui_state.is_metric else 3.28084
    dist_unit = "m" if ui_state.is_metric else "ft"
    
    forcing_stop_length = getattr(plan, "forcingStopLength", 0.0)
    dist_val = int(round(forcing_stop_length * distance_conversion))
    stop_sign_confirmed = getattr(plan, "stopSignConfirmed", False)
    
    color = rl.Color(255, 30, 60, 255) # Sleek high-contrast red
    
    return AetherGaugeData(
      text=str(dist_val),
      unit=dist_unit,
      label="STOP",
      animation="force_stop",
      color=color,
      indicator_type="force_stop",
      indicator_value=forcing_stop_length,
      stop_sign_confirmed=stop_sign_confirmed
    )

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
      color=color,
      indicator_type="road_curve",
      indicator_value=state['curvature']
    )

class AetherGauge:
  def __init__(self):
    self.sources: list[AetherGaugeSource] = [ForceStopSource(), CurveSpeedSource()]

  def get_active_data(self) -> AetherGaugeData | None:
    for source in self.sources:
      if source.is_active():
        return source.get_gauge_data()
    return None

  def _get_model_offset(self, t: float, model) -> float:
    if not model:
      return 0.0
    
    # Map t (0.0 to 1.0) to distance x (0.0 to 50.0 meters)
    x_target = t * 50.0
    
    xs = model.position.x
    ys = model.position.y
    n = len(xs)
    if n < 2:
      return 0.0
      
    if x_target <= xs[0]:
      return ys[0]
    if x_target >= xs[n-1]:
      return ys[n-1]
      
    for i in range(n - 1):
      if xs[i] <= x_target <= xs[i+1]:
        seg_t = (x_target - xs[i]) / (xs[i+1] - xs[i])
        return ys[i] + seg_t * (ys[i+1] - ys[i])
        
    return 0.0

  def render(self, rect: rl.Rectangle, font_bold: rl.Font, font_medium: rl.Font, current_speed: float):
    data = self.get_active_data()
    if not data:
      return

    cx = rect.x + rect.width / 2
    # Vertical center of travel speed text is exactly at rect.y + 180 (matching hud_renderer.py)
    cy_speed = rect.y + 180

    speed_text = str(round(current_speed))
    speed_text_size = measure_text_cached(font_bold, speed_text, 176)

    # Position the curving road widget to the left of the speed text, center-aligned vertically
    icon_cx = cx - speed_text_size.x / 2 - 70.0

    if data.indicator_type in ("road_curve", "force_stop"):
      self._render_unified_road(icon_cx, cy_speed - 39.5, data, font_bold, font_medium)

  def _render_unified_road(self, icx: float, icy: float, data: AetherGaugeData, font_bold: rl.Font, font_medium: rl.Font):
    # Dimensions of the road projection
    half_size = 40.0
    bottom = icy + half_size
    top = icy - half_size
    
    # Model path lookup
    model = ui_state.sm["modelV2"] if ui_state.sm.valid.get("modelV2", False) else None
    
    # 3D perspective widths
    w_bottom = 28.0
    w_top = 10.0
    thickness = 4.0
    
    # Generate points along the road path
    num_segments = 16
    points_left = []
    points_right = []
    
    for i in range(num_segments + 1):
      t = i / num_segments
      if data.indicator_type == "road_curve" and model:
        path_y = self._get_model_offset(t, model)
        abs_y = abs(path_y)
        sign = math.copysign(1.0, path_y) if path_y != 0.0 else 1.0
        # Apply perspective-based shaping factor (t * sqrt(t)) to start straight and bend progressively
        offset = sign * (abs_y ** 0.6) * 10.0 * t * math.sqrt(t)
        offset = max(-half_size, min(half_size, offset))
      else:
        offset = 0.0
      
      cx_t = icx + offset
      y_t = bottom - t * 80.0
      
      # Perspective width interpolation
      w_t = w_bottom - t * (w_bottom - w_top)
      
      points_left.append(rl.Vector2(int(cx_t - w_t), int(y_t)))
      points_right.append(rl.Vector2(int(cx_t + w_t), int(y_t)))

    # A. Draw glowing road surface fill (glowing HUD look)
    fill_color = rl.Color(data.color.r, data.color.g, data.color.b, 35)
    for i in range(num_segments):
      rl.draw_triangle(points_left[i], points_right[i], points_left[i+1], fill_color)
      rl.draw_triangle(points_right[i], points_right[i+1], points_left[i+1], fill_color)

    # B. Draw left and right road boundaries
    shadow_color = rl.Color(0, 0, 0, 100)
    for i in range(num_segments):
      # Shadow lines
      rl.draw_line_ex(rl.Vector2(points_left[i].x, points_left[i].y + 2), rl.Vector2(points_left[i+1].x, points_left[i+1].y + 2), thickness, shadow_color)
      rl.draw_line_ex(rl.Vector2(points_right[i].x, points_right[i].y + 2), rl.Vector2(points_right[i+1].x, points_right[i+1].y + 2), thickness, shadow_color)
      
      # Main boundaries
      rl.draw_line_ex(points_left[i], points_left[i+1], thickness, data.color)
      rl.draw_line_ex(points_right[i], points_right[i+1], thickness, data.color)

    # C. Draw animating chevrons flowing down the road center path
    if data.indicator_type == "force_stop":
      # Slow down chevrons as we approach the stop
      speed_factor = max(0.1, min(1.0, data.indicator_value / 30.0))
    else:
      speed_factor = 1.0

    progress = (rl.get_time() * 1.2 * speed_factor) % 1.0
    for i in range(3):
      # Chevron fraction t (flowing down from 1.0 to 0.0)
      t = 1.0 - ((i + progress) / 3.0)
      
      # Calculate local tangent vector for rotation using model path
      t_next = min(1.0, t + 0.05)
      if data.indicator_type == "road_curve" and model:
        y_t = self._get_model_offset(t, model)
        abs_yt = abs(y_t)
        sign_t = math.copysign(1.0, y_t) if y_t != 0.0 else 1.0
        cx_t = icx + sign_t * (abs_yt ** 0.6) * 10.0 * t * math.sqrt(t)
        
        y_next = self._get_model_offset(t_next, model)
        abs_ynext = abs(y_next)
        sign_next = math.copysign(1.0, y_next) if y_next != 0.0 else 1.0
        cx_next = icx + sign_next * (abs_ynext ** 0.6) * 10.0 * t_next * math.sqrt(t_next)
        
        # Clamp both
        cx_t = max(icx - half_size, min(icx + half_size, cx_t))
        cx_next = max(icx - half_size, min(icx + half_size, cx_next))
      else:
        cx_t = icx
        cx_next = icx
      
      cy_t = bottom - t * 80.0
      cy_next = bottom - t_next * 80.0
      
      dx = cx_next - cx_t
      dy = cy_next - cy_t
      len_v = math.sqrt(dx**2 + dy**2)
      if len_v > 0.001:
        dir_up_x = dx / len_v
        dir_up_y = dy / len_v
      else:
        dir_up_x = 0.0
        dir_up_y = -1.0
        
      dir_right_x = -dir_up_y
      dir_right_y = dir_up_x
      
      # Perspective scaling of chevrons
      chevron_w = 14.0 - t * 6.0
      chevron_h = chevron_w * 0.6
      chevron_thick = max(2.0, 4.0 - t * 2.0)
      
      # Vertices
      lx = cx_t - dir_right_x * chevron_w + dir_up_x * chevron_h
      ly = cy_t - dir_right_y * chevron_w + dir_up_y * chevron_h
      rx = cx_t + dir_right_x * chevron_w + dir_up_x * chevron_h
      ry = cy_t + dir_right_y * chevron_w + dir_up_y * chevron_h
      
      # Alpha envelope fading in at horizon, bright in middle, fading out at bottom
      alpha_factor = math.sin(t * math.pi)
      alpha = int(data.color.a * alpha_factor)
      chev_color = rl.Color(data.color.r, data.color.g, data.color.b, alpha)
      chev_shadow = rl.Color(0, 0, 0, int(alpha * 0.5))
      
      # Draw chevron with shadow
      rl.draw_line_ex(rl.Vector2(int(lx), int(ly + 1.5)), rl.Vector2(int(cx_t), int(cy_t + 1.5)), chevron_thick, chev_shadow)
      rl.draw_line_ex(rl.Vector2(int(rx), int(ry + 1.5)), rl.Vector2(int(cx_t), int(cy_t + 1.5)), chevron_thick, chev_shadow)
      
      rl.draw_line_ex(rl.Vector2(int(lx), int(ly)), rl.Vector2(int(cx_t), int(cy_t)), chevron_thick, chev_color)
      rl.draw_line_ex(rl.Vector2(int(rx), int(ry)), rl.Vector2(int(cx_t), int(cy_t)), chevron_thick, chev_color)

    # E. Draw approaching stop sign if force_stop
    if data.indicator_type == "force_stop":
      self._draw_approaching_stop_sign(icx, icy, bottom, data.indicator_value, data.stop_sign_confirmed)

    # D. Draw clean floating target speed directly below the road base
    self._draw_mini_cradle(icx, bottom, data.text, data.unit, data.color, font_bold, font_medium)

  def _draw_mini_cradle(self, cx: float, bottom: float, target_speed: str, unit: str, color: rl.Color, font_bold: rl.Font, font_medium: rl.Font):
    # Digits (centered at cx, top at bottom + 12)
    val_size = measure_text_cached(font_bold, target_speed, 48)
    val_pos = rl.Vector2(int(cx - val_size.x / 2), int(bottom + 12))
    
    rl.draw_text_ex(font_bold, target_speed, rl.Vector2(val_pos.x - 1, val_pos.y - 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, target_speed, rl.Vector2(val_pos.x + 1, val_pos.y - 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, target_speed, rl.Vector2(val_pos.x - 1, val_pos.y + 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, target_speed, rl.Vector2(val_pos.x + 1, val_pos.y + 1), 48, 0, rl.BLACK)
    rl.draw_text_ex(font_bold, target_speed, val_pos, 48, 0, color)
    
    # Unit (centered at cx, top at bottom + 12 + val_size.y * 0.8)
    unit_size = measure_text_cached(font_medium, unit, 20)
    unit_pos = rl.Vector2(int(cx - unit_size.x / 2), int(bottom + 12 + val_size.y * 0.8))
    
    rl.draw_text_ex(font_medium, unit, rl.Vector2(unit_pos.x - 1, unit_pos.y - 1), 20, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit, rl.Vector2(unit_pos.x + 1, unit_pos.y - 1), 20, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit, rl.Vector2(unit_pos.x - 1, unit_pos.y + 1), 20, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit, rl.Vector2(unit_pos.x + 1, unit_pos.y + 1), 20, 0, rl.BLACK)
    rl.draw_text_ex(font_medium, unit, unit_pos, 20, 0, rl.Color(255, 255, 255, 200))

  def _draw_approaching_stop_sign(self, cx: float, icy: float, bottom: float, distance: float, confirmed: bool):
    # Normalized progress: d_max = 60.0 meters
    d_max = 60.0
    s = max(0.0, min(1.0, (d_max - distance) / d_max))
    
    # 3D perspective translation (stays within the road boundary)
    y_sign = (icy - 30.0) + (s ** 1.5) * 50.0
    
    # Dynamic scale based on distance
    r_min = 6.0
    r_max = 20.0
    r_sign = r_min + (s ** 2.0) * (r_max - r_min)
    
    # Draw drop shadow
    rl.draw_poly(rl.Vector2(int(cx), int(y_sign + 2)), 8, r_sign, 22.5, rl.Color(0, 0, 0, 120))
    
    # Draw outer white border
    rl.draw_poly(rl.Vector2(int(cx), int(y_sign)), 8, r_sign, 22.5, rl.WHITE)
    
    # Draw inner red octagon
    red_color = rl.Color(196, 30, 58, 255)
    rl.draw_poly(rl.Vector2(int(cx), int(y_sign)), 8, r_sign - 3, 22.5, red_color)
    
    # Draw checkmark or exclamation point
    if confirmed:
      # White checkmark
      lx = cx - r_sign * 0.3
      ly = y_sign
      bx = cx - r_sign * 0.07
      by = y_sign + r_sign * 0.22
      rx = cx + r_sign * 0.35
      ry = y_sign - r_sign * 0.22
      
      thick = max(2.0, r_sign * 0.12)
      rl.draw_line_ex(rl.Vector2(int(lx), int(ly)), rl.Vector2(int(bx), int(by)), thick, rl.WHITE)
      rl.draw_line_ex(rl.Vector2(int(bx), int(by)), rl.Vector2(int(rx), int(ry)), thick, rl.WHITE)
    else:
      # White exclamation mark
      thick = max(1.5, r_sign * 0.12)
      bar_h = r_sign * 0.4
      dot_r = max(1.0, r_sign * 0.08)
      
      # Top bar
      rl.draw_rectangle(int(cx - thick / 2), int(y_sign - r_sign * 0.35), int(thick), int(bar_h), rl.WHITE)
      # Dot
      rl.draw_circle(int(cx), int(y_sign + r_sign * 0.35), int(dot_r), rl.WHITE)
