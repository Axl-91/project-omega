#include "Game.hpp"
#include "raylib.h"
#include <cmath>

Game::Game()
    : player(
          {screenWidth / 2.0f - 30.0f, screenHeight / 4.0f},
          25.0f, 200.0f, MAROON) {
    InitWindow(screenWidth, screenHeight, "Project Omega");
    SetTargetFPS(60);
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }

    CloseWindow();
}

void Game::Update() {
    player.Update(GetFrameTime(), level);
}

static void DrawControlsHint() {
    float pulse = (sinf(GetTime() * 4.0f) + 1.0f) / 2.0f;
    float alpha = 0.5f + pulse * 0.5f;

    Color textColor = Fade(DARKPURPLE, alpha);
    DrawText("Use WASD to move", 30, 30, 24, textColor);
}

void Game::Draw() {

    BeginDrawing();

    ClearBackground(RAYWHITE);
    level.Draw();
    player.Draw();

    DrawControlsHint();

    EndDrawing();
}
