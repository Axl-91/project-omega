#include "Config.hpp"
#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "PlayingScreen.hpp"
#include "raylib.h"

static const char *OPTIONS[] = {"Start Game", "Exit"};
static const int OPTION_COUNT = 2;

ScreenResult MainMenuScreen::Update(float deltaTime) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        selectedOption =
            (selectedOption + 1) % OPTION_COUNT;
    }
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
        selectedOption =
            (selectedOption - 1 + OPTION_COUNT) %
            OPTION_COUNT;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        ScreenResult result;
        if (selectedOption == 0) {
            result.nextScreen =
                std::make_unique<PlayingScreen>();
        } else {
            result.quit = true;
        }
        return result;
    }

    return {};
}

void MainMenuScreen::Draw() const {
    const char *title = "PROJECT OMEGA";
    int titleSize = 40;
    int titleWidth = MeasureText(title, titleSize);
    DrawText(title,
             (Config::VIRTUAL_WIDTH - titleWidth) / 2,
             Config::VIRTUAL_HEIGHT / 2 - 100, titleSize,
             DARKGRAY);

    int optionSize = 24;
    int spacing = 40;
    int startY = Config::VIRTUAL_HEIGHT / 2;

    for (int i = 0; i < OPTION_COUNT; i++) {
        bool selected = (i == selectedOption);

        const char *label =
            selected ? TextFormat("> %s", OPTIONS[i])
                     : OPTIONS[i];
        Color color = selected ? VIOLET : GRAY;

        int labelWidth = MeasureText(label, optionSize);
        DrawText(label,
                 (Config::VIRTUAL_WIDTH - labelWidth) / 2,
                 startY + i * spacing, optionSize, color);
    }
}
