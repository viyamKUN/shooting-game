#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

Bullet::Bullet(int speed) : Entity("bullets.bmp", 16, 16, 0, 0), speed(speed) {}

Bullet::~Bullet() {}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
