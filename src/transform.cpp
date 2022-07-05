#include "transform.h"

namespace sg::gamelogic {

Transform::Transform() { Transform(100, 100, 0, 0); }

Transform::Transform(int sizeX, int sizeY) { Transform(sizeX, sizeY, 0, 0); }

Transform::Transform(int sizeX, int sizeY, int posX, int posY) {
  size = new Coordination(sizeX, sizeY);
  position = new Coordination(posX, posY);
}

Transform::~Transform() {}

Coordination* Transform::GetSize() { return size; }

Coordination* Transform::GetPosition() { return position; }

}  // namespace sg::gamelogic
