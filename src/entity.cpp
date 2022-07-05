#include "entity.h"

namespace sg::gamelogic {
Entity::Entity(const char* spriteName, int sizeX, int sizeY, int posX,
               int posY) {
  const char* defaultPath = "../assets/";
  char* path = new char[strlen(defaultPath) + strlen(spriteName)];
  path = strcat(path, defaultPath);
  path = strcat(path, spriteName);
  spriteRenderer = new Surface(path);

  transform = new Transform(sizeX, sizeY, posX, posY);
}

Entity::~Entity() {}

void Entity::SetAnimation(int animationType, int maxFrame) {
  spriteRenderer->SetAnimation(animationType, maxFrame);
}

void Entity::OnLoad() { spriteRenderer->OnLoad(transform); }

void Entity::OnLoop() { spriteRenderer->OnLoop(); }

void Entity::OnRender(SDL_Renderer* renderer) {
  spriteRenderer->OnDraw(renderer);
}

void Entity::OnCleanUp() {
  if (spriteRenderer) {
    spriteRenderer->OnClear();
  }
  spriteRenderer = NULL;
}

}  // namespace sg::gamelogic
