#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

Bullet::Bullet(int posX, int posY, int speed)
    : Entity("bullets.bmp", 16, 16, posX, posY), speed(speed) {
  srand(time(NULL));
  int x = rand() % 4;
  CutSprite(x * 16, 0);
  SetCollider(16, 16, posX, posY);
}

Bullet::~Bullet() {}

void Bullet::OnLoop() {
  transform->Translate(0, -1 * speed);
  collider->UpdatePos(transform->GetPosition()->getX(),
                      transform->GetPosition()->getY());
  if (transform->GetPosition()->getY() < 0) {
    Entity::Destroy();
  }
}

void Bullet::OnCleanUp() { Entity::OnCleanUp(); }

void Bullet::OnCollisionDetect(Entity* target) {
  std::cout << "Bullet shoot something. TAG is box: ["
            << target->CompareTag("box") << "]" << std::endl;
  Entity::Destroy();
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
