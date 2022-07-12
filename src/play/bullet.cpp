#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

Bullet::Bullet(int posX, int posY, int speed)
    : Entity("bullets.bmp", WIDTH, HEIGHT, posX, posY), SPEED(speed) {
  srand(time(NULL));
  int x = rand() % 4;
  CutSprite(x * WIDTH, 0);
  SetCollider(WIDTH, HEIGHT);
  SetTag(BULLET);
}

Bullet::~Bullet() {}

void Bullet::OnLoop() {
  transform->Translate(0, -1 * SPEED);
  collider->UpdatePos(transform);
  if (transform->GetPosition()->getY() < 0) {
    Entity::Destroy();
  }
}

void Bullet::OnCollisionDetect(Entity* target) {
  if (target->CompareTag(ENEMY)) Entity::Destroy();
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
