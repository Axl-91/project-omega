#include "Game.hpp"
#include "raylib.h"

Game::Game()
    : player({screenWidth / 2.0f, screenHeight / 2.0f}, 40.0f, 200.0f, MAROON) {
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

void Game::Update() { player.Update(GetFrameTime()); }

void Game::Draw() {
  BeginDrawing();

  ClearBackground(RAYWHITE);
  player.Draw();
  DrawText("Use WASD to move", 10, 10, 24, DARKGRAY);

  EndDrawing();
}
