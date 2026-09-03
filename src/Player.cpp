#include "Physics.hpp"
#include "Player.hpp"
#include <raylib.h>

Player::Player(Vector2 startPosition, float size,
               float speed, Color color)
    : position(startPosition), velocity({0, 0}),
      onGround(false), size(size), speed(speed),
      color(color) {}

void Player::Update(float deltaTime, const Level &level) {
    float distance = speed * deltaTime;
    std::vector<Rectangle> solids = level.GetSolidTiles();
    Rectangle playerRect = {position.x, position.y, size,
                            size};

    velocity.x = 0;
    velocity.y += Physics::GRAVITY * deltaTime;
    velocity.y = velocity.y > Physics::MAX_FALL_SPEED
                     ? Physics::MAX_FALL_SPEED
                     : velocity.y;

    if (IsKeyPressed(KEY_SPACE) && onGround)
        velocity.y -= 500.0f;
    if (IsKeyDown(KEY_D))
        velocity.x += speed;
    if (IsKeyDown(KEY_A))
        velocity.x -= speed;

    // --- Horizontal movement + collision ---
    float moveX = velocity.x * deltaTime;
    position.x += moveX;
    playerRect.x = position.x;

    for (const Rectangle &tile : solids) {
        if (CheckCollisionRecs(playerRect, tile)) {
            if (moveX > 0) {
                position.x = tile.x - size;
            } else if (moveX < 0) {
                position.x = tile.x + tile.width;
            }
            playerRect.x = position.x;
        }
    }

    // --- Vertical movement + collision ---
    float moveY = velocity.y * deltaTime;
    position.y += moveY;
    playerRect.y = position.y;

    onGround = false;

    for (const Rectangle &tile : solids) {
        if (CheckCollisionRecs(playerRect, tile)) {
            if (moveY > 0) {
                position.y = tile.y - size;
                onGround = true;
            } else if (moveY < 0) {
                position.y = tile.y + tile.height;
            }
            playerRect.y = position.y;
            velocity.y = 0;
        }
    }
}

void Player::Draw() const {
    DrawRectangleV(position, {size, size}, color);
}
