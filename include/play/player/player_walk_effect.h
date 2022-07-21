#ifndef __PLAYER_WALK_EFFECT_H_
#define __PLAYER_WALK_EFFECT_H_

#include "gamelogic/entity.h"
#include "play/game_settings.h"

namespace sg {
namespace play {
class PlayerWalkEffect : public gamelogic::Entity {
 public:
  PlayerWalkEffect();
  ~PlayerWalkEffect();
  void PlayWalkAnim();
  void StopWalkAnim();
  void SetPosition(int x, int y, SIDE moveSide);

 private:
  static const int SIZE = 32;
  static const int MARGIN_FROM_PLAYER = 20;

  void SetAnimation();
};

}  // namespace play
}  // namespace sg

#endif
