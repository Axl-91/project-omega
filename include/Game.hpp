#pragma once

#include "GameScreen.hpp"
#include <memory>

class Game {
  public:
    Game();

    void Run();

  private:
    std::unique_ptr<GameScreen> currentScreen;
};
