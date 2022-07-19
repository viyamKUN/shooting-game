#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

Bullet::Bullet(int posX, int posY, int speed, FACTION faction)
    : Entity("bullets.bmp", WIDTH, HEIGHT, posX, posY), SPEED(speed) {
  srand(time(NULL));
  int x = rand() % 4;
  CutSprite(x * WIDTH, 0);
  SetCollider(WIDTH, HEIGHT);

  auto tag = faction == FACTION_PLAYER ? PLAYER_BULLET : ENEMY_BULLET;
  SetTag(tag);
  bulletFaction = faction;
}

Bullet::~Bullet() {}

void Bullet::OnLoop() {
  auto moveSide = bulletFaction == FACTION_PLAYER ? -1 : 1;
  transform->Translate(0, moveSide * SPEED);
  collider->UpdatePos(transform);

  if (transform->GetPosition()->getY() < 0) {
    Entity::Destroy();
  }
}

void Bullet::OnCollisionDetect(Entity* target) {
  auto targetTag = bulletFaction == FACTION_PLAYER ? ENEMY : PLAYER;
  if (target->CompareTag(targetTag)) Entity::Destroy();
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
