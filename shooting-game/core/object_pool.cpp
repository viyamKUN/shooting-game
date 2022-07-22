#include "shooting-game/core/object_pool.h"

namespace sg {
namespace core {

ObjectPool::ObjectPool(entity::Entity* baseEntity, int maxCount) {
  this->baseEntity = baseEntity;
  CreateObjects(maxCount);
}

ObjectPool::~ObjectPool() {}

entity::Entity* ObjectPool::GetObject() {
  for (auto obj : objects) {
    if (!obj->GetIsActive()) return obj;
  }
  CreateObjects(objects.size());
  return objects.back();
}

void ObjectPool::DisableAllObjects() {
  for (auto obj : objects) {
    if (obj->GetIsActive()) obj->SetIsActive(false);
  }
}

int ObjectPool::GetObjectCount() { return objects.size(); }

void ObjectPool::CreateObjects(int maxCount) {
  for (int i = 0; i < maxCount; i++) {
    auto entity = baseEntity->Clone();
    objects.push_back(entity);
    EntityRegistry::GetInstance()->RegistEntity(entity);
    entity->SetIsActive(false);
  }
}

}  // namespace core
}  // namespace sg
