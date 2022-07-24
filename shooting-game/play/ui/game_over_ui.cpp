#include "shooting-game/play/ui/game_over_ui.h"

// #include "shooting-game/play/play_manager.h"

namespace sg {
namespace play {
namespace ui {

GameOverUi::GameOverUi() : Entity("black.bmp", 16, 16, 0, 0) {}

GameOverUi::~GameOverUi() {}

void GameOverUi::Init() {
  transform->SetScale(SCREEN_WIDTH, SCREEN_HEIGHT);
  core::EntityRegistry::GetInstance()->RegistEntity(this);
  titleTextUi = new TextUi();
  titleTextUi->UpdatePos(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4);
  titleTextUi->UpdateText("PLAYER DIE");
}

void GameOverUi::Close() {
  titleTextUi->Close();
  SetIsActive(false);
}

void GameOverUi::Open() {
  titleTextUi->Open();
  SetIsActive(true);
}

void GameOverUi::UpdateScore(int score) {
  // By Number UI
}

}  // namespace ui
}  // namespace play
}  // namespace sg
