#ifndef __GAME_START_UI_H_
#define __GAME_START_UI_H_

#include "shooting-game/gamelogic/entity_registry.h"

namespace sg {
namespace play {
namespace ui {
class GameStartUi : public gamelogic::Entity {
 public:
  GameStartUi();
  ~GameStartUi();

  void OnKeyDown(SDL_Keycode key, Uint16 mod);
};
}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
