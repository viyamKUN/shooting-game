#include "shooting-game/core/entity/collider.h"

namespace sg {
namespace core {
namespace entity {

Collider::Collider(int sizeX, int sizeY, Transform* transform) {
  collider = new SDL_Rect();
  collider->w = sizeX * transform->GetScale()->getX();
  collider->h = sizeY * transform->GetScale()->getY();
  collider->x = transform->GetPosition()->getX();
  collider->y = transform->GetPosition()->getY();
  isActive = true;
}

Collider::~Collider() {
  if (collider) delete collider;
}

void Collider::UpdatePos(Transform* transform) {
  collider->x = transform->GetPosition()->getX();
  collider->y = transform->GetPosition()->getY();
}

SDL_bool Collider::HasIntersection(Collider* target) {
  return SDL_HasIntersection(collider, target->GetCollider());
}

SDL_Rect* Collider::GetCollider() { return collider; }

void Collider::SetActive(bool isOn) { isActive = isOn; }

bool Collider::GetActive() { return isActive; }

}  // namespace entity
}  // namespace core
}  // namespace sg
