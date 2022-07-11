#include "entity.h"

#include "game.h"

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
  collider = NULL;
}

Entity::~Entity() {
  delete spriteRenderer;
  delete transform;
}

void Entity::SetAnimation() { spriteRenderer->InitAnimation(); }

void Entity::CutSprite(int posX, int posY) {
  spriteRenderer->CutSurface(posX, posY);
}

// Update Tag. Tag is classify for entity.
void Entity::SetTag(const char* tag) { this->tag = tag; }

bool Entity::CompareTag(const char* tag) {
  if (this->tag != NULL)
    return strcmp(this->tag, tag) == 0;
  else
    return false;
}

// Collider can detect collision.
void Entity::SetCollider(int sizeX, int sizeY, int posX, int posY) {
  collider = new Collider(sizeX, sizeY, posX, posY);
}

Collider* Entity::GetCollider() { return collider; }

void Entity::OnLoad() { spriteRenderer->OnLoad(transform); }

void Entity::OnLoop() {
  spriteRenderer->OnLoop();
  if (collider) {
    collider->UpdatePos(transform->GetPosition()->getX(),
                        transform->GetPosition()->getY());
  }
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

void Entity::OnCollision(Entity* target) {
  if (collider == NULL) return;
  if (target->GetCollider() == NULL) return;

  if (collider->HasIntersection(target->GetCollider()) == SDL_TRUE) {
    OnCollisionDetect(target);
  }
}

void Entity::OnCollisionDetect(Entity* target) {
  // virtual method
}

void Entity::OnRender(SDL_Renderer* renderer) {
  spriteRenderer->OnDraw(renderer);
}

void Entity::Destroy() { Game::GetInstance()->RegisterEntityDestroy(this); }

void Entity::OnCleanUp() {
  if (spriteRenderer) {
    spriteRenderer->OnClear();
  }
}

}  // namespace gamelogic
}  // namespace sg
