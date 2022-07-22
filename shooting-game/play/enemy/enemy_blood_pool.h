#ifndef __ENEMY_BLOOD_POOL_H_
#define __ENEMY_BLOOD_POOL_H_

#include "shooting-game/core/entity.h"
#include "shooting-game/core/object_pool.h"
#include "shooting-game/play/enemy/enemy_hit_effect.h"

namespace sg {
namespace play {
namespace enemy {
class EnemyBloodPool {
 public:
  EnemyBloodPool();
  ~EnemyBloodPool();

  void CallBloodAnim(int x, int y);
  void ClearBloods();

 private:
  const int START_COUNT = 32;
  core::ObjectPool* pool;
};

}  // namespace enemy
}  // namespace play
}  // namespace sg

#endif
