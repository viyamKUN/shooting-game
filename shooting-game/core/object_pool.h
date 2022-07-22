#ifndef __OBJECT_POOL_H_
#define __OBJECT_POOL_H_

#include <iostream>
#include <list>

#include "shooting-game/core/entity.h"

namespace sg {
namespace core {

class ObjectPool {
 public:
  ObjectPool(Entity* baseEntity, int maxCount);
  ~ObjectPool();

  Entity* GetObject();
  void DisableAllObjects();

 private:
  std::list<Entity*> objects;
  Entity* baseEntity;

  void CreateObjects(int maxCount);
};

}  // namespace core
}  // namespace sg

#endif
