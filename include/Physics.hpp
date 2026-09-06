#pragma once

namespace Physics {
    constexpr float GRAVITY = 1000.0f;
    constexpr float MAX_FALL_SPEED = 500.0f;

    constexpr float JUMP_FORCE = 350.0f;
    constexpr float JUMP_CUT_MULTIPLIER = 0.4f;

    // Epsilon I need for transitions so collision is
    // detected correctly
    constexpr float COLLISION_EPSILON = 0.5f;

    constexpr float COYOTE_TIME = 0.10f;
} // namespace Physics
