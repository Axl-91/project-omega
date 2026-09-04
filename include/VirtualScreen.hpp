#pragma once

#include "raylib.h"

class VirtualScreen {
  public:
    VirtualScreen(int virtualWidth, int virtualHeight);
    ~VirtualScreen();

    VirtualScreen(const VirtualScreen &) = delete;
    VirtualScreen &
    operator=(const VirtualScreen &) = delete;

    void BeginDrawing() const;
    void EndDrawing() const;

  private:
    int virtualWidth;
    int virtualHeight;
    RenderTexture2D target;

    Rectangle GetDestinationRect() const;
};
