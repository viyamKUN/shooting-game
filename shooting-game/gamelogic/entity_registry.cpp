#include "shooting-game/gamelogic/entity_registry.h"

namespace sg {
namespace gamelogic {

EntityRegistry* EntityRegistry::instance = NULL;

EntityRegistry* EntityRegistry::GetInstance() {
  if (EntityRegistry::instance == NULL) {
    EntityRegistry::instance = new EntityRegistry();
  }
  return EntityRegistry::instance;
}

EntityRegistry::EntityRegistry() {}

EntityRegistry::~EntityRegistry() {}

void EntityRegistry::RegistEntity(Entity* entity) {
  entities.push_back(entity);
  entity->OnLoad();
  entity->SetIsActive(true);
}

std::list<Entity*> EntityRegistry::GetRegistry() { return entities; }

void EntityRegistry::CleanUpRegistry() { entities.clear(); }

}  // namespace gamelogic
}  // namespace sg
