#ifndef __ENTITY_REGISTRY_H_
#define __ENTITY_REGISTRY_H_

#include <list>

#include "shooting-game/core/entity.h"

namespace sg {
namespace core {
class EntityRegistry {
 public:
  EntityRegistry();
  ~EntityRegistry();

  static EntityRegistry* GetInstance();

  void RegistEntity(Entity* entity);
  void CleanUpRegistry();

  std::list<Entity*> GetRegistry();

 private:
  std::list<Entity*> entities;

  static EntityRegistry* instance;
};

}  // namespace core
}  // namespace sg

#endif
