#ifndef __ENEMY_HIT_EFFECT_H_
#define __ENEMY_HIT_EFFECT_H_

#include "shooting-game/core/entity/entity.h"

namespace sg {
namespace play {
namespace enemy {
class EnemyHitEffect : public core::entity::Entity {
 public:
  EnemyHitEffect();
  ~EnemyHitEffect();

  core::entity::Entity* Clone();
  void SetPosition(int x, int y);
  void ResetData();

 private:
  static const int SIZE = 32;
  static const int MARGIN_FROM_PLAYER = 20;

  void SetAnimation();
};

}  // namespace enemy
}  // namespace play
}  // namespace sg
#endif
