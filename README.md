# cub3D

A 3D maze renderer built from scratch in C using raycasting, inspired by the classic Wolfenstein 3D engine.  
Project developed as part of the [42 School](https://42.fr) curriculum at **42 Firenze**.

![Language](https://img.shields.io/badge/language-C-blue)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen)
![License](https://img.shields.io/badge/license-42-lightgrey)

---

## Overview

cub3D renders a first-person 3D perspective inside a maze defined by a `.cub` map file. The engine uses the **Digital Differential Analyzer (DDA)** algorithm to cast rays column by column across the screen, calculating wall intersections in real time. Walls are textured with `.xpm` images, and the player can navigate the environment using keyboard controls.

The project is built entirely with the **MiniLibX** graphics library and standard C, with no external game engines or frameworks.

---

## Features

- Real-time raycasting engine with perpendicular distance correction (no fish-eye)
- Textured walls using `.xpm` files, with correct orientation per cardinal direction (N/S/E/W)
- Smooth player movement (WASD) with wall collision detection and sliding
- Camera rotation via arrow keys using 2D rotation matrix
- Double-buffered rendering for flicker-free display
- Map parsing with flood-fill validation to ensure the map is fully enclosed
- RGB ceiling and floor colors
- Clean memory management with full resource cleanup on exit

---

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Quit |

---

## Building

### Requirements

- **GCC** or **CC** compiler
- **Make**
- **MiniLibX** (included or available via 42 repositories)
- **X11** libraries (`libXext`, `libX11`)
- Linux environment (X11-based display server)

### Compile

```bash
make
```

### Run

```bash
./cub3D path/to/map.cub
```

### Example

```bash
./cub3D test.cub
```

---

## Map Format

Maps use the `.cub` extension. A valid map file contains texture paths, floor/ceiling colors, and a grid-based map layout.

### Elements

```
NO ./textures/north.xpm      # North wall texture
SO ./textures/south.xpm      # South wall texture
WE ./textures/west.xpm       # West wall texture
EA ./textures/east.xpm       # East wall texture

F 50,50,50                   # Floor color (R,G,B)
C 30,30,80                   # Ceiling color (R,G,B)
```

### Map Grid

```
        1111111111111111
        1000000000000001
        1000000000000001
        1000010000000001
        100000N000000001
        1000000000000001
        1111111111111111
```

- `1` — Wall
- `0` — Empty space (walkable)
- `N`, `S`, `E`, `W` — Player start position and orientation
- Spaces are allowed and treated as non-walkable areas
- The map must be fully enclosed by walls (validated via flood fill)
- Exactly one player position is required

---

## Architecture

```
cub3D
├── srcs/
│   ├── main.c                    # Entry point, argument validation
│   ├── includes/
│   │   └── cub3d.h               # Structs, prototypes, constants
│   ├── parsing/                  # .cub file parser
│   │   ├── parse_file.c          # File reading and line dispatch
│   │   ├── parse_elements.c      # Texture and color parsing
│   │   ├── parse_map.c           # Map grid construction
│   │   ├── parse_textures.c      # Element completeness check
│   │   ├── parse_utils.c         # Utilities (realloc, char validation)
│   │   └── validate_map.c        # Flood-fill map validation
│   ├── engine/                   # Raycasting engine
│   │   ├── dda.c                 # Ray initialization, DDA stepping, wall hit
│   │   ├── raycaster.c           # Ray orchestration, texture selection
│   │   ├── render.c              # Frame rendering (ceiling, walls, floor)
│   │   └── textures.c            # XPM loading and pixel sampling
│   ├── player/                   # Player controls
│   │   ├── movement.c            # WASD with collision detection
│   │   └── rotation.c            # Arrow key rotation (2D matrix)
│   └── utils/                    # Infrastructure
│       ├── init.c                # MLX setup, hooks, game loop
│       ├── error.c               # Error reporting
│       └── cleanup.c             # Memory and resource cleanup
├── libft/                        # Custom C standard library
├── minilibx-linux/               # MiniLibX graphics library
├── textures/                     # Wall texture files (.xpm)
├── test.cub                      # Example map
└── Makefile
```

---

## How the Raycasting Works

For each vertical column of pixels on screen:

1. **Ray direction** is calculated from the player's direction vector and the camera plane
2. **DDA algorithm** steps through the grid cell by cell until the ray hits a wall (`'1'`)
3. **Perpendicular distance** to the wall is computed (not Euclidean — this prevents the fish-eye effect)
4. **Wall height** on screen is inversely proportional to distance
5. **Texture column** is sampled based on the exact hit point on the wall face
6. **Ceiling and floor** are drawn above and below the wall strip

This process repeats 1280 times per frame (once per screen column), producing a complete 3D perspective at interactive frame rates.

---

## Authors

| Author | Role | GitHub |
|--------|------|--------|
| **Giusmery Nobile** | MLX initialization, player movement/rotation, rendering pipeline, bug fixes | [@ginobile](https://github.com/giusnob) |
| **Giulia Fanelli** | Parsing, map validation, DDA algorithm, raycasting, texture system | [@gifanell](https://github.com/gifanell) |

---

## Acknowledgments

- [42 Firenze](https://42firenze.it) and the 42 Network
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — the foundational reference for the raycasting algorithm
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

---

## License

This project was developed as part of the 42 School curriculum.
