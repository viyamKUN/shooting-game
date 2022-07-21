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

void EntityRegistry::RegisterEntityDestroy(Entity* entity) {
  destroyRegistry.push_back(entity);
}

bool EntityRegistry::HasDestroyRegister() { return !destroyRegistry.empty(); }

void EntityRegistry::DestroyEntitiesIsDestroyRegistry() {
  for (auto entity : destroyRegistry) {
    entities.remove(entity);
    entity->OnCleanUp();
    // TODO: delete called on non-final 'sg::gamelogic::Entity' that has virtual
    // functions but non-virtual destructo
    delete entity;
  }
  destroyRegistry.clear();
}

std::list<Entity*> EntityRegistry::GetRegistry() { return entities; }

std::list<Entity*> EntityRegistry::GetDestroyRegistry() {
  return destroyRegistry;
}

void EntityRegistry::CleanUpRegistry() { entities.clear(); }

}  // namespace gamelogic
}  // namespace sg
