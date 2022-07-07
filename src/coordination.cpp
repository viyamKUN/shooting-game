#include "coordination.h"

namespace sg {
namespace gamelogic {
Coordination::Coordination(int x, int y) {
  this->x = x;
  this->y = y;
}

Coordination::~Coordination() {}

int Coordination::getX() { return x; }

int Coordination::getY() { return y; }

void Coordination::setX(int x) { this->x = x; }

void Coordination::setY(int y) { this->y = y; }

}  // namespace gamelogic
}  // namespace sg
