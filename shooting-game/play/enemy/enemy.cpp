#include "shooting-game/play/enemy/enemy.h"

namespace sg {
namespace play {

Enemy::Enemy(int posX, int posY)
    : Entity("enemy.bmp", WIDTH, HEIGHT, posX, posY), MY_SCORE(5) {
  SetAnimation();
  SetCollider(WIDTH, HEIGHT);
  SetTag(ENEMY);
  shootingTimeBucket = SDL_GetTicks();
}

Enemy::~Enemy() {}

core::entity::Entity* Enemy::Clone() {
  return new Enemy(transform->GetPosition()->getX(),
                   transform->GetPosition()->getY());
}

void Enemy::OnLoop() {
  Entity::OnLoop();
  if (hp <= 0) return;

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
  spriteRenderer->ChangeAnimationState(ENEMY_ANIMATION_WALK);
  spriteRenderer->ResetAnimation();
}

void Enemy::OnCollisionDetect(core::entity::Entity* target) {
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
  ServiceProvider::GetInstance()->AddScore(MY_SCORE);
  spriteRenderer->ChangeAnimationState(ENEMY_ANIMATION_DEAD);
}

void Enemy::Shoot() {
  ServiceProvider::GetInstance()->GetBulletPool()->SpawnBullet(
      transform->GetPosition()->getX(), transform->GetPosition()->getY(),
      BULLET_SPEED, FACTION_ENEMY);
}

void Enemy::SetAnimation() {
  Entity::SetAnimation();
  spriteRenderer->AddAnimation(ENEMY_ANIMATION_WALK,
                               core::entity::visual::ANIMATION_RESTART, 5);
  spriteRenderer->AddAnimation(ENEMY_ANIMATION_DEAD,
                               core::entity::visual::ANIMATION_ONETIME, 7);
}

}  // namespace play
}  // namespace sg
