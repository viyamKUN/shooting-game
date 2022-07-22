#include "shooting-game/play/ui/game_over_ui.h"

// #include "shooting-game/play/play_manager.h"

namespace sg {
namespace play {
namespace ui {

GameOverUi::GameOverUi() : Entity("black.bmp", 16, 16, 0, 0) {
  transform->SetScale(SCREEN_WIDTH, SCREEN_HEIGHT);
  gamelogic::EntityRegistry::GetInstance()->RegistEntity(this);
}

GameOverUi::~GameOverUi() {}

}  // namespace ui
}  // namespace play
}  // namespace sg
