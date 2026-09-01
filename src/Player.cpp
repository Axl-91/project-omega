#include "Player.hpp"

Player::Player(Vector2 startPosition, float size, float speed, Color color)
    : position(startPosition), size(size), speed(speed), color(color) {}

void Player::Update(float deltaTime) {
  float distance = speed * deltaTime;

  if (IsKeyDown(KEY_D))
    position.x += distance;
  if (IsKeyDown(KEY_A))
    position.x -= distance;
  if (IsKeyDown(KEY_S))
    position.y += distance;
  if (IsKeyDown(KEY_W))
    position.y -= distance;
}

void Player::Draw() const { DrawRectangleV(position, {size, size}, color); }
