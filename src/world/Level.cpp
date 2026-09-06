#include "Config.hpp"
#include "world/Level.hpp"
#include "world/TileType.hpp"

Level::Level(const tilesVector &tileData)
    : tiles(tileData) {}

void Level::Draw() const {
    for (int row = 0; row < (int)tiles.size(); row++) {
        for (int col = 0; col < (int)tiles[row].size();
             col++) {
            if (tiles[row][col] == (int)TileType::Solid) {
                DrawRectangle(col * Config::TILE_SIZE,
                              row * Config::TILE_SIZE,
                              Config::TILE_SIZE,
                              Config::TILE_SIZE, DARKGRAY);
            }
        }
    }
}

std::vector<Rectangle> Level::GetSolidTiles() const {
    std::vector<Rectangle> solids;

    for (int row = 0; row < (int)tiles.size(); row++) {
        for (int col = 0; col < (int)tiles[row].size();
             col++) {
            if (tiles[row][col] == (int)TileType::Solid) {
                solids.push_back(
                    {(float)(col * Config::TILE_SIZE),
                     (float)(row * Config::TILE_SIZE),
                     (float)Config::TILE_SIZE,
                     (float)Config::TILE_SIZE});
            }
        }
    }

    return solids;
}
