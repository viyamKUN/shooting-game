#include "play/enemy_spawner.h"
namespace sg {
namespace gamelogic {
namespace play {

EnemySpawner::EnemySpawner() : Entity() {
  auto baseEntity = new Enemy();
  enemyPool = new ObjectPool(baseEntity, MAX_COUNT);
}

EnemySpawner::~EnemySpawner() {}

void EnemySpawner::OnLoop() {}

void EnemySpawner::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  if (key == SDLK_a) OnSpawn();
}

void EnemySpawner::OnSpawn() {
  auto enemy = enemyPool->GetObject();
  if (enemy == NULL) return;
  // TODO: if there is no entity to return, enemy will be null. Need some
  // feedbacks.

  enemy->SetIsActive(true);
  // TODO: Reset enemy data (ex. hp, position...)
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
