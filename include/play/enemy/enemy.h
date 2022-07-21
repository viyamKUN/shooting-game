#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "gamelogic/config.h"
#include "gamelogic/entity.h"
#include "play/bullet.h"
#include "play/game_settings.h"

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
