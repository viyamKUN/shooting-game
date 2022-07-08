#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

Bullet::Bullet(int posX, int posY, int speed)
    : Entity("bullets.bmp", 16, 16, posX, posY), speed(speed) {
  srand(time(NULL));
  int x = rand() % 4;
  CutSprite(x * 16, 0);
}

Bullet::~Bullet() {}

void Bullet::OnLoop() {
  transform->Translate(0, -1 * speed);
  if (transform->GetPosition()->getY() < 0) {
    Entity::Destroy();
  }
}

void Bullet::OnCleanUp() { Entity::OnCleanUp(); }

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
