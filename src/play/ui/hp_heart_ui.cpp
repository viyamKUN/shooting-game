#include "play/ui/hp_heart_ui.h"

#include "game.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace ui {

HpHeartUI::HpHeartUI() : Entity("hearts.bmp", WIDTH, HEIGHT, 0, 0) {
  Game::GetInstance()->RegisterEntity(this);
  UpdateState(true);
}

HpHeartUI::~HpHeartUI() {}

void HpHeartUI::UpdatePosition(int posX, int posY) {
  transform->SetPosition(posX, posY);
}

void HpHeartUI::UpdateState(bool isFill) {
  if (isFill)
    CutSprite(0, 0);
  else
    CutSprite(WIDTH, 0);
}

int HpHeartUI::GetWidth() { return WIDTH; }

}  // namespace ui
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
