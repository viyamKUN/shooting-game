#include "play/ui/ui_manager.h"

namespace sg {
namespace play {
namespace ui {

UiManager::UiManager() {
  hpUi = new HpUi();
  scoreUI = new ScoreUi();
}

UiManager::~UiManager() {}

void UiManager::Init() {
  hpUi->Init();
  scoreUI->Init();
}

void UiManager::UpdateHp(int hp) { hpUi->UpdateHp(hp); }

void UiManager::UpdateScore(int score) { scoreUI->UpdateNumber(score); }

}  // namespace ui
}  // namespace play
}  // namespace sg
