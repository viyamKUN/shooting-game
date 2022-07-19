#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "config.h"
#include "entity.h"
#include "play/bullet.h"
#include "play/bullet_pool.h"
#include "play/game_settings.h"

namespace sg {
namespace gamelogic {
namespace play {

class Player : public Entity {
 public:
  Player();
  ~Player();

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
  enum PLAYER_ANIMATIONS {
    PLAYER_ANIMATION_IDLE = 0,
    PLAYER_ANIMATION_WALK = 1
  };

  void SetAnimation();
  void Shoot();
  void OnCollisionDetect(Entity* target);
  void Hit();
  void Die();
  // When player hit by enemy, player will be invincible for short time.
  void BeTemporaryInvincible();
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
