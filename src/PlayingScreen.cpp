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

    const char *hintsStr =
        "Use WASD to move, SPACE to jump, P to pause";
    int hintsSize = 24;
    int titleWidth = MeasureText(hintsStr, hintsSize);

    int posX = (Config::VIRTUAL_WIDTH - titleWidth) / 2,
        posY = 30;

    DrawText(hintsStr, posX, posY, hintsSize,
             Fade(DARKPURPLE, alpha));
}

PlayingScreen::PlayingScreen()
    : player({Config::VIRTUAL_WIDTH / 2.0f,
              Config::VIRTUAL_HEIGHT / 2.0f},
             Config::PLAYER_SIZE, Config::PLAYER_SPEED,
             MAROON) {}

ScreenResult PlayingScreen::Update(float deltaTime) {
    player.Update(deltaTime, roomManager.GetCurrentLevel());
    roomManager.CheckRoomTransition(player);

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
    roomManager.GetCurrentLevel().Draw();
    player.Draw();
    DrawControlsHint();
}
