#pragma once

#include "Level.hpp"
#include "Player.hpp"

class Game {
  public:
    Game();

    void Run();

  private:
    static const int screenWidth = 800;
    static const int screenHeight = 600;

    Player player;
    Level level;

    void Update();
    void Draw();
};
