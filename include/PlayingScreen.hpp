#pragma once

#include "GameScreen.hpp"
#include "Player.hpp"
#include "RoomManager.hpp"

class PlayingScreen : public GameScreen {
  public:
    PlayingScreen();

    ScreenResult Update(float deltaTime) override;
    void Draw() const override;

  private:
    RoomManager roomManager;
    Player player;
};
