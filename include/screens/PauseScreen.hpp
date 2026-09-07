#pragma once

#include "app/GameScreen.hpp"
#include "screens/PlayingScreen.hpp"
#include <memory>

class PauseScreen;
using PlayScreenPtr = std::unique_ptr<PlayingScreen>;

class PauseScreen : public GameScreen {
  public:
    /**
     * @brief Constructs a paused screen that takes
     * ownership of an existing PlayingScreen, keeping its
     * state intact while paused.
     *
     * @param playingScreen The in-progress game screen to
     * pause. Ownership is transferred to this PauseScreen;
     * it is returned unchanged via Update() when the player
     * unpauses.
     */
    explicit PauseScreen(PlayScreenPtr playingScreen);

    ScreenResult Update(float deltaTime) override;
    void Draw() const override;

  private:
    PlayScreenPtr playingScreen;
};
