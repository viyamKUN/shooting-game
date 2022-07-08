#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "config.h"
#include "entity.h"
#include "play/bullet.h"

namespace sg {
namespace gamelogic {
namespace play {

class Player : public Entity {
 public:
  Player();
  ~Player();

  void OnLoop();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnKey(SDL_Keycode key);
  void OnCleanUp();

 private:
  void SetAnimation();
  void Shoot();

  const int bulletSpeed = 5;
  const int playerSpeed = 3;
  const int shootingInterval = 500;  // milliseconds
  int shootingTimeBucket;
  enum PLAYER_ANIMATIONS {
    PLAYER_ANIMATION_IDLE = 0,
    PLAYER_ANIMATION_WALK = 1
  };
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
