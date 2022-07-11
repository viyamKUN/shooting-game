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

Entity::~Entity() {
  delete spriteRenderer;
  delete transform;
}

void Entity::SetAnimation() { spriteRenderer->InitAnimation(); }

void Entity::CutSprite(int posX, int posY) {
  spriteRenderer->CutSurface(posX, posY);
}

void Entity::OnLoad() { spriteRenderer->OnLoad(transform); }

void Entity::OnLoop() {
  spriteRenderer->OnLoop();
  // virtual method
}

void Entity::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  // virtual method
}

void Entity::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  // virtual method
}

void Entity::OnKey(SDL_Keycode key) {
  // virtual method
}

void Entity::OnRender(SDL_Renderer* renderer) {
  spriteRenderer->OnDraw(renderer);
}

void Entity::Destroy() {
  // TODO: implement
}

void Entity::OnCleanUp() {
  if (spriteRenderer) {
    spriteRenderer->OnClear();
  }
}

}  // namespace gamelogic
}  // namespace sg
