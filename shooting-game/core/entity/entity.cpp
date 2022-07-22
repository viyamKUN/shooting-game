#include "shooting-game/core/entity/entity.h"

namespace sg {
namespace core {
namespace entity {

Entity::Entity() {
  spriteRenderer = NULL;
  transform = NULL;
  collider = NULL;
  isActive = false;
}

Entity::Entity(const char* spriteName, int sizeX, int sizeY, int posX,
               int posY) {
  const char* defaultPath = "./assets/";
  char* path = new char[strlen(defaultPath) + strlen(spriteName)];
  path = strcat(path, defaultPath);
  path = strcat(path, spriteName);
  this->spriteName = spriteName;

  spriteRenderer = new visual::Surface(path, sizeX, sizeY);
  transform = new Transform(posX, posY);
  collider = NULL;
}

Entity::~Entity() {
  if (spriteRenderer) delete spriteRenderer;
  if (transform) delete transform;
  if (collider) delete collider;
}

entity::Entity* Entity::Clone() {
  return new Entity(spriteName, spriteRenderer->GetSize()->getX(),
                    spriteRenderer->GetSize()->getY(),
                    transform->GetPosition()->getX(),
                    transform->GetPosition()->getY());
}

void Entity::SetAnimation() { spriteRenderer->InitAnimation(); }

void Entity::CutSprite(int posX, int posY) {
  spriteRenderer->CutSurface(posX, posY);
}

// Update Tag. Tag is classify for entity.
void Entity::SetTag(const char* tag) { this->tag = tag; }

bool Entity::CompareTag(const char* tag) {
  if (this->tag != NULL && tag != NULL)
    return strcmp(this->tag, tag) == 0;
  else
    return false;
}

// Collider can detect collision.
void Entity::SetCollider(int sizeX, int sizeY) {
  collider = new Collider(sizeX, sizeY, transform);
}

void Entity::SetActiveCollider(bool isOn) { collider->SetActive(isOn); }

Collider* Entity::GetCollider() {
  if (collider == NULL) return NULL;
  if (!collider->GetActive()) return NULL;
  return collider;
}

void Entity::SetIsActive(bool active) { isActive = active; }

bool Entity::GetIsActive() { return isActive; }

void Entity::OnLoad() {
  if (spriteRenderer) {
    spriteRenderer->OnLoad(transform);
  }
}

void Entity::OnLoop() {
  if (spriteRenderer) {
    if (spriteRenderer->IsAnimationOver())
      SetIsActive(false);
    else
      spriteRenderer->OnLoop();
  }
  if (collider) {
    collider->UpdatePos(transform);
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

void Entity::OnCollision(entity::Entity* target) {
  if (collider == NULL) return;
  if (target->GetCollider() == NULL) return;

  if (collider->HasIntersection(target->GetCollider()) == SDL_TRUE) {
    OnCollisionDetect(target);
  }
}

void Entity::OnCollisionDetect(entity::Entity* target) {
  // virtual method
}

void Entity::OnRender(SDL_Renderer* renderer) {
  if (spriteRenderer) {
    spriteRenderer->OnDraw(renderer);
  }
}

void Entity::OnCleanUp() {
  if (spriteRenderer) {
    spriteRenderer->OnClear();
  }
}

}  // namespace entity
}  // namespace core
}  // namespace sg
