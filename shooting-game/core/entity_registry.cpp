#include "shooting-game/core/entity_registry.h"

namespace sg {
namespace core {

EntityRegistry* EntityRegistry::instance = NULL;

EntityRegistry* EntityRegistry::GetInstance() {
  if (EntityRegistry::instance == NULL) {
    EntityRegistry::instance = new EntityRegistry();
  }
  return EntityRegistry::instance;
}

EntityRegistry::EntityRegistry() {}

EntityRegistry::~EntityRegistry() {}

void EntityRegistry::RegistEntity(entity::Entity* entity) {
  entities.push_back(entity);
  entity->OnLoad();
  entity->SetIsActive(true);
}

std::list<entity::Entity*> EntityRegistry::GetRegistry() { return entities; }

void EntityRegistry::CleanUpRegistry() {
  while (!entities.empty()) {
    delete entities.front();
    entities.pop_front();
  }
  entities.clear();
}

}  // namespace core
}  // namespace sg
