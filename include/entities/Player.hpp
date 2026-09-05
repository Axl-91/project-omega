#pragma once

#include "raylib.h"
#include "world/Level.hpp"

class Player {
  public:
    Player(Vector2 startPosition, float size, float speed,
           Color color);

    void Update(float deltaTime, const Level &level);
    void Draw() const;

    Vector2 GetPosition() const { return position; }
    void SetPosition(Vector2 newPosition) {
        position = newPosition;
    }

  private:
    Vector2 position;
    Vector2 velocity;

    float size;
    float speed;
    Color color;

    bool onGround;
    bool isJumping;
    float coyoteTimeCounter;
};
