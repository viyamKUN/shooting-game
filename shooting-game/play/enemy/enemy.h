#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity/entity.h"
#include "shooting-game/play/game_settings.h"
#include "shooting-game/play/service_provider.h"

namespace sg {
namespace play {
class Enemy : public core::entity::Entity {
 public:
  Enemy(int posX, int posY);
  ~Enemy();
  core::entity::Entity* Clone();

  void OnLoop();
  void ResetData(int xPos, int yPos);

 protected:
  void OnCollisionDetect(core::entity::Entity* target);

 private:
  static const int WIDTH = 32;
  static const int HEIGHT = 32;
  static const int BULLET_SPEED = 4;
  static const int SHOOTING_INTERVAL = 1000;
  const int MY_SCORE;
  const int MAX_HP = 3;
  int hp;
  int shootingTimeBucket;

  enum ENEMY_ANIMATIONS { ENEMY_ANIMATION_WALK = 0, ENEMY_ANIMATION_DEAD = 1 };

  void Hit();
  void Die();
  void Shoot();
  void SetAnimation();
};

}  // namespace play
}  // namespace sg

#endif
