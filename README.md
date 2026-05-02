*This project has been created as part of the 42 curriculum by gnobile, gifanell.*

# cub3D

A 3D maze renderer built from scratch in C using raycasting, inspired by the classic Wolfenstein 3D engine (Id Software, 1992). The project generates a real-time first-person perspective inside a maze defined by a configuration file, using the MiniLibX graphics library.

---

## Description

cub3D renders a first-person 3D view inside a maze read from a `.cub` scene file. For each vertical column of the screen, a ray is cast from the player's position using the **Digital Differential Analyzer (DDA)** algorithm, stepping through the map grid until it hits a wall. The perpendicular distance to the wall determines its height on screen, creating the illusion of depth. Walls are textured with `.xpm` images that vary depending on which cardinal direction the wall faces (North, South, East, West). Floor and ceiling are drawn with configurable RGB colors.

The player can move through the maze with WASD keys, rotate the camera with arrow keys, and the program handles wall collisions with a sliding mechanic that prevents the player from walking through walls while allowing smooth movement along them.

The project is built entirely with the **MiniLibX** library and standard C, with no external game engines or frameworks. Rendering uses double buffering for flicker-free display at interactive frame rates.

### Features

- Real-time raycasting with DDA algorithm
- Perpendicular distance correction (no fish-eye effect)
- Four distinct wall textures based on cardinal orientation (N/S/E/W)
- Configurable floor and ceiling RGB colors
- Smooth WASD movement with wall collision detection and sliding
- Camera rotation via arrow keys using 2D rotation matrix
- Double-buffered rendering (921,600 pixels per frame)
- Complete `.cub` file parser with flood-fill map validation
- Clean memory management with full resource cleanup on exit
- Error handling with explicit messages for all misconfiguration cases

---

## Instructions

### Requirements

- **cc** compiler
- **Make**
- **MiniLibX** (included or available via 42 repositories)
- **X11** libraries (`libXext`, `libX11`)
- **Math** library (`-lm`)
- Linux environment with X11 display server

### Compilation

```bash
make
```

The Makefile compiles with `-Wall -Wextra -Werror` using `cc`. It does not perform unnecessary relinking: modifying a single source file only recompiles that file's object before relinking.

Available rules: `make all`, `make clean`, `make fclean`, `make re`.

### Execution

```bash
./cub3D path/to/map.cub
```

### Example

```bash
./cub3D test.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Quit |
| Window close button | Quit |

### Scene file format (.cub)

The scene file defines textures, colors, and the map layout:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 107,142,86
C 135,195,235

        1111111111111111
        1000000000000001
        1000010000000001
        100000N000000001
        1000000000000001
        1111111111111111
```

Map characters: `1` = wall, `0` = empty space, `N`/`S`/`E`/`W` = player start position and orientation. The map must be fully enclosed by walls. Spaces are valid parts of the map.

The program returns `Error` followed by an explicit message for any misconfiguration (invalid extension, missing elements, duplicate keys, invalid paths, out-of-range colors, unclosed map, missing or multiple players, invalid characters).

---

## Resources

### References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — primary reference for the raycasting algorithm, DDA implementation, and texture mapping
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — library reference for window management, image creation, and event handling
- [Wolfenstein 3D](http://users.atw.hu/wolf3d/) — the original game that inspired this project

### AI usage

AI tools (Claude by Anthropic) were used during development for the following tasks:

- **Code review and debugging**: identifying mismatches between function signatures and header declarations, spotting typos and logic errors in the initial codebase
- **Documentation**: collaborating with both team members on writing this README
- **Architecture guidance**: discussing project structure, the division of work between team members, and the order of initialization steps

All AI-generated suggestions were reviewed, understood, tested, and validated by both team members before integration.

---

## Project structure

```
cub3D/
├── Makefile
├── README.md
├── test.cub
├── textures/                         # Wall texture files (.xpm)
├── libft/                            # Custom C standard library
├── minilibx-linux/                   # MiniLibX graphics library
└── srcs/
    ├── main.c                        # Entry point, argument validation
    ├── includes/
    │   └── cub3d.h                   # Structs, prototypes, constants
    ├── parsing/                      # .cub file parser
    │   ├── parse_file.c              # File reading and line dispatch
    │   ├── parse_elements.c          # Texture path and RGB color parsing
    │   ├── parse_map.c               # Map grid construction, player setup
    │   ├── parse_textures.c          # Element completeness verification
    │   ├── parse_utils.c             # Utilities (realloc, char validation)
    │   └── validate_map.c            # Flood-fill map closure validation
    ├── engine/                       # Raycasting engine
    │   ├── dda.c                     # Ray init, DDA stepping, wall hit
    │   ├── raycaster.c               # Ray orchestration, texture selection
    │   ├── render.c                  # Frame rendering (ceiling, walls, floor)
    │   └── textures.c               # XPM loading and pixel sampling
    ├── player/                       # Player controls
    │   ├── movement.c                # WASD with collision detection
    │   └── rotation.c                # Arrow key rotation (2D matrix)
    └── utils/                        # Infrastructure
        ├── init.c                    # MLX setup, hooks, keyboard handling
        ├── game_loop.c               # Main loop, close handler
        ├── error.c                   # Error reporting to stderr
        └── cleanup.c                 # Memory and resource cleanup
```

---

## Authors

| Author | Login | Role |
|--------|-------|------|
| **Giusmery Nobile** | gnobile | MLX initialization, player movement and rotation, rendering pipeline, memory management, bug fixes |
| **Giulia Fanelli** | gifanell | File parsing, map validation, DDA algorithm, raycasting, texture system |

Developed at **42 Firenze** as part of the [42 Network](https://42.fr) curriculum.
