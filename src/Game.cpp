#include "Config.hpp"
#include "Game.hpp"
#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "raylib.h"

Game::Game() {
    InitWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT,
               "Project Omega");
    SetTargetFPS(Config::FPS);

    currentScreen = std::make_unique<MainMenuScreen>();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        ScreenResult result =
            currentScreen->Update(GetFrameTime());

        if (result.quit) {
            break;
        }
        if (result.nextScreen) {
            currentScreen = std::move(result.nextScreen);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        currentScreen->Draw();
        EndDrawing();
    }

    CloseWindow();
}
