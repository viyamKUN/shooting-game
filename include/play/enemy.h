#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
class Enemy : public Entity {
 public:
  Enemy(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Enemy();
  void OnLoop();
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
