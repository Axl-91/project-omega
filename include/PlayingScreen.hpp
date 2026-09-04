#pragma once

#include "GameScreen.hpp"
#include "Level.hpp"
#include "Player.hpp"

class PlayingScreen : public GameScreen {
  public:
    PlayingScreen();

    ScreenResult Update(float deltaTime) override;
    void Draw() const override;

  private:
    Level level;
    Player player;
};
