#include "play/enemy/enemy_blood_pool.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace enemy {

EnemyBloodPool::EnemyBloodPool() {
  Entity* baseEntity = new EnemyHitEffect();
  pool = new ObjectPool(baseEntity, START_COUNT);
}

EnemyBloodPool::~EnemyBloodPool() {}

void EnemyBloodPool::CallBloodAnim(int x, int y) {
  auto entity = pool->GetObject();
  entity->SetIsActive(true);
  ((EnemyHitEffect*)entity)->SetPosition(x, y);
  ((EnemyHitEffect*)entity)->ResetData();
}

}  // namespace enemy
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
