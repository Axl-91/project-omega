#include "world/LevelLoader.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <vector>

namespace LevelLoader {
    /**
     * @brief Loads all rooms from a level file in JSON
     * format.
     *
     * @param path Path to the JSON file, relative to the
     * executable's working directory.
     *
     * @return The loaded rooms, in the same order they
     * appear in the file.
     *
     * @throws std::runtime_error if the file doesn't exist,
     * is malformed, or is missing the expected "rooms"
     * field.
     */
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
