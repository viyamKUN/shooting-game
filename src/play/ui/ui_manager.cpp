#include "play/ui/ui_manager.h"

namespace sg {
namespace play {
namespace ui {

UiManager* UiManager::instance = NULL;

UiManager* UiManager::GetInstance() {
  if (instance == NULL) {
    instance = new UiManager();
  }
  return instance;
}

UiManager::UiManager() { hpUi = new HpUi(); }

UiManager::~UiManager() {}

void UiManager::Init() { hpUi->Init(); }

void UiManager::UpdateHp(int hp) { hpUi->UpdateHp(hp); }

}  // namespace ui
}  // namespace play
}  // namespace sg
