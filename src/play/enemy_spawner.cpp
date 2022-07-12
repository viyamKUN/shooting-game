#include "play/enemy_spawner.h"

namespace sg {
namespace gamelogic {
namespace play {

EnemySpawner::EnemySpawner() : ObjectPool(MAX_COUNT) {}

EnemySpawner::~EnemySpawner() {}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
