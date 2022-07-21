#ifndef __ENTITY_REGISTRY_H_
#define __ENTITY_REGISTRY_H_

#include <list>

#include "shooting-game/gamelogic/entity.h"

namespace sg {
namespace gamelogic {
class EntityRegistry {
 public:
  EntityRegistry();
  ~EntityRegistry();

  static EntityRegistry* GetInstance();

  void RegistEntity(Entity* entity);
  void RegisterEntityDestroy(Entity* entity);
  bool HasDestroyRegister();
  void DestroyEntitiesIsDestroyRegistry();
  void CleanUpRegistry();

  std::list<Entity*> GetRegistry();
  std::list<Entity*> GetDestroyRegistry();

 private:
  std::list<Entity*> entities;
  std::list<Entity*> destroyRegistry;

  static EntityRegistry* instance;
};

}  // namespace gamelogic
}  // namespace sg

#endif
