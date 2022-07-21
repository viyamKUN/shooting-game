#include "play/enemy/enemy.h"

#include "gamelogic/game.h"
#include "play/service_provider.h"

namespace sg {
namespace play {

Enemy::Enemy() : Enemy(0, 0) {}

Enemy::Enemy(int posX, int posY)
    : Entity("box.bmp", WIDTH, HEIGHT, posX, posY), MY_SCORE(5) {
  SetCollider(WIDTH, HEIGHT);
  SetTag(ENEMY);
  shootingTimeBucket = SDL_GetTicks();
}

Enemy::~Enemy() {}

gamelogic::Entity* Enemy::Clone() { return new Enemy(); }

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
  transform->SetPosition(xPos, yPos);
}

void Enemy::OnCollisionDetect(Entity* target) {
  if (target->CompareTag(BULLET)) {
    if (((Bullet*)target)->GetFaction() == FACTION_PLAYER) {
      Hit();
    }
  }
}

void Enemy::Hit() {
  hp--;
  ServiceProvider::GetInstance()->GetBloodPool()->CallBloodAnim(
      transform->GetPosition()->getX(), transform->GetPosition()->getY());
  if (hp <= 0) Die();
}

void Enemy::Die() {
  ServiceProvider::GetInstance()->GetPlayManager()->AddScore(MY_SCORE);
  SetIsActive(false);
}

void Enemy::Shoot() {
  ServiceProvider::GetInstance()->GetBulletPool()->SpawnBullet(
      transform->GetPosition()->getX(), transform->GetPosition()->getY(),
      BULLET_SPEED, FACTION_ENEMY);
}
}  // namespace play
}  // namespace sg
