#pragma once

#include "entities/Player.hpp"
#include "world/Level.hpp"
#include <string>
#include <vector>

class RoomManager {
  public:
    explicit RoomManager(const std::string &levelPath);

    const Level &GetCurrentLevel() const;

    /**
     * @brief Update the player's position, physics, and
     * collisions against the level for this frame.
     *
     * @param deltaTime Time elapsed since the last frame,
     * in seconds.
     * @param level The level to check collisions against
     * (read-only).
     */
    bool CheckRoomTransition(Player &player);

  private:
    std::vector<Level> rooms;
    int currentRoomIndex;
};
