#include "Config.hpp"
#include "Physics.hpp"
#include "world/LevelLoader.hpp"
#include "world/RoomManager.hpp"

// TODO: currentRoomIndex should come from the level json
RoomManager::RoomManager(const std::string &levelPath)
    : rooms(LevelLoader::LoadRooms(levelPath)),
      currentRoomIndex(0) {}

const Level &RoomManager::GetCurrentLevel() const {
    return rooms[currentRoomIndex];
}

bool RoomManager::CheckRoomTransition(Player &player) {
    Vector2 pos = player.GetPosition();

    if (pos.x > Config::VIRTUAL_WIDTH) {
        if (currentRoomIndex + 1 < (int)rooms.size()) {
            currentRoomIndex++;
            player.SetPosition(
                {1.0f, pos.y - Physics::COLLISION_EPSILON});
            return true;
        }
    } else if (pos.x + Config::PLAYER_WIDTH < 0) {
        if (currentRoomIndex - 1 >= 0) {
            currentRoomIndex--;
            player.SetPosition(
                {Config::VIRTUAL_WIDTH -
                     Config::PLAYER_WIDTH - 1.0f,
                 pos.y - Physics::COLLISION_EPSILON});
            return true;
        }
    }
    return false;
}
