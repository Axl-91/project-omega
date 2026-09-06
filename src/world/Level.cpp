#include "world/Level.hpp"
#include "world/TileType.hpp"

Level::Level(const tilesVector &tileData)
    : tiles(tileData) {}

void Level::Draw() const {
    for (int row = 0; row < (int)tiles.size(); row++) {
        for (int col = 0; col < (int)tiles[row].size();
             col++) {
            if (tiles[row][col] == (int)TileType::Solid) {
                DrawRectangle(col * TILE_SIZE,
                              row * TILE_SIZE, TILE_SIZE,
                              TILE_SIZE, DARKGRAY);
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
                solids.push_back({(float)(col * TILE_SIZE),
                                  (float)(row * TILE_SIZE),
                                  (float)TILE_SIZE,
                                  (float)TILE_SIZE});
            }
        }
    }

    return solids;
}
