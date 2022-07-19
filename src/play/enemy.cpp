#include "play/enemy.h"

#include "game.h"

namespace sg {
namespace gamelogic {
namespace play {

Enemy::Enemy() : Enemy(0, 0) {}

Enemy::Enemy(int posX, int posY)
    : Entity("box.bmp", WIDTH, HEIGHT, posX, posY) {
  SetCollider(WIDTH, HEIGHT);
  SetTag(ENEMY);
  shootingTimeBucket = SDL_GetTicks();
}

Enemy::~Enemy() {}

Entity* Enemy::Clone() { return new Enemy(); }

void Enemy::OnLoop() {
  transform->Translate(0, 1);
  collider->UpdatePos(transform);
  if (transform->GetPosition()->getY() > SCREEN_HEIGHT) {
    Entity::SetIsActive(false);
  }

  if (SDL_GetTicks() > shootingTimeBucket + SHOOTING_INTERVAL) {
    shootingTimeBucket = SDL_GetTicks();
    Shoot();
  }
}

void Enemy::ResetData(int xPos, int yPos) {
  hp = MAX_HP;
  transform->GetPosition()->setX(xPos);
  transform->GetPosition()->setY(yPos);
}

void Enemy::OnCollisionDetect(Entity* target) {
  if (target->CompareTag(PLAYER_BULLET)) Hit();
}

void Enemy::Hit() {
  hp--;
  if (hp <= 0) Die();
}

void Enemy::Die() { SetIsActive(false); }

void Enemy::Shoot() {
  play::Bullet* bullet = new play::Bullet(transform->GetPosition()->getX(),
                                          transform->GetPosition()->getY(),
                                          BULLET_SPEED, FACTION_ENEMY);
  Game::GetInstance()->RegisterEntity(bullet);
}
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
