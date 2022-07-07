#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#include <SDL.h>

#include <map>

namespace sg {
namespace gamelogic {

enum ANIMATING_TYPE { ANIMATION_NONE, ANIMATION_RESTART, ANIMATION_PINGPONG };

class Animation {
 public:
  Animation();
  ~Animation();

  void OnAnimate();
  int GetCurrentFrame();
  void SetAnimationState(Uint16 state);
  int GetAnimationState();
  void AddAnimationState(Uint16 state, Uint16 animType, int maxFrame);

 private:
  const int frameRate;

  int currentFrame;
  int timeBucket;
  int frameIncrease;
  Uint16 animationState;
  std::map<Uint16, struct AnimationState>
      animationStatesMap;  // state index, state
};

struct AnimationState {
 public:
  int maxFrame;
  Uint16 animationType;
};

}  // namespace gamelogic
}  // namespace sg

#endif
