#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Omega");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    const char *welcomeText = "Welcome to Raylib";
    int fontSize = 40;
    int textWidth = MeasureText(welcomeText, 40);

    int textX = (SCREEN_WIDTH - textWidth) / 2;
    int textY = SCREEN_HEIGHT / 2 - fontSize / 2;

    DrawText(welcomeText, textX, textY, fontSize, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
