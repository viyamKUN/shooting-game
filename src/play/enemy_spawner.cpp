#include "play/enemy_spawner.h"
namespace sg {
namespace gamelogic {
namespace play {

EnemySpawner::EnemySpawner() : Entity() {
  auto baseEntity = new Enemy();
  enemyPool = new ObjectPool(baseEntity, MAX_COUNT);
  spawnTimeBucket = SDL_GetTicks();
  interval = START_INTERVAL;
}

EnemySpawner::~EnemySpawner() {}

void EnemySpawner::OnLoop() {
  if (SDL_GetTicks() > spawnTimeBucket + interval) {
    spawnTimeBucket = SDL_GetTicks();
    auto decreseAmount = 1 - SDL_GetTicks() * 0.01;
    SetSpawnInterval();
    OnSpawn();
  }
}

void EnemySpawner::SetSpawnInterval() {
  auto value = -0.0001 * SDL_GetTicks() + START_INTERVAL;
  if (value <= 200) {
    interval = 200;
    return;
  }
  interval = value;
}

void EnemySpawner::OnSpawn() {
  auto enemy = enemyPool->GetObject();
  if (enemy == NULL) return;
  // TODO: if there is no entity to return, enemy will be null. Need some
  // feedbacks.

  enemy->SetIsActive(true);
  srand(SDL_GetTicks());
  int randomPos = SCREEN_WIDTH * (rand() % 100 * 0.01);
  ((Enemy*)enemy)->ResetData(randomPos, 0);
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
