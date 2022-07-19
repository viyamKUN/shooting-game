#include "play/ui/hp_ui.h"

namespace sg {
namespace gamelogic {
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
    heartUIs[i]->UpdatePosition(40 * i, 0);
  }
}

void HpUi::UpdateHp(int hp) {
  for (int i = 0; i < PLAYER_MAX_HP; i++) {
    heartUIs[i]->UpdateState(i < hp);
  }
}

}  // namespace ui
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
