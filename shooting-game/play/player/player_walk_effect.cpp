#include "shooting-game/play/player/player_walk_effect.h"

namespace sg {
namespace play {

PlayerWalkEffect::PlayerWalkEffect()
    : Entity("effects/walk.bmp", SIZE, SIZE, 0, 0) {
  SetAnimation();
}

PlayerWalkEffect::~PlayerWalkEffect() {}

void PlayerWalkEffect::PlayWalkAnim() {
  if (GetIsActive()) return;

  SetIsActive(true);
  spriteRenderer->ResetAnimation();
}

void PlayerWalkEffect::StopWalkAnim() { SetIsActive(false); }

void PlayerWalkEffect::SetPosition(int x, int y, SIDE moveSide) {
  switch (moveSide) {
    case LEFT:
      spriteRenderer->Flip(SDL_FLIP_HORIZONTAL);
      transform->SetPosition(x + MARGIN_FROM_PLAYER, y);
      break;

    case RIGHT:
      spriteRenderer->Flip(SDL_FLIP_NONE);
      transform->SetPosition(x - MARGIN_FROM_PLAYER, y);
      break;

    default:
      break;
  }
}

void PlayerWalkEffect::SetAnimation() {
  Entity::SetAnimation();
  spriteRenderer->AddAnimation(0, core::entity::visual::ANIMATION_RESTART, 5);
}

}  // namespace play
}  // namespace sg
