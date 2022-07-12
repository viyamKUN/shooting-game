#include "play/player.h"

#include "game.h"

namespace sg {
namespace gamelogic {
namespace play {

Player::Player()
    : Entity("player.bmp", 32, 32, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 80),
      shootingTimeBucket(0) {
  SetAnimation();
}

Player::~Player() {}

void Player::OnLoop() { Entity::OnLoop(); }

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
  switch (key) {
    case SDLK_LEFT:
      transform->Translate(-1 * playerSpeed, 0);
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_WALK);
      spriteRenderer->Flip(SDL_FLIP_NONE);
      break;

    case SDLK_RIGHT:
      transform->Translate(1 * playerSpeed, 0);
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_WALK);
      spriteRenderer->Flip(SDL_FLIP_HORIZONTAL);
      break;

    case SDLK_SPACE:
      if (shootingTimeBucket + shootingInterval <= SDL_GetTicks()) {
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
  play::Bullet* bullet =
      new play::Bullet(transform->GetPosition()->getX(),
                       transform->GetPosition()->getY(), bulletSpeed);
  Game::GetInstance()->RegisterEntity(bullet);
}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
