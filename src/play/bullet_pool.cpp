#include "play/bullet_pool.h"

namespace sg {
namespace gamelogic {
namespace play {

BulletPool::BulletPool() {
  Bullet* baseBullet = new Bullet();
  pool = new ObjectPool(baseBullet, START_COUNT);
}

BulletPool::~BulletPool() {}

void BulletPool::SpawnBullet(int posX, int posY, int speed, FACTION faction) {
  auto bullet = pool->GetObject();
  ((Bullet*)bullet)->ResetData(posX, posY, speed, faction);
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
