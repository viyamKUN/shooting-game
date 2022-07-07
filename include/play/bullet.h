#ifndef __BULLET_H_
#define __BULLET_H_

#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
class Bullet : public Entity {
 public:
  Bullet(int speed);
  ~Bullet();

 private:
  const int speed;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
