#ifndef __BULLET_H_
#define __BULLET_H_

#include "config.h"
#include "entity.h"
#include "play/game_settings.h"

namespace sg {
namespace gamelogic {
namespace play {
class Bullet : public Entity {
 public:
  ~Bullet();
  void OnLoop();

 protected:
  void OnCollisionDetect(Entity* target);

 private:
  const int SPEED;
  static const int WIDTH = 16;
  static const int HEIGHT = 16;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
