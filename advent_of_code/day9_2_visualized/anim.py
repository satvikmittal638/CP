import sys
import pygame
import os
import shutil

# Check for imageio for GIF generation
try:
    import imageio
    HAS_IMAGEIO = True
except ImportError:
    HAS_IMAGEIO = False
    print("Warning: 'imageio' not found. GIFs will not be generated automatically.")
    print("Run: pip install imageio")

# --- CONFIGURATION ---
BG_COLOR = (20, 20, 30)       # Dark Navy
WALL_COLOR = (46, 204, 113)   # Bright Green
CHECK_COLOR = (52, 152, 219)  # Blue
BEST_COLOR = (241, 196, 15)   # Gold
TEXT_COLOR = (255, 255, 255)  # White
REC_COLOR = (231, 76, 60)     # Red (Recording Indicator)

# Transparency (0-255)
CHECK_ALPHA = 80 

def parse_input():
    """Reads stdin to find map bounds before starting graphics"""
    rects = []
    while True:
        line = sys.stdin.readline()
        if not line: return None, None
        if line.startswith("SIZE"): break

    print("Reading Map Geometry...", file=sys.stderr)
    while True:
        line = sys.stdin.readline()
        if not line: break
        if line.strip() == "MAP_END": break
        if line.startswith("MAP_START"): continue
        if line.startswith('R'):
            parts = list(map(int, line.split()[1:]))
            rects.append(parts)
            
    if not rects: return None, None
    return rects, line

def generate_gif(frame_folder, output_file="recap.gif"):
    """Stitches frames into a GIF using imageio"""
    if not HAS_IMAGEIO: return
    
    print(f"Generating {output_file}... (This may take a moment)")
    images = []
    # Sort files numerically
    filenames = sorted(os.listdir(frame_folder), key=lambda x: int(x.split('_')[1].split('.')[0]))
    
    # Read images
    for filename in filenames:
        if filename.endswith(".png"):
            file_path = os.path.join(frame_folder, filename)
            images.append(imageio.imread(file_path))
            
    if images:
        # Save GIF (duration=0.03 is approx 30 FPS)
        imageio.mimsave(output_file, images, duration=0.03, loop=0)
        print(f"Success! Saved to {output_file}")
    else:
        print("No frames found.")

def main():
    pygame.init()
    pygame.font.init()
    font = pygame.font.SysFont("Consolas", 24, bold=True)
    small_font = pygame.font.SysFont("Consolas", 16)
    
    # Auto-Size Window
    info = pygame.display.Info()
    SCREEN_W = int(info.current_w * 0.8)
    SCREEN_H = int(info.current_h * 0.9)
    
    # 1. PARSE MAP
    wall_rects, last_line = parse_input()
    if not wall_rects: return

    # Calculate Zoom/Scale
    min_r = min(r for r, c, h, w in wall_rects)
    min_c = min(c for r, c, h, w in wall_rects)
    max_r = max(r + h for r, c, h, w in wall_rects)
    max_c = max(c + w for r, c, h, w in wall_rects)
    
    poly_h = max_r - min_r
    poly_w = max_c - min_c
    scale = min(SCREEN_W / poly_w, SCREEN_H / poly_h) * 0.9
    
    draw_w = poly_w * scale
    draw_h = poly_h * scale
    offset_x = (SCREEN_W - draw_w) / 2 - (min_c * scale)
    offset_y = (SCREEN_H - draw_h) / 2 - (min_r * scale)

    screen = pygame.display.set_mode((SCREEN_W, SCREEN_H))
    pygame.display.set_caption("AoC Day 9 - Rectangle Scanner")

    # 2. PRE-RENDER STATIC MAP
    background = pygame.Surface((SCREEN_W, SCREEN_H))
    background.fill(BG_COLOR)
    for r, c, h, w in wall_rects:
        rect = (offset_x + c*scale, offset_y + r*scale, max(1, w*scale), max(1, h*scale))
        pygame.draw.rect(background, WALL_COLOR, rect)

    # 3. ANIMATION LOOP
    clock = pygame.time.Clock()
    running = True
    paused = False
    recording = False
    
    # Setup Recording Folder
    frame_dir = "frames_temp"
    if os.path.exists(frame_dir):
        shutil.rmtree(frame_dir)
    os.makedirs(frame_dir)
    frame_idx = 0
    
    batch_size = 1 
    check_surf = pygame.Surface((SCREEN_W, SCREEN_H), pygame.SRCALPHA)
    best_rect_coords = None
    best_area = 0
    
    while running:
        # Input Handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT: running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP: batch_size = min(1000, batch_size * 2)
                elif event.key == pygame.K_DOWN: batch_size = max(1, batch_size // 2)
                elif event.key == pygame.K_SPACE: paused = not paused
                elif event.key == pygame.K_r: recording = not recording

        if not paused:
            check_surf.fill((0,0,0,0)) 
            
            # PROCESS BATCH
            for _ in range(batch_size):
                line = sys.stdin.readline()
                if not line: 
                    paused = True
                    break
                
                parts = line.split()
                if len(parts) > 0 and parts[0] in ['C', 'F']:
                    cmd = parts[0]
                    r1, c1, r2, c2 = map(int, parts[1:])
                    
                    x = offset_x + c1 * scale
                    y = offset_y + r1 * scale
                    w = (c2 - c1 + 1) * scale
                    h = (r2 - r1 + 1) * scale
                    
                    if cmd == 'C':
                        if batch_size < 50: 
                             pygame.draw.rect(check_surf, (*CHECK_COLOR, CHECK_ALPHA), (x, y, w, h))
                        else:
                             pygame.draw.rect(check_surf, CHECK_COLOR, (x, y, w, h), 1)

                    elif cmd == 'F':
                        best_rect_coords = (x, y, w, h)
                        best_area = (r2 - r1 + 1) * (c2 - c1 + 1)
                        pygame.draw.rect(check_surf, (255, 255, 255, 200), (x, y, w, h))
                        break 

        # DRAWING
        screen.blit(background, (0, 0))
        screen.blit(check_surf, (0, 0))
        
        if best_rect_coords:
            pygame.draw.rect(screen, (*BEST_COLOR, 50), best_rect_coords, 4)

        # UI OVERLAY
        ui_bg = pygame.Surface((320, 110))
        ui_bg.set_alpha(200)
        ui_bg.fill((0,0,0))
        screen.blit(ui_bg, (10, 10))
        
        area_text = font.render(f"Max Area: {best_area}", True, BEST_COLOR)
        speed_text = small_font.render(f"Speed: {batch_size}x checks/frame", True, TEXT_COLOR)
        ctrl_text = small_font.render("UP/DOWN: Speed | SPACE: Pause", True, (150, 150, 150))
        rec_text = small_font.render(f"REC: {'ON' if recording else 'OFF'} (Press R)", True, REC_COLOR if recording else (100,100,100))
        
        screen.blit(area_text, (20, 20))
        screen.blit(speed_text, (20, 50))
        screen.blit(ctrl_text, (20, 70))
        screen.blit(rec_text, (20, 90))

        if recording:
            pygame.draw.circle(screen, REC_COLOR, (310, 30), 10)

        pygame.display.flip()
        
        # Save Frame for GIF
        if recording and not paused:
            frame_name = os.path.join(frame_dir, f"frame_{frame_idx:05d}.png")
            pygame.image.save(screen, frame_name)
            frame_idx += 1
        
        clock.tick(60)

    pygame.quit()
    
    # Generate GIF on exit if any frames were recorded
    if frame_idx > 0:
        generate_gif(frame_dir, "recap.gif")
        # Optional: Cleanup frames folder
        # shutil.rmtree(frame_dir) 
        print(f"Temporary frames kept in '{frame_dir}'")

if __name__ == "__main__":
    main()