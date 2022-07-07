#include "transform.h"

namespace sg {
namespace gamelogic {

Transform::Transform() { Transform(100, 100, 0, 0); }

Transform::Transform(int sizeX, int sizeY) { Transform(sizeX, sizeY, 0, 0); }

Transform::Transform(int sizeX, int sizeY, int posX, int posY) {
  size = new Coordination(sizeX, sizeY);
  position = new Coordination(posX, posY);
  scale = new Coordination(1, 1);  // Init scale
}

Transform::~Transform() {}

Coordination* Transform::GetSize() { return size; }

Coordination* Transform::GetPosition() { return position; }

Coordination* Transform::GetScale() { return scale; }

void Transform::Translate(int x, int y) {
  position->setX(position->getX() + x);
  position->setY(position->getY() + y);
}

void Transform::SetScale(int x, int y) {
  scale->setX(x);
  scale->setY(y);
}

}  // namespace gamelogic
}  // namespace sg
