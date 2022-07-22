#include "shooting-game/gamelogic/animation.h"

namespace sg {
namespace gamelogic {
Animation::Animation()
    : frameRate(150),
      currentFrame(0),
      timeBucket(0),
      // TODO(hayeon): warning: field 'animationState' will be initialized after
      // field 'frameIncrease'
      animationState(0),
      frameIncrease(1),
      isAnimationOver(false) {}

Animation::~Animation() {}

void Animation::OnAnimate() {
  if (timeBucket + frameRate > SDL_GetTicks()) return;

  timeBucket = SDL_GetTicks();
  currentFrame += frameIncrease;
  Uint16 animationType = animationStatesMap[animationState].animationType;
  int maxFrame = animationStatesMap[animationState].maxFrame;

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

    case ANIMATION_ONETIME:
      if (currentFrame >= maxFrame) isAnimationOver = true;
    default:
      break;
  }
}

int Animation::GetCurrentFrame() { return currentFrame; }

// Get animation state index (ex. idle = 0, run = 1)
int Animation::GetAnimationState() { return animationState; }

void Animation::SetAnimationState(Uint16 state) {
  if (animationState != state) {
    currentFrame = 0;
  }
  animationState = state;
}

void Animation::AddAnimationState(Uint16 state, Uint16 animType, int maxFrame) {
  AnimationState animState;
  animState.animationType = animType;
  animState.maxFrame = maxFrame;
  animationStatesMap.insert({state, animState});
}

void Animation::ResetAnimation() {
  currentFrame = 0;
  isAnimationOver = false;
}

bool Animation::GetIsAnimationOver() { return isAnimationOver; }

}  // namespace gamelogic
}  // namespace sg