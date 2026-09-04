#include "Config.hpp"
#include "Game.hpp"
#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "raylib.h"

Game::Game() {
    InitWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT,
               "Project Omega");
    SetTargetFPS(Config::FPS);

    virtualScreen = std::make_unique<VirtualScreen>(
        Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    currentScreen = std::make_unique<MainMenuScreen>();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F11)) {
            if (!IsWindowFullscreen()) {
                int monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor),
                              GetMonitorHeight(monitor));
            } else {
                SetWindowSize(Config::SCREEN_WIDTH,
                              Config::SCREEN_HEIGHT);
            }
            ToggleFullscreen();
        }

        ScreenResult result =
            currentScreen->Update(GetFrameTime());

        if (result.quit) {
            break;
        }
        if (result.nextScreen) {
            currentScreen = std::move(result.nextScreen);
        }

        virtualScreen->BeginDrawing();

        ClearBackground(RAYWHITE);
        currentScreen->Draw();

        virtualScreen->EndDrawing();
    }

    virtualScreen.reset();
    CloseWindow();
}
