#ifndef __ENEMY_SPAWNER_H_
#define __ENEMY_SPAWNER_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity.h"
#include "shooting-game/core/object_pool.h"
#include "shooting-game/play/enemy/enemy.h"

namespace sg {
namespace play {
class EnemySpawner : public core::Entity {
 public:
  EnemySpawner();
  ~EnemySpawner();

  void ClearEnemies();
  void OnLoop();

 private:
  static const int MAX_COUNT = 5;
  static const int START_INTERVAL = 4000;
  core::ObjectPool* enemyPool;
  int spawnTimeBucket;
  int interval;

  void SetSpawnInterval();
  void OnSpawn();
};

}  // namespace play
}  // namespace sg

#endif
