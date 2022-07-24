#include "shooting-game/play/ui/ui_manager.h"

namespace sg {
namespace play {
namespace ui {

UiManager::UiManager() {}

UiManager::~UiManager() {}

void UiManager::InitStartUI() {
  gameStartUI = new GameStartUi();
  gameStartUI->Init();
}

void UiManager::OffStartUI() { gameStartUI->Close(); }

void UiManager::InitGameUI() {
  hpUi = new HpUi();
  hpUi->Init();

  scoreUI = new ScoreUi();
  scoreUI->Init();

  gameOverUI = new GameOverUi();
  gameOverUI->Init();
  gameOverUI->Close();
}

void UiManager::UpdateHp(int hp) { hpUi->UpdateHp(hp); }

void UiManager::UpdateScore(int score) { scoreUI->UpdateNumber(score); }

void UiManager::ShowGameOverUI(int score) {
  gameOverUI->UpdateScore(score);
  gameOverUI->Open();
}

void UiManager::OffGameOverUI() { gameOverUI->Close(); }

}  // namespace ui
}  // namespace play
}  // namespace sg
