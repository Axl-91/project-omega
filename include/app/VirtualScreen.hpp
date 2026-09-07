#pragma once

#include "raylib.h"

class VirtualScreen {
  public:
    VirtualScreen(int virtualWidth, int virtualHeight);
    ~VirtualScreen();

    VirtualScreen(const VirtualScreen &) = delete;
    VirtualScreen &
    operator=(const VirtualScreen &) = delete;

    /**
     * @brief Begins drawing to the internal
     * virtual-resolution texture instead of the real
     * window.
     *
     * Anything drawn between this call and the matching
     * EndDrawing() is rendered at the fixed virtual
     * resolution, regardless of the actual window size.
     */
    void BeginDrawing() const;

    /**
     * @brief Ends virtual-resolution drawing and presents
     * the result to the real window, scaled to fit (with
     * letterboxing if the aspect ratios don't match).
     */
    void EndDrawing() const;

  private:
    int virtualWidth;
    int virtualHeight;
    RenderTexture2D target;

    Rectangle GetDestinationRect() const;
};
