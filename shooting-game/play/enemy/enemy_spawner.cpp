#include "shooting-game/play/enemy/enemy_spawner.h"
namespace sg {
namespace play {

EnemySpawner::EnemySpawner() : Entity() {
  auto baseEntity = new Enemy(0, 0);
  enemyPool = new core::ObjectPool(baseEntity, MAX_COUNT);
  spawnTimeBucket = SDL_GetTicks();
  interval = START_INTERVAL;
}

EnemySpawner::~EnemySpawner() {}

void EnemySpawner::ClearEnemies() { enemyPool->DisableAllObjects(); }

void EnemySpawner::OnLoop() {
  if (SDL_GetTicks() > spawnTimeBucket + interval) {
    spawnTimeBucket = SDL_GetTicks();
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
  enemy->SetIsActive(true);
  srand(SDL_GetTicks());
  int randomPos = SCREEN_WIDTH * (rand() % 100 * 0.01);
  ((Enemy*)enemy)->ResetData(randomPos, 0);
}

}  // namespace play
}  // namespace sg
