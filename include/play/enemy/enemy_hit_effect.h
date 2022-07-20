#ifndef __ENEMY_HIT_EFFECT_H_
#define __ENEMY_HIT_EFFECT_H_

#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace enemy {
class EnemyHitEffect : public Entity {
 public:
  EnemyHitEffect();
  ~EnemyHitEffect();

  Entity* Clone();
  void SetPosition(int x, int y);

 private:
  static const int SIZE = 32;
  static const int MARGIN_FROM_PLAYER = 20;

  void SetAnimation();
};

}  // namespace enemy
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
#endif
