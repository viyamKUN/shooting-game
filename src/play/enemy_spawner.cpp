#include "play/enemy_spawner.h"

#include "game.h"

namespace sg {
namespace gamelogic {
namespace play {

EnemySpawner::EnemySpawner() : Entity() {
  enemyPool = new ObjectPool<Enemy>(MAX_COUNT);
}

EnemySpawner::~EnemySpawner() {}

void EnemySpawner::OnLoop() {}

void EnemySpawner::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  if (key == SDLK_a) OnSpawn();
}

void EnemySpawner::OnSpawn() {
  Enemy* enemy = enemyPool->GetObject();
  Game::GetInstance()->RegisterEntity(enemy);
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
