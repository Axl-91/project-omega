#pragma once

#include <raylib.h>
#include <vector>

using tilesVector = std::vector<std::vector<int>>;

class Level {
  public:
    static const int TILE_SIZE = 25;

    explicit Level(const tilesVector &tileData);

    void Draw() const;
    std::vector<Rectangle> GetSolidTiles() const;

  private:
    tilesVector tiles;
};
