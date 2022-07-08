#include "entity.h"

namespace sg {
namespace gamelogic {
Entity::Entity(const char* spriteName, int sizeX, int sizeY, int posX,
               int posY) {
  const char* defaultPath = "../assets/";
  char* path = new char[strlen(defaultPath) + strlen(spriteName)];
  path = strcat(path, defaultPath);
  path = strcat(path, spriteName);

  spriteRenderer = new Surface(path, sizeX, sizeY);
  transform = new Transform(posX, posY);
}

Entity::~Entity() {}

void Entity::SetAnimation() { spriteRenderer->InitAnimation(); }

void Entity::CutSprite(int posX, int posY) {
  spriteRenderer->CutSurface(posX, posY);
}

void Entity::OnLoad() { spriteRenderer->OnLoad(transform); }

void Entity::RegisterChildEntity(Entity* entity) {
  entities.push_back(entity);
  entity->RegisterParentEntity(this);
  entity->OnLoad();
}

void Entity::RegisterParentEntity(Entity* entity) { parent = entity; }

void Entity::AddDestoryTargetEntity(Entity* entity) {
  destroyTargets.push_back(entity);
}

void Entity::RemoveDestroyTargets() {
  if (destroyTargets.empty()) return;
  for (auto entity : destroyTargets) {
    entities.remove(entity);
  }
  destroyTargets.clear();
}

void Entity::OnLoop() {
  spriteRenderer->OnLoop();
  for (auto entity : entities) {
    entity->OnLoop();
  }
  RemoveDestroyTargets();
  // virtual method
}

void Entity::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  for (auto entity : entities) {
    entity->OnKeyDown(key, mod);
  }
  // virtual method
}

void Entity::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  // virtual method
  for (auto entity : entities) {
    entity->OnKeyUp(key, mod);
  }
}

void Entity::OnKey(SDL_Keycode key) {
  // virtual method
  for (auto entity : entities) {
    entity->OnKey(key);
  }
}

void Entity::OnRender(SDL_Renderer* renderer) {
  spriteRenderer->OnDraw(renderer);
  for (auto entity : entities) {
    entity->OnRender(renderer);
  }
}

void Entity::Destroy() {
  if (parent) {
    parent->AddDestoryTargetEntity(this);
  }
  OnCleanUp();
}

void Entity::OnCleanUp() {
  if (spriteRenderer) {
    spriteRenderer->OnClear();
  }
  for (auto entity : entities) {
    entity->OnCleanUp();
  }
  entities.clear();
  spriteRenderer = NULL;
}

}  // namespace gamelogic
}  // namespace sg
