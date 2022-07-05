#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#include <SDL.h>

namespace sg::gamelogic {

enum ANIMATING_TYPE { ANIMATION_NONE, ANIMATION_RESTART, ANIMATION_PINGPONG };

class Animation {
 private:
  int currentFrame;
  int timeBucket;
  int frameIncrease;

 public:
  const int maxFrame;
  const int animationType;
  const int frameRate;

 public:
  Animation(int maxFrame, int animationType);
  ~Animation();

  void OnAnimate();
  int GetCurrentFrame();
};

}  // namespace sg::gamelogic

#endif
