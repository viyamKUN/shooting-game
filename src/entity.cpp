#include "entity.h"

namespace sg::gamelogic {
Entity::Entity(const char* spriteName, int sizeX, int sizeY, int posX,
               int posY) {
  const char* defaultPath = "../assets/";
  char* path = new char[strlen(defaultPath) + strlen(spriteName)];
  path = strcat(path, defaultPath);
  path = strcat(path, spriteName);
  spriteSurface = new Surface(path);

  transform = new Transform(sizeX, sizeY, posX, posY);
  animation = NULL;
}

Entity::~Entity() {}

void Entity::SetAnimation(int animationType, int maxFrame) {
  if (animationType == ANIMATION_NONE) return;
  animation = new Animation(maxFrame, animationType);
}

void Entity::OnLoad() { spriteSurface->OnLoad(transform); }

void Entity::OnLoop() {
  if (animation) animation->OnAnimate();
}

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
