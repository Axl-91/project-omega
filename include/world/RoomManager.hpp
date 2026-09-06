#pragma once

#include "entities/Player.hpp"
#include "world/Level.hpp"
#include <string>
#include <vector>

class RoomManager {
  public:
    explicit RoomManager(const std::string &levelPath);

    const Level &GetCurrentLevel() const;

    bool CheckRoomTransition(Player &player);

  private:
    std::vector<Level> rooms;
    int currentRoomIndex;
};
