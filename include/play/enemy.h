#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
class Enemy : public Entity {
 public:
  Enemy(int posX, int posY);
  ~Enemy();
  void OnLoop();

 private:
  static const int WIDTH = 32;
  static const int HEIGHT = 32;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
