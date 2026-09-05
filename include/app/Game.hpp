#pragma once

#include "GameScreen.hpp"
#include "VirtualScreen.hpp"
#include <memory>

class Game {
  public:
    Game();

    void Run();

  private:
    std::unique_ptr<VirtualScreen> virtualScreen;
    std::unique_ptr<GameScreen> currentScreen;
};
