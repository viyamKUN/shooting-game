#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#include <SDL.h>

namespace sg {
namespace gamelogic {

enum ANIMATING_TYPE { ANIMATION_NONE, ANIMATION_RESTART, ANIMATION_PINGPONG };

class Animation {
 public:
  const int animationType;
  const int frameRate;

 public:
  Animation(int maxFrame, int animationType);
  ~Animation();

  void OnAnimate();
  int GetCurrentFrame();
  void SetAnimationState(int state);
  int GetAnimationState();

 private:
  int currentFrame;
  int timeBucket;
  int frameIncrease;
  int animationState;
  int maxFrame;
};

}  // namespace gamelogic
}  // namespace sg

#endif
