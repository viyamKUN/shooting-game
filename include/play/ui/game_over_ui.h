#ifndef __GAME_OVER_UI_H_
#define __GAME_OVER_UI_H_

#include "gamelogic/config.h"
#include "gamelogic/entity.h"

namespace sg {
namespace play {
namespace ui {
class GameOverUi : public gamelogic::Entity {
 public:
  GameOverUi();
  ~GameOverUi();

  void OnKeyDown(SDL_Keycode key, Uint16 mod);
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
