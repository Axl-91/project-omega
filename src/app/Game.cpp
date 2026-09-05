#include "Config.hpp"
#include "app/Game.hpp"
#include "app/GameScreen.hpp"
#include "raylib.h"
#include "screens/MainMenuScreen.hpp"

Game::Game() {
    InitWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT,
               "Project Omega");
    SetTargetFPS(Config::FPS);

    virtualScreen = std::make_unique<VirtualScreen>(
        Config::VIRTUAL_WIDTH, Config::VIRTUAL_HEIGHT);
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
                SetWindowSize(Config::WINDOW_WIDTH,
                              Config::WINDOW_HEIGHT);
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
