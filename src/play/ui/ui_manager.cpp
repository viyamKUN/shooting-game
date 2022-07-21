#include "play/ui/ui_manager.h"

namespace sg {
namespace play {
namespace ui {

UiManager::UiManager() {
  hpUi = new HpUi();
  scoreUI = new ScoreUi();
  gameOverUI = new GameOverUi();
}

UiManager::~UiManager() {}

void UiManager::Init() {
  hpUi->Init();
  scoreUI->Init();
  gameOverUI->SetIsActive(false);
}

void UiManager::UpdateHp(int hp) { hpUi->UpdateHp(hp); }

void UiManager::UpdateScore(int score) { scoreUI->UpdateNumber(score); }

void UiManager::ShowGameOverUI() { gameOverUI->SetIsActive(true); }

}  // namespace ui
}  // namespace play
}  // namespace sg
