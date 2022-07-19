#include "play/ui/hp_heart_ui.h"

#include "game.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace ui {

HpHeartUI::HpHeartUI() : Entity("box.bmp", 16, 32, 0, 0) {
  Game::GetInstance()->RegisterEntity(this);
  UpdateState(false);
}

HpHeartUI::~HpHeartUI() {}

void HpHeartUI::UpdatePosition(int posX, int posY) {
  transform->SetPosition(posX, posY);
}

void HpHeartUI::UpdateState(bool isFill) {
  this->isFill = isFill;
  // TODO: Update Image
  if (isFill)
    CutSprite(0, 0);
  else
    CutSprite(16, 0);
}

}  // namespace ui
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
