#ifndef __BULLET_H_
#define __BULLET_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity/entity.h"
#include "shooting-game/play/game_settings.h"

namespace sg {
namespace play {
class Bullet : public core::entity::Entity {
 public:
  Bullet();
  ~Bullet();

  core::entity::Entity* Clone();
  void ResetData(int posX, int posY, int speed, FACTION faction);
  void OnLoop();
  FACTION GetFaction();

 protected:
  void OnCollisionDetect(core::entity::Entity* target);

 private:
  static const int WIDTH = 16;
  static const int HEIGHT = 16;
  int speed;
  FACTION bulletFaction;
};

}  // namespace play
}  // namespace sg

#endif
