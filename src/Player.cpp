#include "Player.hpp"
#include <raylib.h>

Player::Player(Vector2 startPosition, float size,
               float speed, Color color)
    : position(startPosition), size(size), speed(speed),
      color(color) {}

void Player::Update(float deltaTime, const Level &level) {
    float distance = speed * deltaTime;
    std::vector<Rectangle> solids = level.GetSolidTiles();
    Rectangle playerRect = {position.x, position.y, size,
                            size};

    float moveX = 0;
    float moveY = 0;

    if (IsKeyDown(KEY_D))
        moveX += distance;
    if (IsKeyDown(KEY_A))
        moveX -= distance;
    if (IsKeyDown(KEY_S))
        moveY += distance;
    if (IsKeyDown(KEY_W))
        moveY -= distance;

    // --- Horizontal movement + collision ---
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
    position.y += moveY;
    playerRect.y = position.y;

    for (const Rectangle &tile : solids) {
        if (CheckCollisionRecs(playerRect, tile)) {
            if (moveY > 0) {
                position.y = tile.y - size;
            } else if (moveY < 0) {
                position.y = tile.y + tile.height;
            }
        }
        playerRect.y = position.y;
    }
}

void Player::Draw() const {
    DrawRectangleV(position, {size, size}, color);
}
