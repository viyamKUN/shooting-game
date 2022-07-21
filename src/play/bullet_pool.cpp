#include "play/bullet_pool.h"

namespace sg {
namespace play {

BulletPool::BulletPool() {
  Bullet* baseBullet = new Bullet();
  pool = new gamelogic::ObjectPool(baseBullet, START_COUNT);
}

BulletPool::~BulletPool() {}

void BulletPool::SpawnBullet(int posX, int posY, int speed, FACTION faction) {
  auto bullet = pool->GetObject();
  ((Bullet*)bullet)->ResetData(posX, posY, speed, faction);
}

}  // namespace play
}  // namespace sg
