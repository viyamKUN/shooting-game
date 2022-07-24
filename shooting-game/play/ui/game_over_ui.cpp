#include "shooting-game/play/ui/game_over_ui.h"

// #include "shooting-game/play/play_manager.h"

namespace sg {
namespace play {
namespace ui {

GameOverUi::GameOverUi() : Entity("brown_1px.bmp", 16, 16, 0, 0) {}

GameOverUi::~GameOverUi() {}

void GameOverUi::Init() {
  transform->SetScale(SCREEN_WIDTH, SCREEN_HEIGHT);
  core::EntityRegistry::GetInstance()->RegistEntity(this);

  titleTextUi = new TextUi();
  titleTextUi->UpdatePos(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4);
  titleTextUi->UpdateText("PLAYER DIE");

  descTextUi = new TextUi();
  descTextUi->UpdatePos(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.6);
  descTextUi->UpdateText("RESTART BY RETURN   QUIT BY ESCAPE");

  scoreUi = new TextUi();
  scoreUi->UpdatePos(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.8);
}

void GameOverUi::Close() {
  titleTextUi->Close();
  descTextUi->Close();
  scoreUi->Close();
  SetIsActive(false);
}

void GameOverUi::Open() {
  titleTextUi->Open();
  descTextUi->Open();
  scoreUi->Open();
  SetIsActive(true);
}

void GameOverUi::UpdateScore(int score) {
  scoreUi->UpdateText(std::to_string(score));
}

}  // namespace ui
}  // namespace play
}  // namespace sg
