#include "play/enemy.h"

namespace sg {
namespace gamelogic {
namespace play {

Enemy::Enemy(int posX, int posY)
    : Entity("box.bmp", WIDTH, HEIGHT, posX, posY) {
  SetCollider(WIDTH, HEIGHT);
  SetTag("enemy");
}

Enemy::~Enemy() {}

void Enemy::OnLoop() {
  // TODO
  // Auto Moving
  // Auto Shooting
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
