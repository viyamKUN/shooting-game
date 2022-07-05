#include "entity.h"

namespace GameLogic {

Entity::Entity(const char* spriteName) {
  const char* defaultPath = "../assets/";
  char* path = new char[strlen(defaultPath) + strlen(spriteName)];
  path = strcat(path, defaultPath);
  path = strcat(path, spriteName);
  spriteSurface = new Surface(path);
}

Entity::~Entity() {}

void Entity::OnLoad() { spriteSurface->OnLoad(); }

void Entity::OnLoop() {}

void Entity::OnRender(SDL_Renderer* renderer) {
  spriteSurface->OnDraw(renderer);
}

void Entity::OnCleanUp() {
  if (spriteSurface) {
    spriteSurface->OnClear();
  }
  spriteSurface = NULL;
}

}  // namespace GameLogic
