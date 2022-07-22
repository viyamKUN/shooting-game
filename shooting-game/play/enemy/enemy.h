#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "shooting-game/gamelogic/config.h"
#include "shooting-game/gamelogic/entity.h"
#include "shooting-game/play/bullet.h"
#include "shooting-game/play/game_settings.h"

namespace sg {
namespace play {
class Enemy : public gamelogic::Entity {
 public:
  Enemy();
  Enemy(int posX, int posY);
  ~Enemy();
  Entity* Clone();

  void OnLoop();
  void ResetData(int xPos, int yPos);

 protected:
  void OnCollisionDetect(Entity* target);

 private:
  static const int WIDTH = 32;
  static const int HEIGHT = 32;
  static const int BULLET_SPEED = 4;
  static const int SHOOTING_INTERVAL = 1000;
  const int MY_SCORE;
  const int MAX_HP = 3;
  int hp;
  int shootingTimeBucket;

  void Hit();
  void Die();
  void Shoot();
};

}  // namespace play
}  // namespace sg

#endif