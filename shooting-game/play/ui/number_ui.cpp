#include "shooting-game/play/ui/number_ui.h"

namespace sg {
namespace play {
namespace ui {
NumberUI::NumberUI() : Entity("numbers.bmp", SIZE, SIZE, 0, 0) {
  UpdateNumber(0);
  core::EntityRegistry::GetInstance()->RegistEntity(this);
}

NumberUI::~NumberUI() {}

void NumberUI::SetPosition(int posX, int posY) {
  transform->SetPosition(posX, posY);
}

void NumberUI::UpdateNumber(int num) {
  this->number = num;
  CutSprite(SIZE * number, 0);
}

}  // namespace ui
}  // namespace play
}  // namespace sg
