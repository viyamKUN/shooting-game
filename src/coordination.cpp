#include "coordination.h"

namespace sg::gamelogic {

Coordination::Coordination(int x, int y) {
  this->x = x;
  this->y = y;
}

Coordination::~Coordination() {}

int Coordination::getX() { return x; }

int Coordination::getY() { return y; }

}  // namespace sg::gamelogic
