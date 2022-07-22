#include "shooting-game/play/ui/score_ui.h"

namespace sg {
namespace play {
namespace ui {

ScoreUi::ScoreUi() {
  for (int i = 0; i < MAX_NUMBER_COUNT; i++) {
    numberUIs[i] = new NumberUI();
  }
}

ScoreUi::~ScoreUi() {}

void ScoreUi::Init() {
  for (int i = 0; i < MAX_NUMBER_COUNT; i++) {
    numberUIs[i]->SetPosition(POS_X - NUMBER_SIZE * i, POS_Y);
  }
}

void ScoreUi::UpdateNumber(int score) {
  for (int i = 0; i < MAX_NUMBER_COUNT; i++) {
    auto num = (score / (int)pow(10, i)) % 10;
    numberUIs[i]->UpdateNumber(num);
  }
}

}  // namespace ui
}  // namespace play
}  // namespace sg
