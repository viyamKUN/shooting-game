#ifndef __ENEMY_SPAWNER_H_
#define __ENEMY_SPAWNER_H_

#include "object_pool.h"

namespace sg {
namespace gamelogic {
namespace play {
class EnemySpawner : ObjectPool {
 public:
  EnemySpawner();
  ~EnemySpawner();
  void SetSpawnRule();
  void OnSpawn();

 private:
  static const int MAX_COUNT = 15;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
