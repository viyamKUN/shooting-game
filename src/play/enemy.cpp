#include "play/enemy.h"

namespace sg {
namespace gamelogic {
namespace play {

Enemy::Enemy(const char* spriteName, int sizeX, int sizeY, int posX, int posY)
    : Entity(spriteName, sizeX, sizeY, posX, posY) {}

Enemy::~Enemy() {}

void Enemy::OnLoop() {}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
