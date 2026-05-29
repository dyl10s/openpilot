from __future__ import annotations
import math
import pyray as rl


def draw_custom_icon(key: str, x: float, y: float, s: float, color: rl.Color):
  # Helper for drawing quadratic Bezier curves
  def draw_bezier(p0: rl.Vector2, p1: rl.Vector2, p2: rl.Vector2, thick: float):
    segments = 20
    for i in range(segments):
      t1 = i / segments
      t2 = (i + 1) / segments
      x1_val = (1 - t1)**2 * p0.x + 2 * (1 - t1) * t1 * p1.x + t1**2 * p2.x
      y1_val = (1 - t1)**2 * p0.y + 2 * (1 - t1) * t1 * p1.y + t1**2 * p2.y
      x2_val = (1 - t2)**2 * p0.x + 2 * (1 - t2) * t2 * p1.x + t2**2 * p2.x
      y2_val = (1 - t2)**2 * p0.y + 2 * (1 - t2) * t2 * p1.y + t2**2 * p2.y
      rl.draw_line_ex(rl.Vector2(x1_val, y1_val), rl.Vector2(x2_val, y2_val), thick, color)

  # Helper for drawing tilted ellipse arcs
  def draw_ellipse_arc(cx: float, cy: float, a: float, b: float, tilt_deg: float, start_deg: float, end_deg: float, thick: float):
    tilt = math.radians(tilt_deg)
    segments = 24
    step = (end_deg - start_deg) / segments
    for i in range(segments):
      p1 = math.radians(start_deg + i * step)
      p2 = math.radians(start_deg + (i + 1) * step)
      
      x1_val = a * math.cos(p1)
      y1_val = b * math.sin(p1)
      rx1 = x1_val * math.cos(tilt) - y1_val * math.sin(tilt)
      ry1 = x1_val * math.sin(tilt) + y1_val * math.cos(tilt)
      
      x2_val = a * math.cos(p2)
      y2_val = b * math.sin(p2)
      rx2 = x2_val * math.cos(tilt) - y2_val * math.sin(tilt)
      ry2 = x2_val * math.sin(tilt) + y2_val * math.cos(tilt)
      
      rl.draw_line_ex(rl.Vector2(cx + rx1, cy + ry1), rl.Vector2(cx + rx2, cy + ry2), thick, color)

  # Helper for drawing 4-pointed stars
  def draw_star(cx: float, cy: float, R: float, r: float):
    v1a = rl.Vector2(cx - r, cy - r)
    v1b = rl.Vector2(cx + r, cy - r)
    v1c = rl.Vector2(cx, cy - R)
    
    v2a = rl.Vector2(cx + r, cy - r)
    v2b = rl.Vector2(cx + r, cy + r)
    v2c = rl.Vector2(cx + R, cy)
    
    v3a = rl.Vector2(cx + r, cy + r)
    v3b = rl.Vector2(cx - r, cy + r)
    v3c = rl.Vector2(cx, cy + R)
    
    v4a = rl.Vector2(cx - r, cy + r)
    v4b = rl.Vector2(cx - r, cy - r)
    v4c = rl.Vector2(cx - R, cy)
    
    rl.draw_triangle(v1a, v1b, v1c, color)
    rl.draw_triangle(v2a, v2b, v2c, color)
    rl.draw_triangle(v3a, v3b, v3c, color)
    rl.draw_triangle(v4a, v4b, v4c, color)
    rl.draw_circle_v(rl.Vector2(cx, cy), r, color)

  if key == "sound":
    # Alerts & Sounds: Bell with side arcs
    x_c = x + 30.0 * s
    y_dome = y + 28.0 * s

    # Side arcs representing sound waves (left and right)
    draw_ellipse_arc(x_c, y_dome, 18.0 * s, 9.0 * s, -15.0, 135.0, 225.0, 2.0 * s)
    draw_ellipse_arc(x_c, y_dome, 26.0 * s, 13.0 * s, -15.0, 135.0, 225.0, 2.0 * s)
    draw_ellipse_arc(x_c, y_dome, 18.0 * s, 9.0 * s, -15.0, -45.0, 45.0, 2.0 * s)
    draw_ellipse_arc(x_c, y_dome, 26.0 * s, 13.0 * s, -15.0, -45.0, 45.0, 2.0 * s)

    # Top loop (handle)
    rl.draw_ring(rl.Vector2(x_c, y_dome - 9.5 * s), 1.5 * s, 3.5 * s, 180.0, 360.0, 16, color)

    # Bell dome
    rl.draw_circle_sector(rl.Vector2(x_c, y_dome), 9.5 * s, 180.0, 360.0, 24, color)

    # Main bell body
    rl.draw_rectangle_rec(rl.Rectangle(x_c - 9.5 * s, y_dome, 19.0 * s, 9.0 * s), color)

    # Flared skirt
    rl.draw_rectangle_rec(rl.Rectangle(x_c - 9.5 * s, y_dome + 9.0 * s, 19.0 * s, 4.0 * s), color)
    rl.draw_triangle(
      rl.Vector2(x_c - 9.5 * s, y_dome + 9.0 * s),
      rl.Vector2(x_c - 13.5 * s, y_dome + 13.0 * s),
      rl.Vector2(x_c - 9.5 * s, y_dome + 13.0 * s),
      color
    )
    rl.draw_triangle(
      rl.Vector2(x_c + 9.5 * s, y_dome + 9.0 * s),
      rl.Vector2(x_c + 9.5 * s, y_dome + 13.0 * s),
      rl.Vector2(x_c + 13.5 * s, y_dome + 13.0 * s),
      color
    )

    # Bottom lip
    rl.draw_rectangle_rounded(rl.Rectangle(x_c - 14.5 * s, y_dome + 13.0 * s, 29.0 * s, 3.0 * s), 1.0, 4, color)

    # Clapper
    rl.draw_circle_v(rl.Vector2(x_c, y_dome + 18.0 * s), 3.5 * s, color)

  elif key == "steering":
    # Driving Controls: Steering wheel with center hub
    x_c = x + 30.0 * s
    y_c = y + 30.0 * s
    center = rl.Vector2(x_c, y_c)

    # Outer rim
    rl.draw_ring(center, 19.5 * s, 22.0 * s, 0.0, 360.0, 48, color)

    # Thumb rests
    rl.draw_circle_v(rl.Vector2(x_c - 17.5 * s, y_c - 8.0 * s), 2.5 * s, color)
    rl.draw_circle_v(rl.Vector2(x_c + 17.5 * s, y_c - 8.0 * s), 2.5 * s, color)

    # Inner ring in hub
    rl.draw_ring(center, 4.5 * s, 5.5 * s, 0.0, 360.0, 24, color)

    # Center star
    draw_star(x_c, y_c, 4.5 * s, 1.5 * s)

    # Three spokes
    rl.draw_line_ex(rl.Vector2(x_c - 5.5 * s, y_c + 1.0 * s), rl.Vector2(x_c - 19.5 * s, y_c + 4.0 * s), 2.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_c + 5.5 * s, y_c + 1.0 * s), rl.Vector2(x_c + 19.5 * s, y_c + 4.0 * s), 2.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_c, y_c + 5.5 * s), rl.Vector2(x_c, y_c + 19.5 * s), 2.5 * s, color)

  elif key == "navigate":
    # Map Data: Path with starting indicator and destination crosshair
    x_s = x + 12.0 * s
    y_s = y + 48.0 * s
    x_d = x + 48.0 * s
    y_d = y + 14.0 * s

    # Start node
    rl.draw_circle_v(rl.Vector2(x_s, y_s), 3.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x_s, y_s - 3.0 * s), rl.Vector2(x_s, y_s - 6.0 * s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_s, y_s + 3.0 * s), rl.Vector2(x_s, y_s + 6.0 * s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_s - 3.0 * s, y_s), rl.Vector2(x_s - 6.0 * s, y_s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_s + 3.0 * s, y_s), rl.Vector2(x_s + 6.0 * s, y_s), 1.5 * s, color)

    # Sweeping curved path
    p0 = rl.Vector2(x_s, y_s)
    p1 = rl.Vector2(x + 40.0 * s, y + 42.0 * s)
    p2 = rl.Vector2(x_d, y_d)
    draw_bezier(p0, p1, p2, 3.0 * s)

    # Destination crosshair
    rl.draw_ring(rl.Vector2(x_d, y_d), 5.5 * s, 6.5 * s, 0.0, 360.0, 24, color)
    rl.draw_line_ex(rl.Vector2(x_d, y_d - 9.0 * s), rl.Vector2(x_d, y_d - 5.5 * s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_d, y_d + 5.5 * s), rl.Vector2(x_d, y_d + 9.0 * s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_d - 9.0 * s, y_d), rl.Vector2(x_d - 5.5 * s, y_d), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x_d + 5.5 * s, y_d), rl.Vector2(x_d + 9.0 * s, y_d), 1.5 * s, color)

    # Center star
    draw_star(x_d, y_d, 4.0 * s, 1.25 * s)

  elif key == "system":
    # System Settings: Interlocking gears
    cx1, cy1 = x + 23.0 * s, y + 23.0 * s
    cx2, cy2 = x + 41.0 * s, y + 41.0 * s

    # Gear 1 (Large)
    # Ring body
    rl.draw_ring(rl.Vector2(cx1, cy1), 6.0 * s, 12.0 * s, 0.0, 360.0, 36, color)
    # Center star (spokes/core)
    draw_star(cx1, cy1, 6.0 * s, 2.0 * s)
    # Teeth (8 cogs, blocky teeth meshing cleanly)
    for i in range(8):
      angle_rad = math.radians(i * 45.0)
      cos_a = math.cos(angle_rad)
      sin_a = math.sin(angle_rad)
      rl.draw_line_ex(
        rl.Vector2(cx1 + cos_a * 11.5 * s, cy1 + sin_a * 11.5 * s),
        rl.Vector2(cx1 + cos_a * 15.5 * s, cy1 + sin_a * 15.5 * s),
        5.0 * s,
        color
      )

    # Gear 2 (Small)
    # Ring body
    rl.draw_ring(rl.Vector2(cx2, cy2), 4.5 * s, 9.0 * s, 0.0, 360.0, 24, color)
    # Center star (spokes/core)
    draw_star(cx2, cy2, 4.5 * s, 1.5 * s)
    # Teeth (6 cogs, offset by 15 degrees to mesh perfectly)
    for j in range(6):
      angle_rad = math.radians(15.0 + j * 60.0)
      cos_a = math.cos(angle_rad)
      sin_a = math.sin(angle_rad)
      rl.draw_line_ex(
        rl.Vector2(cx2 + cos_a * 8.5 * s, cy2 + sin_a * 8.5 * s),
        rl.Vector2(cx2 + cos_a * 12.0 * s, cy2 + sin_a * 12.0 * s),
        4.0 * s,
        color
      )

  elif key == "display":
    # Outer screen bezel - Chamfered modern rectangular shape
    p1 = rl.Vector2(x + 9.0 * s, y + 11.0 * s)
    p2 = rl.Vector2(x + 51.0 * s, y + 11.0 * s)
    p3 = rl.Vector2(x + 54.0 * s, y + 14.0 * s)
    p4 = rl.Vector2(x + 54.0 * s, y + 36.0 * s)
    p5 = rl.Vector2(x + 51.0 * s, y + 39.0 * s)
    p6 = rl.Vector2(x + 9.0 * s, y + 39.0 * s)
    p7 = rl.Vector2(x + 6.0 * s, y + 36.0 * s)
    p8 = rl.Vector2(x + 6.0 * s, y + 14.0 * s)

    rl.draw_line_ex(p1, p2, 2.0 * s, color)
    rl.draw_line_ex(p2, p3, 2.0 * s, color)
    rl.draw_line_ex(p3, p4, 2.0 * s, color)
    rl.draw_line_ex(p4, p5, 2.0 * s, color)
    rl.draw_line_ex(p5, p6, 2.0 * s, color)
    rl.draw_line_ex(p6, p7, 2.0 * s, color)
    rl.draw_line_ex(p7, p8, 2.0 * s, color)
    rl.draw_line_ex(p8, p1, 2.0 * s, color)

    # Inner bezel - Offset chamfered line to establish depth
    ip1 = rl.Vector2(x + 10.5 * s, y + 13.0 * s)
    ip2 = rl.Vector2(x + 49.5 * s, y + 13.0 * s)
    ip3 = rl.Vector2(x + 52.0 * s, y + 15.5 * s)
    ip4 = rl.Vector2(x + 52.0 * s, y + 34.5 * s)
    ip5 = rl.Vector2(x + 49.5 * s, y + 37.0 * s)
    ip6 = rl.Vector2(x + 10.5 * s, y + 37.0 * s)
    ip7 = rl.Vector2(x + 8.0 * s, y + 34.5 * s)
    ip8 = rl.Vector2(x + 8.0 * s, y + 15.5 * s)

    rl.draw_line_ex(ip1, ip2, 1.0 * s, color)
    rl.draw_line_ex(ip2, ip3, 1.0 * s, color)
    rl.draw_line_ex(ip3, ip4, 1.0 * s, color)
    rl.draw_line_ex(ip4, ip5, 1.0 * s, color)
    rl.draw_line_ex(ip5, ip6, 1.0 * s, color)
    rl.draw_line_ex(ip6, ip7, 1.0 * s, color)
    rl.draw_line_ex(ip7, ip8, 1.0 * s, color)
    rl.draw_line_ex(ip8, ip1, 1.0 * s, color)

    # Dash Bracket Mount (Porsche engineered stability)
    rl.draw_line_ex(rl.Vector2(x + 12.0 * s, y + 53.0 * s), rl.Vector2(x + 48.0 * s, y + 53.0 * s), 2.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 22.0 * s, y + 39.0 * s), rl.Vector2(x + 18.0 * s, y + 53.0 * s), 2.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 38.0 * s, y + 39.0 * s), rl.Vector2(x + 42.0 * s, y + 53.0 * s), 2.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 20.0 * s, y + 46.0 * s), rl.Vector2(x + 40.0 * s, y + 46.0 * s), 1.5 * s, color)
    rl.draw_circle_v(rl.Vector2(x + 30.0 * s, y + 49.0 * s), 2.5 * s, color)

    # Flight Path Vector (FPV)
    rl.draw_ring(rl.Vector2(x + 30.0 * s, y + 25.0 * s), 0.75 * s, 1.75 * s, 0.0, 360.0, 16, color)
    rl.draw_line_ex(rl.Vector2(x + 25.0 * s, y + 25.0 * s), rl.Vector2(x + 28.0 * s, y + 25.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 32.0 * s, y + 25.0 * s), rl.Vector2(x + 35.0 * s, y + 25.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 30.0 * s, y + 21.0 * s), rl.Vector2(x + 30.0 * s, y + 23.0 * s), 1.0 * s, color)

    # Attitude Horizon Lines
    rl.draw_line_ex(rl.Vector2(x + 14.0 * s, y + 25.0 * s), rl.Vector2(x + 22.0 * s, y + 25.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 38.0 * s, y + 25.0 * s), rl.Vector2(x + 46.0 * s, y + 25.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 14.0 * s, y + 25.0 * s), rl.Vector2(x + 14.0 * s, y + 22.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 22.0 * s, y + 25.0 * s), rl.Vector2(x + 22.0 * s, y + 28.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 38.0 * s, y + 25.0 * s), rl.Vector2(x + 38.0 * s, y + 28.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 46.0 * s, y + 25.0 * s), rl.Vector2(x + 46.0 * s, y + 22.0 * s), 1.0 * s, color)

    # Pitch Ladder (above/below horizon)
    rl.draw_line_ex(rl.Vector2(x + 25.0 * s, y + 19.0 * s), rl.Vector2(x + 27.5 * s, y + 19.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 32.5 * s, y + 19.0 * s), rl.Vector2(x + 35.0 * s, y + 19.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 25.0 * s, y + 19.0 * s), rl.Vector2(x + 25.0 * s, y + 20.5 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 35.0 * s, y + 19.0 * s), rl.Vector2(x + 35.0 * s, y + 20.5 * s), 1.0 * s, color)

    rl.draw_line_ex(rl.Vector2(x + 25.0 * s, y + 31.0 * s), rl.Vector2(x + 27.5 * s, y + 31.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 32.5 * s, y + 31.0 * s), rl.Vector2(x + 35.0 * s, y + 31.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 25.0 * s, y + 31.0 * s), rl.Vector2(x + 25.0 * s, y + 29.5 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 35.0 * s, y + 31.0 * s), rl.Vector2(x + 35.0 * s, y + 29.5 * s), 1.0 * s, color)

    # Telemetry HUD Tapes (Speed and Altitude)
    rl.draw_line_ex(rl.Vector2(x + 11.0 * s, y + 16.0 * s), rl.Vector2(x + 11.0 * s, y + 34.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 11.0 * s, y + 18.0 * s), rl.Vector2(x + 13.0 * s, y + 18.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 11.0 * s, y + 22.0 * s), rl.Vector2(x + 14.5 * s, y + 22.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 11.0 * s, y + 26.0 * s), rl.Vector2(x + 13.0 * s, y + 26.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 11.0 * s, y + 30.0 * s), rl.Vector2(x + 14.5 * s, y + 30.0 * s), 1.0 * s, color)

    rl.draw_line_ex(rl.Vector2(x + 49.0 * s, y + 16.0 * s), rl.Vector2(x + 49.0 * s, y + 34.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 47.0 * s, y + 18.0 * s), rl.Vector2(x + 49.0 * s, y + 18.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 45.5 * s, y + 22.0 * s), rl.Vector2(x + 49.0 * s, y + 22.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 47.0 * s, y + 26.0 * s), rl.Vector2(x + 49.0 * s, y + 26.0 * s), 1.0 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 45.5 * s, y + 30.0 * s), rl.Vector2(x + 49.0 * s, y + 30.0 * s), 1.0 * s, color)

    # Curved Horizon / Orbital sweep (Mercedes curves)
    p0_curve = rl.Vector2(x + 15.0 * s, y + 34.0 * s)
    p1_curve = rl.Vector2(x + 30.0 * s, y + 29.0 * s)
    p2_curve = rl.Vector2(x + 45.0 * s, y + 34.0 * s)
    draw_bezier(p0_curve, p1_curve, p2_curve, 1.0 * s)

    # Celestial Galaxy-themed accents (Space Vista)
    draw_star(x + 15.0 * s, y + 17.0 * s, 1.5 * s, 0.5 * s)
    rl.draw_ring(rl.Vector2(x + 44.0 * s, y + 17.0 * s), 1.5 * s, 2.5 * s, 220.0, 320.0, 12, color)
    draw_star(x + 42.0 * s, y + 15.0 * s, 1.25 * s, 0.4 * s)

  elif key == "vehicle":
    # Vehicle Settings: Aerodynamic car silhouette floating over curved base
    # Curved base line
    rl.draw_ring(rl.Vector2(x + 30.0 * s, y + 110.0 * s), 64.0 * s, 66.5 * s, 245.0, 295.0, 36, color)

    # Vehicle silhouette
    v_front = rl.Vector2(x + 10.0 * s, y + 31.0 * s)
    v_hood_end = rl.Vector2(x + 20.0 * s, y + 25.0 * s)
    v_cabin_end = rl.Vector2(x + 38.0 * s, y + 19.0 * s)
    v_rear = rl.Vector2(x + 50.0 * s, y + 31.0 * s)

    # Front bumper and hood
    rl.draw_line_ex(rl.Vector2(x + 10.0 * s, y + 31.0 * s), rl.Vector2(x + 10.0 * s, y + 34.0 * s), 2.0 * s, color)
    draw_bezier(v_front, rl.Vector2(x + 13.0 * s, y + 28.0 * s), v_hood_end, 2.0 * s)

    # Cabin roofline
    draw_bezier(v_hood_end, rl.Vector2(x + 27.0 * s, y + 19.0 * s), v_cabin_end, 2.0 * s)

    # Rear glass and tail
    draw_bezier(v_cabin_end, rl.Vector2(x + 46.0 * s, y + 21.0 * s), v_rear, 2.0 * s)
    rl.draw_line_ex(v_rear, rl.Vector2(x + 50.0 * s, y + 34.0 * s), 2.0 * s, color)

    # Underbody and wheel arches
    rl.draw_line_ex(rl.Vector2(x + 10.0 * s, y + 34.0 * s), rl.Vector2(x + 14.5 * s, y + 34.0 * s), 2.0 * s, color)
    rl.draw_ring(rl.Vector2(x + 19.0 * s, y + 34.0 * s), 4.5 * s, 5.5 * s, 180.0, 360.0, 12, color)
    rl.draw_line_ex(rl.Vector2(x + 23.5 * s, y + 34.0 * s), rl.Vector2(x + 37.5 * s, y + 34.0 * s), 2.0 * s, color)
    rl.draw_ring(rl.Vector2(x + 42.0 * s, y + 34.0 * s), 4.5 * s, 5.5 * s, 180.0, 360.0, 12, color)
    rl.draw_line_ex(rl.Vector2(x + 46.5 * s, y + 34.0 * s), rl.Vector2(x + 50.0 * s, y + 34.0 * s), 2.0 * s, color)

    # Wheels
    rl.draw_ring(rl.Vector2(x + 19.0 * s, y + 34.0 * s), 2.5 * s, 4.0 * s, 0.0, 360.0, 16, color)
    rl.draw_ring(rl.Vector2(x + 42.0 * s, y + 34.0 * s), 2.5 * s, 4.0 * s, 0.0, 360.0, 16, color)

    # Cabin window
    rl.draw_line_ex(rl.Vector2(x + 22.0 * s, y + 25.0 * s), rl.Vector2(x + 37.0 * s, y + 21.0 * s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 37.0 * s, y + 21.0 * s), rl.Vector2(x + 38.0 * s, y + 25.0 * s), 1.5 * s, color)
    rl.draw_line_ex(rl.Vector2(x + 38.0 * s, y + 25.0 * s), rl.Vector2(x + 22.0 * s, y + 25.0 * s), 1.5 * s, color)

    # Background star accent
    draw_star(x + 14.0 * s, y + 12.0 * s, 3.0 * s, 1.0 * s)
