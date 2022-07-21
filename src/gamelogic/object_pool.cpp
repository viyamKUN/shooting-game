#include "gamelogic/object_pool.h"

#include "gamelogic/game.h"

namespace sg {
namespace gamelogic {

ObjectPool::ObjectPool(Entity* baseEntity, int maxCount) {
  this->baseEntity = baseEntity;
  CreateObjects(maxCount);
}

ObjectPool::~ObjectPool() {}

Entity* ObjectPool::GetObject() {
  for (auto obj : objects) {
    if (!obj->GetIsActive()) return obj;
  }
  CreateObjects(objects.size());
  return objects.back();
}

void ObjectPool::CreateObjects(int maxCount) {
  for (int i = 0; i < maxCount; i++) {
    auto entity = baseEntity->Clone();
    objects.push_back(entity);
    Game::GetInstance()->RegisterEntity(entity);
    entity->SetIsActive(false);
  }
}

}  // namespace gamelogic
}  // namespace sg
