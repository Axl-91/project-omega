#pragma once

#include "entities/Player.hpp"
#include "world/Level.hpp"
#include <vector>

class RoomManager {
  public:
    RoomManager();

    const Level &GetCurrentLevel() const;

    bool CheckRoomTransition(Player &player);

  private:
    std::vector<Level> rooms;
    int currentRoomIndex;
};
