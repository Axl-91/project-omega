#pragma once

#include <raylib.h>
#include <vector>

using tilesVector = std::vector<std::vector<int>>;

class Level {
  public:
    explicit Level(const tilesVector &tileData);

    void Draw() const;
    std::vector<Rectangle> GetSolidTiles() const;

  private:
    tilesVector tiles;
};
