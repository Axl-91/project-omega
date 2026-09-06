#include "world/LevelLoader.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <vector>

namespace LevelLoader {
    std::vector<Level> LoadRooms(const std::string &path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            throw std::runtime_error("Can't open file: " +
                                     path);
        }

        nlohmann::json data;
        file >> data;

        if (!data.contains("rooms")) {
            throw std::runtime_error(
                "Rooms Error: There's no room key" + path);
        }
        if (!data.at("rooms").is_array()) {
            throw std::runtime_error(
                "Rooms Error: Room is not an array" + path);
        }

        std::vector<Level> rooms;
        for (const auto &roomJson : data.at("rooms")) {
            auto tileData =
                roomJson.at("tiles")
                    .get<std::vector<std::vector<int>>>();
            rooms.emplace_back(tileData);
        }

        if (rooms.empty()) {
            throw std::runtime_error(
                "Rooms Error: There are no rooms: " + path);
        }
        return rooms;
    }

} // namespace LevelLoader
