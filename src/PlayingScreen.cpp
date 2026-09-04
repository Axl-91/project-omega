#include "Config.hpp"
#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "PauseScreen.hpp"
#include "PlayingScreen.hpp"
#include "raylib.h"
#include <cmath>

static void DrawControlsHint() {
    float pulse = (sinf(GetTime() * 4.0f) + 1.0f) / 2.0f;
    float alpha = 0.5f + pulse * 0.5f;
    DrawText("Use WASD to move, SPACE to jump, P to pause",
             30, 30, 24, Fade(DARKPURPLE, alpha));
}

PlayingScreen::PlayingScreen()
    : player({Config::SCREEN_WIDTH / 2.0f,
              Config::SCREEN_HEIGHT / 2.0f},
             Config::PLAYER_SIZE, Config::PLAYER_SPEED,
             MAROON) {}

ScreenResult PlayingScreen::Update(float deltaTime) {
    player.Update(deltaTime, level);

    if (IsKeyPressed(KEY_P)) {
        ScreenResult result;
        auto movedSelf = std::make_unique<PlayingScreen>(
            std::move(*this));
        result.nextScreen = std::make_unique<PauseScreen>(
            std::move(movedSelf));
        return result;
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
        ScreenResult result;
        result.nextScreen =
            std::make_unique<MainMenuScreen>();
        return result;
    }

    return {};
}

void PlayingScreen::Draw() const {
    level.Draw();
    player.Draw();
    DrawControlsHint();
}
