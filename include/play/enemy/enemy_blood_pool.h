#ifndef __ENEMY_BLOOD_POOL_H_
#define __ENEMY_BLOOD_POOL_H_

#include "entity.h"
#include "object_pool.h"
#include "play/enemy/enemy_hit_effect.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace enemy {
class EnemyBloodPool {
 public:
  EnemyBloodPool();
  ~EnemyBloodPool();

  void CallBloodAnim(int x, int y);

 private:
  const int START_COUNT = 32;
  ObjectPool* pool;
};

}  // namespace enemy
}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
