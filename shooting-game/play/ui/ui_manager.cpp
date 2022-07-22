#include "shooting-game/play/ui/ui_manager.h"

namespace sg {
namespace play {
namespace ui {

UiManager::UiManager() {}

UiManager::~UiManager() {}

void UiManager::InitStartUI() { gameStartUI = new GameStartUi(); }

void UiManager::OffStartUI() { gameStartUI->SetIsActive(false); }

void UiManager::InitGameUI() {
  hpUi = new HpUi();
  hpUi->Init();

  scoreUI = new ScoreUi();
  scoreUI->Init();

  gameOverUI = new GameOverUi();
  gameOverUI->SetIsActive(false);
}

void UiManager::UpdateHp(int hp) { hpUi->UpdateHp(hp); }

void UiManager::UpdateScore(int score) { scoreUI->UpdateNumber(score); }

void UiManager::ShowGameOverUI() { gameOverUI->SetIsActive(true); }

void UiManager::OffGameOverUI() { gameOverUI->SetIsActive(false); }

}  // namespace ui
}  // namespace play
}  // namespace sg
