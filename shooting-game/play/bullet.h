#ifndef __BULLET_H_
#define __BULLET_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity.h"
#include "shooting-game/play/game_settings.h"

namespace sg {
namespace play {
class Bullet : public core::Entity {
 public:
  Bullet();
  ~Bullet();

  Entity* Clone();
  void ResetData(int posX, int posY, int speed, FACTION faction);
  void OnLoop();
  FACTION GetFaction();

 protected:
  void OnCollisionDetect(Entity* target);

 private:
  static const int WIDTH = 16;
  static const int HEIGHT = 16;
  int speed;
  FACTION bulletFaction;
};

}  // namespace play
}  // namespace sg

#endif
