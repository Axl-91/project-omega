#pragma once

#include <memory>

class GameScreen;
using ScreenPtr = std::unique_ptr<GameScreen>;

struct ScreenResult {
    ScreenPtr nextScreen = nullptr;
    bool quit = false;
};

class GameScreen {
  public:
    virtual ~GameScreen() = default;

    virtual ScreenResult Update(float deltaTime) = 0;

    virtual void Draw() const = 0;
};
