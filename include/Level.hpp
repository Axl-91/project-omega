#pragma once

#include <raylib.h>
#include <string>
#include <vector>

class Level {
  public:
    static const int TILE_SIZE = 25;

    Level(const std::vector<std::string> &layout);

    void Draw() const;
    std::vector<Rectangle> GetSolidTiles() const;

  private:
    std::vector<std::string> tiles;
};
