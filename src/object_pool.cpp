#include "object_pool.h"

#include "game.h"

namespace sg {
namespace gamelogic {

ObjectPool::ObjectPool(Entity* baseEntity, int maxCount) {
  for (int i = 0; i < maxCount; i++) {
    auto entity = baseEntity->Clone();
    objects.push_back(entity);
    Game::GetInstance()->RegisterEntity(entity);
    entity->SetIsActive(false);
  }
}

ObjectPool::~ObjectPool() {}

Entity* ObjectPool::GetObject() {
  for (auto obj : objects) {
    if (!obj->GetIsActive()) return obj;
  }
  return NULL;
}
}  // namespace gamelogic
}  // namespace sg
