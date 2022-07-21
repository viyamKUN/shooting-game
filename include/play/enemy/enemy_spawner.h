#ifndef __ENEMY_SPAWNER_H_
#define __ENEMY_SPAWNER_H_

#include "config.h"
#include "entity.h"
#include "object_pool.h"
#include "play/enemy/enemy.h"
namespace sg {
namespace gamelogic {
namespace play {
class EnemySpawner : public Entity {
 public:
  EnemySpawner();
  ~EnemySpawner();

  void OnLoop();

 private:
  static const int MAX_COUNT = 15;
  static const int START_INTERVAL = 4000;
  ObjectPool* enemyPool;
  int spawnTimeBucket;
  int interval;

  void SetSpawnInterval();
  void OnSpawn();
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
