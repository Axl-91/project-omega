#pragma once

#include "app/GameScreen.hpp"
#include "entities/Player.hpp"
#include "world/RoomManager.hpp"

class PlayingScreen : public GameScreen {
  public:
    PlayingScreen();

    ScreenResult Update(float deltaTime) override;
    void Draw() const override;

  private:
    RoomManager roomManager;
    Player player;
};
