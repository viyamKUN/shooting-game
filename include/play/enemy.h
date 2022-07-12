#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "entity.h"
#include "play/tags.h"

namespace sg {
namespace gamelogic {
namespace play {
class Enemy : public Entity {
 public:
  Enemy(int posX, int posY);
  ~Enemy();
  void OnLoop();

 protected:
  void OnCollisionDetect(Entity* target);

 private:
  static const int WIDTH = 32;
  static const int HEIGHT = 32;
  const int MAX_HP = 3;
  int hp;

  void Hit();
  void Die();
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
