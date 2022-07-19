#include "play/player.h"

#include "game.h"

namespace sg {
namespace gamelogic {
namespace play {

Player::Player()
    : Entity("player.bmp", 32, 32, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 80),
      shootingTimeBucket(0),
      hp(MAX_HP),
      isDead(false),
      isInvincible(false) {
  SetAnimation();
  SetTag(PLAYER);
  SetCollider(32, 32);
}

Player::~Player() {}

void Player::OnLoop() {
  Entity::OnLoop();
  if (isInvincible) {
    if (SDL_GetTicks() > invincibleTimeBucket + INVINCIBLE_TIME) {
      // invincible is over.
      isInvincible = false;
    }
  }
}

void Player::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  switch (key) {}
}

void Player::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  switch (key) {
    case SDLK_LEFT:
    case SDLK_RIGHT:
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_IDLE);
      break;
  }
}

void Player::OnKey(SDL_Keycode key) {
  if (isDead) return;
  switch (key) {
    case SDLK_LEFT:
      transform->Translate(-1 * PLAYER_SPEED, 0);
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_WALK);
      spriteRenderer->Flip(SDL_FLIP_NONE);
      break;

    case SDLK_RIGHT:
      transform->Translate(1 * PLAYER_SPEED, 0);
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_WALK);
      spriteRenderer->Flip(SDL_FLIP_HORIZONTAL);
      break;

    case SDLK_SPACE:
      if (shootingTimeBucket + SHOOTING_INTERVAL <= SDL_GetTicks()) {
        shootingTimeBucket = SDL_GetTicks();
        Shoot();
      }
      break;
  }
}

void Player::SetAnimation() {
  Entity::SetAnimation();
  spriteRenderer->AddAnimation(PLAYER_ANIMATION_IDLE, ANIMATION_RESTART, 4);
  spriteRenderer->AddAnimation(PLAYER_ANIMATION_WALK, ANIMATION_RESTART, 5);
}

void Player::Shoot() {
  play::Bullet* bullet = new play::Bullet(transform->GetPosition()->getX(),
                                          transform->GetPosition()->getY(),
                                          BULLET_SPEED, FACTION_PLAYER);
  Game::GetInstance()->RegisterEntity(bullet);
}

void Player::OnCollisionDetect(Entity* target) {
  if (isDead) return;
  if (target->CompareTag(ENEMY) || target->CompareTag(ENEMY_BULLET)) {
    if (!isInvincible) Hit();
  }
}

void Player::Hit() {
  hp--;
  isInvincible = true;
  invincibleTimeBucket = SDL_GetTicks();
  if (hp <= 0) Die();
}

void Player::Die() {
  isDead = true;
  std::cout << "Player Die!" << std::endl;
  Entity::SetActiveCollider(false);

  // TODO: implement
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
