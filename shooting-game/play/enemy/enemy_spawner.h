#ifndef __ENEMY_SPAWNER_H_
#define __ENEMY_SPAWNER_H_

#include "shooting-game/gamelogic/config.h"
#include "shooting-game/gamelogic/entity.h"
#include "shooting-game/gamelogic/object_pool.h"
#include "shooting-game/play/enemy/enemy.h"

namespace sg {
namespace play {
class EnemySpawner : public gamelogic::Entity {
 public:
  EnemySpawner();
  ~EnemySpawner();

  void ClearEnemies();
  void OnLoop();

 private:
  static const int MAX_COUNT = 15;
  static const int START_INTERVAL = 4000;
  gamelogic::ObjectPool* enemyPool;
  int spawnTimeBucket;
  int interval;

  void SetSpawnInterval();
  void OnSpawn();
};

}  // namespace play
}  // namespace sg

#endif
