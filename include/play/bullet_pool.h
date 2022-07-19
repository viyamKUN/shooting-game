#ifndef __BULLET_POOL_H_
#define __BULLET_POOL_H_

#include "bullet.h"
#include "object_pool.h"

namespace sg {
namespace gamelogic {
namespace play {
// Manage whole bullets for game. (include whole enemies and player.)
class BulletPool {
 public:
  BulletPool();
  ~BulletPool();

  void SpawnBullet(int posX, int posY, int speed, FACTION faction);

 private:
  const int START_COUNT = 32;
  ObjectPool* pool;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
