# Project Omega

A small 2D platformer built with C++ and [raylib](https://www.raylib.com/)

This project was created mainly to test the library

## Requirements (Fedora)

```bash
sudo dnf install -y raylib raylib-devel gcc-c++ cmake git make
```

## Project structure

```text
project-omega/
├── CMakeLists.txt       # Build configuration
├── src/                 # Source files
│   ├── main.cpp         
│   ├── app/             # Core game infrastructure
│   ├── entities/        # Game entities
│   ├── screens/         # Game screens
│   └── world/           # Game world
├── include/             # Project headers
│   ├── Config.hpp       # Global configuration
│   ├── Physics.hpp      # Physics and collision logic
│   ├── app/
│   ├── entities/
│   ├── screens/
│   └── world/
├── assets/              # Sprites, sounds, fonts, etc.
└── README.md
```


## Build and run

```bash
make configure  # Configure CMake
make build      # Build the project
make run        # Build if necessary and run the game
make clean      # Remove build files
```

## Controls

| Key | Action |
|---|---|
| `A` / `D` | Move left / right |
| `SPACE` | Jump (hold longer for a higher jump) |
| `P` | Pause / unpause |
| `ESC` | Back to main menu |
| `F11` | Toggle fullscreen |
| `ENTER` / `↑` `↓` | Navigate and confirm menu options |

## Roadmap

### Done
 
- [x] Movement (A/D) and gravity
- [x] Jump with variable height
- [x] Tile-based collision
- [x] Room-to-room transitions 
- [x] Screen/state system: main menu, playing
- [x] Pause on game, state preserved on pause
- [x] Virtual resolution with automatic scaling + fullscreen toggle
- [x] Centralized config/physics constants

### Pending
 
- [ ] Death & respawn (the core loop of the genre)
- [x] Levels loaded from data
- [ ] Room grid in 2D
- [ ] One-way platforms
- [ ] Moving platforms
- [ ] Level goal / completion, level select
- [ ] Sprites/animation instead of plain rectangles
- [ ] Sound effects and music
 
