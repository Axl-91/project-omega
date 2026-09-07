#include "Config.hpp"
#include "app/GameScreen.hpp"
#include "raylib.h"
#include "screens/MainMenuScreen.hpp"
#include "screens/PauseScreen.hpp"
#include "screens/PlayingScreen.hpp"
#include "world/RoomManager.hpp"

static void DrawControlsHint() {
    const char *hintsStr =
        "Use W/D to move, SPACE to jump, P to pause";
    int hintsSize = 4;
    int titleWidth = MeasureText(hintsStr, hintsSize);

    int posX = (Config::VIRTUAL_WIDTH - titleWidth) / 2,
        posY = 3;

    DrawText(hintsStr, posX, posY, hintsSize, WHITE);
}

// TODO: We need another way to read our first level
// TODO: startingPosition should come from the level
PlayingScreen::PlayingScreen()
    : roomManager("assets/levels/level1.json"),
      player({Config::VIRTUAL_WIDTH / 2.0f,
              Config::VIRTUAL_HEIGHT / 2.0f},
             Config::PLAYER_SPEED, MAROON) {}

ScreenResult PlayingScreen::Update(float deltaTime) {
    player.Update(deltaTime, roomManager.GetCurrentLevel());
    roomManager.CheckRoomTransition(player);

    if (IsKeyPressed(KEY_P)) {
        ScreenResult result;
        // On pause, we move our own state into a new
        // PlayingScreen instance so it survives after this
        // object is destroyed, PauseScreen takes ownership
        // of it and hands it back unchanged when unpausing
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
