#ifndef __GAME_OVER_UI_H_
#define __GAME_OVER_UI_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity_registry.h"

namespace sg {
namespace play {
namespace ui {
class GameOverUi : public core::Entity {
 public:
  GameOverUi();
  ~GameOverUi();
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
