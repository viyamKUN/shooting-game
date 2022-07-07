#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "config.h"
#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {

class Player : public Entity {
 public:
  Player(int screenWidth, int screenHeight);
  ~Player();

  void OnLoop();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnCleanUp();

 private:
  void SetAnimation();

  enum PLAYER_ANIMATIONS {
    PLAYER_ANIMATION_IDLE = 0,
    PLAYER_ANIMATION_WALK = 1
  };
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
