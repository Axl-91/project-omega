#pragma once

#include "raylib.h"
#include "world/Level.hpp"

class Player {
  public:
    Player(Vector2 startPosition, float speed, Color color);

    /**
     * @brief Update the player's position, physics, and
     * collisions against the level for this frame.
     *
     * @param deltaTime Time elapsed since the last frame,
     * in seconds.
     * @param level The level to check collisions against
     * (read-only).
     */
    void Update(float deltaTime, const Level &level);
    void Draw() const;

    Vector2 GetPosition() const { return position; }

    /**
     * @brief Change the position of the player to the one
     * that is specified on the params.
     *
     * @param newPosition the new position of the player.
     *
     * @note Used for teleporting the player when this one
     * change rooms
     */
    void SetPosition(Vector2 newPosition) {
        position = newPosition;
    }

  private:
    Vector2 position;
    Vector2 velocity;

    float width;
    float height;

    float speed;
    Color color;

    bool onGround;
    bool isJumping;
    float coyoteTimeCounter;
};
