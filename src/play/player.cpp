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
      break;

    case SDLK_RIGHT:
      transform->Translate(1, 0);
      break;
  }
}

void Player::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  switch (key) {
    case SDLK_LEFT:
    case SDLK_RIGHT:
      // return to idle animation
      break;
  }
}

void Player::SetAnimation(int animationType, int maxFrame) {
  Entity::SetAnimation(animationType, maxFrame);
  // state별로 y 인덱스를 매핑
}

void Player::OnCleanUp() { Entity::OnCleanUp(); }

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
