#include "collider.h"

namespace sg {
namespace gamelogic {

Collider::Collider(int sizeX, int sizeY, Transform* transform) {
  collider = new SDL_Rect();
  collider->w = sizeX;
  collider->h = sizeY;
  collider->x = transform->GetPosition()->getX();
  collider->y = transform->GetPosition()->getY();
}

Collider::~Collider() {}

void Collider::UpdatePos(Transform* transform) {
  collider->x = transform->GetPosition()->getX();
  collider->y = transform->GetPosition()->getY();
}

SDL_bool Collider::HasIntersection(Collider* target) {
  return SDL_HasIntersection(collider, target->GetCollider());
}

SDL_Rect* Collider::GetCollider() { return collider; }

}  // namespace gamelogic
}  // namespace sg
