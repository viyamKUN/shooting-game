#include "play/player.h"

namespace sg {
namespace gamelogic {
namespace play {

Player::Player(int screenWidth, int screenHeight)
    : Entity("player.bmp", 32, 32, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 80) {}

Player::~Player() {}

void Player::OnLoop() { Entity::OnLoop(); }

void Player::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  switch (key) {
    case SDLK_LEFT:
      transform->Translate(-1, 0);
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_WALK);
      break;

    case SDLK_RIGHT:
      transform->Translate(1, 0);
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_WALK);
      break;
  }
}

void Player::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  switch (key) {
    case SDLK_LEFT:
    case SDLK_RIGHT:
      spriteRenderer->ChangeAnimationState(PLAYER_ANIMATION_IDLE);
      break;
  }
}

void Player::OnCleanUp() { Entity::OnCleanUp(); }

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
