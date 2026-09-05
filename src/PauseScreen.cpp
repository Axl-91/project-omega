#include "Config.hpp"
#include "GameScreen.hpp"
#include "PauseScreen.hpp"
#include "raylib.h"

PauseScreen::PauseScreen(PlayScreenPtr playingScreen)
    : playingScreen(std::move(playingScreen)) {}

ScreenResult PauseScreen::Update(float deltaTime) {
    if (IsKeyPressed(KEY_P)) {
        ScreenResult result;
        result.nextScreen = std::move(playingScreen);
        return result;
    }
    return {};
}

void PauseScreen::Draw() const {
    playingScreen->Draw();

    DrawRectangle(0, 0, Config::VIRTUAL_WIDTH,
                  Config::VIRTUAL_HEIGHT,
                  Fade(BLACK, 0.5f));

    const char *text = "PAUSED";
    int size = 40;
    int width = MeasureText(text, size);
    DrawText(text, (Config::VIRTUAL_WIDTH - width) / 2,
             Config::VIRTUAL_HEIGHT / 2 - size / 2, size,
             RAYWHITE);
}
