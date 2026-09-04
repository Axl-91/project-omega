#pragma once

#include "GameScreen.hpp"
#include "PlayingScreen.hpp"
#include <memory>

class PauseScreen;
using PlayScreenPtr = std::unique_ptr<PlayingScreen>;

class PauseScreen : public GameScreen {
  public:
    explicit PauseScreen(PlayScreenPtr playingScreen);

    ScreenResult Update(float deltaTime) override;
    void Draw() const override;

  private:
    PlayScreenPtr playingScreen;
};
