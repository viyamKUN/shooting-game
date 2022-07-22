#include "shooting-game/play/bullet.h"

namespace sg {
namespace play {

Bullet::Bullet() : Entity("bullets.bmp", WIDTH, HEIGHT, 0, 0), speed(0) {
  SetCollider(WIDTH, HEIGHT);
  srand(time(NULL));
  int x = rand() % 4;
  CutSprite(x * WIDTH, 0);
  SetTag(BULLET);
}

Bullet::~Bullet() {}

core::Entity* Bullet::Clone() { return new Bullet(); }

void Bullet::ResetData(int posX, int posY, int speed, FACTION faction) {
  transform->SetPosition(posX, posY);

  this->speed = speed;

  bulletFaction = faction;
  SetIsActive(true);
}

void Bullet::OnLoop() {
  auto moveSide = bulletFaction == FACTION_PLAYER ? -1 : 1;
  transform->Translate(0, moveSide * speed);
  collider->UpdatePos(transform);

  if (transform->GetPosition()->getY() < 0 ||
      transform->GetPosition()->getY() > SCREEN_HEIGHT) {
    SetIsActive(false);
  }
}

FACTION Bullet::GetFaction() { return bulletFaction; }

void Bullet::OnCollisionDetect(Entity* target) {
  auto targetTag = bulletFaction == FACTION_PLAYER ? ENEMY : PLAYER;
  if (target->CompareTag(targetTag)) SetIsActive(false);
}

}  // namespace play
}  // namespace sg
