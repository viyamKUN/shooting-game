#ifndef __GAME_START_UI_H_
#define __GAME_START_UI_H_

#include "shooting-game/core/entity_registry.h"
#include "shooting-game/play/ui/text/text_ui.h"

namespace sg {
namespace play {
namespace ui {
class GameStartUi : public core::entity::Entity {
 public:
  GameStartUi();
  ~GameStartUi();
};
}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
