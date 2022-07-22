#include "shooting-game/play/enemy/enemy_blood_pool.h"

namespace sg {
namespace play {
namespace enemy {

EnemyBloodPool::EnemyBloodPool() {
  core::entity::Entity* baseEntity = new EnemyHitEffect();
  pool = new core::ObjectPool(baseEntity, START_COUNT);
}

EnemyBloodPool::~EnemyBloodPool() {}

void EnemyBloodPool::CallBloodAnim(int x, int y) {
  auto entity = pool->GetObject();
  entity->SetIsActive(true);
  ((EnemyHitEffect*)entity)->SetPosition(x, y);
  ((EnemyHitEffect*)entity)->ResetData();
}

void EnemyBloodPool::ClearBloods() { pool->DisableAllObjects(); }

}  // namespace enemy
}  // namespace play
}  // namespace sg
