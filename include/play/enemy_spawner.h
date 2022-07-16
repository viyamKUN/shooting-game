#ifndef __ENEMY_SPAWNER_H_
#define __ENEMY_SPAWNER_H_

#include "entity.h"
#include "object_pool.h"
#include "play/enemy.h"

namespace sg {
namespace gamelogic {
namespace play {
class EnemySpawner : public Entity {
 public:
  EnemySpawner();
  ~EnemySpawner();

  void OnLoop();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);

 private:
  static const int MAX_COUNT = 15;
  static const int INTERVAL = 4;
  ObjectPool* enemyPool;

  void OnSpawn();
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
