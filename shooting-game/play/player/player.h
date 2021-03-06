#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity/entity.h"
#include "shooting-game/core/entity_registry.h"
#include "shooting-game/play/game_settings.h"
#include "shooting-game/play/player/player_walk_effect.h"
#include "shooting-game/play/service_provider.h"

namespace sg {
namespace play {

class Player : public core::entity::Entity {
 public:
  Player(std::function<void()> gameOverEvent);
  ~Player();

  void ResetData();
  void OnLoop();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnKey(SDL_Keycode key);

 private:
  const int BULLET_SPEED = 5;
  const int PLAYER_SPEED = 3;
  const int SHOOTING_INTERVAL = 500;  // milliseconds
  const int INVINCIBLE_TIME = 500;

  int hp;
  bool isDead;
  bool isInvincible;
  int shootingTimeBucket;
  int invincibleTimeBucket;
  std::function<void()> gameOverEvent;

  enum PLAYER_ANIMATIONS {
    PLAYER_ANIMATION_IDLE = 0,
    PLAYER_ANIMATION_WALK = 1
  };

  void SetAnimation();
  void Shoot();
  void OnCollisionDetect(core::entity::Entity* target);
  void Hit();
  void Die();
  // When player hit by enemy, player will be invincible for short time.
  void BeTemporaryInvincible();

  PlayerWalkEffect* walkEffect;
};

}  // namespace play
}  // namespace sg

#endif
