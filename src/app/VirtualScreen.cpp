#include "app/VirtualScreen.hpp"

VirtualScreen::VirtualScreen(int virtualWidth,
                             int virtualHeight)
    : virtualWidth(virtualWidth),
      virtualHeight(virtualHeight) {
    target = LoadRenderTexture(virtualWidth, virtualHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
}

VirtualScreen::~VirtualScreen() {
    UnloadRenderTexture(target);
}

void VirtualScreen::BeginDrawing() const {
    BeginTextureMode(target);
}

void VirtualScreen::EndDrawing() const {
    EndTextureMode();

    // Rectangle with virtual width/height where we draw
    Rectangle source = {0, 0, (float)target.texture.width,
                        -(float)target.texture.height};

    // Rectangle where the virtual screen will be drawn
    // The size will cover the screen resolution,
    // maintaining the aspect ratio
    Rectangle dest = GetDestinationRect();

    ::BeginDrawing();

    ClearBackground(BLACK);

    // Draw the source texture into destination rectangle
    DrawTexturePro(target.texture, source, dest, {0, 0},
                   0.0f, WHITE);

    ::EndDrawing();
}

Rectangle VirtualScreen::GetDestinationRect() const {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    float scaleX = (float)screenWidth / virtualWidth;
    float scaleY = (float)screenHeight / virtualHeight;

    // Select the minor scale so we don't overflow the
    // screen
    float scale = (scaleX < scaleY) ? scaleX : scaleY;

    // We multiply the dimensions by scale to mantain the
    // aspect ratio
    float destWidth = virtualWidth * scale;
    float destHeight = virtualHeight * scale;

    float destX = (screenWidth - destWidth) / 2.0f;
    float destY = (screenHeight - destHeight) / 2.0f;

    return {destX, destY, destWidth, destHeight};
}
