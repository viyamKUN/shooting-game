#include "play/ui/hp_ui.h"

namespace sg {
namespace play {
namespace ui {

HpUi::HpUi() {
  // Create heart uis.
  for (int i = 0; i < PLAYER_MAX_HP; i++) {
    heartUIs[i] = new HpHeartUI();
  }
}

HpUi::~HpUi() {}

void HpUi::Init() {
  for (int i = 0; i < PLAYER_MAX_HP; i++) {
    // TODO: positions are dummy for test.
    heartUIs[i]->UpdatePosition(
        X_POS + (heartUIs[i]->GetWidth() + HEART_UI_DISTANCE) * i, Y_POS);
  }
}

void HpUi::UpdateHp(int hp) {
  for (int i = 0; i < PLAYER_MAX_HP; i++) {
    heartUIs[i]->UpdateState(i < hp);
  }
}

}  // namespace ui
}  // namespace play
}  // namespace sg
