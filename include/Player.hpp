#pragma once

#include "Level.hpp"
#include "raylib.h"

class Player {
  public:
    Player(Vector2 startPosition, float size, float speed,
           Color color);

    void Update(float deltaTime, const Level &level);
    void Draw() const;

  private:
    Vector2 position;
    float size;
    float speed;
    Color color;
};
