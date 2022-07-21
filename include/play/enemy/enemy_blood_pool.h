#ifndef __ENEMY_BLOOD_POOL_H_
#define __ENEMY_BLOOD_POOL_H_

#include "gamelogic/entity.h"
#include "gamelogic/object_pool.h"
#include "play/enemy/enemy_hit_effect.h"

namespace sg {
namespace play {
namespace enemy {
class EnemyBloodPool {
 public:
  EnemyBloodPool();
  ~EnemyBloodPool();

  void CallBloodAnim(int x, int y);

 private:
  const int START_COUNT = 32;
  gamelogic::ObjectPool* pool;
};

}  // namespace enemy
}  // namespace play
}  // namespace sg

#endif
