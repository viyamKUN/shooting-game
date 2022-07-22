#ifndef __OBJECT_POOL_H_
#define __OBJECT_POOL_H_

#include <iostream>
#include <list>

#include "shooting-game/core/entity_registry.h"

namespace sg {
namespace core {

class ObjectPool {
 public:
  ObjectPool(entity::Entity* baseEntity, int maxCount);
  ~ObjectPool();

  entity::Entity* GetObject();
  void DisableAllObjects();

 private:
  std::list<entity::Entity*> objects;
  entity::Entity* baseEntity;

  void CreateObjects(int maxCount);
};

}  // namespace core
}  // namespace sg

#endif
