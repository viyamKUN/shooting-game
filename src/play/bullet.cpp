#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

Bullet::Bullet(int speed) : Entity("bullets.bmp", 16, 16, 0, 0), speed(speed) {
  srand(time(NULL));
  int x = rand() % 4;
  CutSprite(x * 16, 0);
}

Bullet::~Bullet() {}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
