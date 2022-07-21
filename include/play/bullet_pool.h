#ifndef __BULLET_POOL_H_
#define __BULLET_POOL_H_

#include "bullet.h"
#include "gamelogic/object_pool.h"

namespace sg {
namespace play {
// Manage whole bullets for game. (include whole enemies and player.)
class BulletPool {
 public:
  BulletPool();
  ~BulletPool();

  void SpawnBullet(int posX, int posY, int speed, FACTION faction);
  void ClearBullets();

 private:
  const int START_COUNT = 32;
  gamelogic::ObjectPool* pool;
};

}  // namespace play
}  // namespace sg

#endif
