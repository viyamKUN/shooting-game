#ifndef __BULLET_H_
#define __BULLET_H_

#include "config.h"
#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
class Bullet : public Entity {
 public:
  Bullet(int posX, int posY, int speed);
  ~Bullet();
  void OnLoop();
  void OnCleanUp();

 private:
  const int speed;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
