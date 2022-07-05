#include "animation.h"

namespace sg {
namespace gamelogic {
Animation::Animation(int maxFrame, int animationType)
    : maxFrame(maxFrame),
      animationType(animationType),
      frameRate(150),
      currentFrame(0),
      timeBucket(0),
      frameIncrease(1),
      animationState(0) {}

Animation::~Animation() {}

void Animation::OnAnimate() {
  if (timeBucket + frameRate > SDL_GetTicks()) return;

  timeBucket = SDL_GetTicks();
  currentFrame += frameIncrease;

  switch (animationType) {
    case ANIMATION_RESTART:
      if (currentFrame >= maxFrame) currentFrame = 0;
      break;

    case ANIMATION_PINGPONG:
      if (currentFrame >= maxFrame)
        frameIncrease *= -1;
      else if (currentFrame == 0)
        frameIncrease *= -1;
      break;

    default:
      break;
  }
}

int Animation::GetCurrentFrame() { return currentFrame; }

// Get animation state index (ex. idle = 0, run = 1)
int Animation::GetAnimationState() { return animationState; }

}  // namespace gamelogic
}  // namespace sg
