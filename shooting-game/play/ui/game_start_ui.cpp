#include "shooting-game/play/ui/game_start_ui.h"

namespace sg {
namespace play {
namespace ui {

GameStartUi::GameStartUi() : Entity() {
  SDL_Log("[Return] Start game.");
  gamelogic::EntityRegistry::GetInstance()->RegistEntity(this);
}

GameStartUi::~GameStartUi() {}

}  // namespace ui
}  // namespace play
}  // namespace sg
