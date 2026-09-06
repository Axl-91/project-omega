#pragma once

#include "Level.hpp"
#include <string>
#include <vector>

namespace LevelLoader {
    std::vector<Level> LoadRooms(const std::string &path);
}
