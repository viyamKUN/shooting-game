#include "collider.h"

namespace sg {
namespace gamelogic {

Collider::Collider(int sizeX, int sizeY, int posX, int posY) {
  collider = new SDL_Rect();
  collider->w = sizeX;
  collider->h = sizeY;
  collider->x = posX;
  collider->y = posY;
}

Collider::~Collider() {}

void Collider::UpdatePos(int posX, int posY) {
  collider->x = posX;
  collider->y = posY;
}

SDL_bool Collider::HasIntersection(Collider* target) {
  return SDL_HasIntersection(collider, target->GetCollider());
}

SDL_Rect* Collider::GetCollider() { return collider; }

}  // namespace gamelogic
}  // namespace sg
