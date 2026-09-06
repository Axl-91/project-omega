#pragma once

namespace Config {
    // Virtual Screen representation
    // for the logic of the game
    constexpr int VIRTUAL_WIDTH = 320;
    constexpr int VIRTUAL_HEIGHT = 240;

    // Size for the window screen
    // that will be displayed
    constexpr int WINDOW_WIDTH = 1024;
    constexpr int WINDOW_HEIGHT = 768;

    constexpr int FPS = 60;

    static const int TILE_SIZE = 16;

    constexpr float PLAYER_SPEED = 150.0f;
    constexpr float PLAYER_WIDTH = 14.0f;
    constexpr float PLAYER_HEIGHT = 18.0f;
} // namespace Config
