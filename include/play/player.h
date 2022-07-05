#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {

class Player : public Entity {
 public:
  Player(int screenWidth, int screenHeight);
  ~Player();

 public:
  void OnLoop();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnCleanUp();
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
