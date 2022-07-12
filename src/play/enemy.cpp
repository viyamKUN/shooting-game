#include "play/enemy.h"

namespace sg {
namespace gamelogic {
namespace play {

Enemy::Enemy() : Enemy(0, 0) {}

Enemy::Enemy(int posX, int posY)
    : Entity("box.bmp", WIDTH, HEIGHT, posX, posY) {
  SetCollider(WIDTH, HEIGHT);
  SetTag(ENEMY);
  hp = MAX_HP;
}

Enemy::~Enemy() {}

void Enemy::OnLoop() {
  // TODO: Auto Shooting
  transform->Translate(0, 1);
  collider->UpdatePos(transform);
}

void Enemy::OnCollisionDetect(Entity* target) {
  if (target->CompareTag(BULLET)) Hit();
}

void Enemy::Hit() {
  hp--;
  if (hp <= 0) Die();
}

void Enemy::Die() { Destroy(); }

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
