# Project Omega

A small 2D platformer built with C++ and [raylib](https://www.raylib.com/)

This project was created mainly to test the library

## Requirements (Fedora)

```bash
sudo dnf install -y raylib raylib-devel gcc-c++ cmake git make
```

## Project structure

```
project-omega/
├── CMakeLists.txt   # Build configuration
├── src/             # Source files
│   └── main.cpp
├── include/         # Project headers
└── assets/          # Sprites, sounds, fonts, etc.
```

## Build and run

```bash
mkdir build && cd build
cmake ..
make
./bin/ProjectOmega
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

- [ ] Multiple levels (loaded from data, not hardcoded)
- [ ] One-way platforms
- [ ] Moving platforms
- [ ] Hazards / death & respawn
- [ ] Level goal / completion
- [ ] Camera that follows the player, larger-than-screen maps
- [ ] Sprites/animation instead of plain rectangles
- [ ] Sound effects and music
