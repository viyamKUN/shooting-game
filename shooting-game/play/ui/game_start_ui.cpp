#include "shooting-game/play/ui/game_start_ui.h"

namespace sg {
namespace play {
namespace ui {

GameStartUi::GameStartUi() : Entity() {
  core::EntityRegistry::GetInstance()->RegistEntity(this);
}

GameStartUi::~GameStartUi() {}

void GameStartUi::Open() { SetIsActive(true); }

void GameStartUi::Close() {
  textUi->Close();
  SetIsActive(false);
}

void GameStartUi::Init() {
  textUi = new TextUi();
  textUi->UpdatePos(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.8);
  textUi->UpdateText("CLICK RETURN TO START");
  SDL_Log("[Return]: Start game.");
}
}  // namespace ui
}  // namespace play
}  // namespace sg
