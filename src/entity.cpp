#include "entity.h"

namespace sg::gamelogic {

Entity::Entity(const char* spriteName, int sizeX, int sizeY, int positionX,
               int positionY) {
  const char* defaultPath = "../assets/";
  char* path = new char[strlen(defaultPath) + strlen(spriteName)];
  path = strcat(path, defaultPath);
  path = strcat(path, spriteName);
  spriteSurface = new Surface(path);

  transform = new Transform(sizeX, sizeY, positionX, positionY);
}

Entity::~Entity() {}

void Entity::OnLoad() { spriteSurface->OnLoad(transform); }

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

}  // namespace sg::gamelogic
