#pragma once

#include "../app/GameScreen.hpp"

class MainMenuScreen : public GameScreen {
  public:
    ScreenResult Update(float deltaTime) override;
    void Draw() const override;

  private:
    int selectedOption = 0;
};
