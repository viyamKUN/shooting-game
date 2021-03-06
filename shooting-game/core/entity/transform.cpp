#include "shooting-game/core/entity/transform.h"

namespace sg {
namespace core {
namespace entity {

Transform::Transform() { Transform(0, 0); }

Transform::Transform(int posX, int posY) {
  position = new Coordination(posX, posY);
  scale = new Coordination(1, 1);  // Init scale
}

Transform::~Transform() {
  delete position;
  delete scale;
}

Coordination* Transform::GetPosition() { return position; }

Coordination* Transform::GetScale() { return scale; }

void Transform::Translate(int x, int y) {
  position->setX(position->getX() + x);
  position->setY(position->getY() + y);
}

void Transform::SetPosition(int x, int y) {
  position->setX(x);
  position->setY(y);
}

void Transform::SetScale(int x, int y) {
  scale->setX(x);
  scale->setY(y);
}

}  // namespace entity
}  // namespace core
}  // namespace sg
