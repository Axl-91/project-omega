#pragma once

#include "Player.hpp"

class Game {
public:
  Game();

  void Run();

private:
  static const int screenWidth = 800;
  static const int screenHeight = 600;

  Player player;

  void Update();
  void Draw();
};
