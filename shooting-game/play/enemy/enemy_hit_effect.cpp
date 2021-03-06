#include "shooting-game/play/enemy/enemy_hit_effect.h"

namespace sg {
namespace play {
namespace enemy {

EnemyHitEffect::EnemyHitEffect()
    : Entity("effects/blood.bmp", SIZE, SIZE, 0, 0) {
  SetAnimation();
}

EnemyHitEffect::~EnemyHitEffect() {}

core::entity::Entity* EnemyHitEffect::Clone() { return new EnemyHitEffect(); }

void EnemyHitEffect::SetPosition(int x, int y) { transform->SetPosition(x, y); }

void EnemyHitEffect::ResetData() { spriteRenderer->ResetAnimation(); }

void EnemyHitEffect::SetAnimation() {
  Entity::SetAnimation();
  spriteRenderer->AddAnimation(0, core::entity::visual::ANIMATION_ONETIME, 5);
}

}  // namespace enemy
}  // namespace play
}  // namespace sg
