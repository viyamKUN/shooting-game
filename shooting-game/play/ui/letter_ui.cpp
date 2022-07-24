#include "shooting-game/play/ui/letter_ui.h"

namespace sg {
namespace play {
namespace ui {
LetterUi::LetterUi() : Entity("numbers.bmp", SIZE, SIZE, 0, 0) {
  core::EntityRegistry::GetInstance()->RegistEntity(this);

  // Init to letter A.
  TryUpdateLetter('A');
}

LetterUi::~LetterUi() {}

void LetterUi::SetPosition(int posX, int posY) {
  transform->SetPosition(posX, posY);
}

bool LetterUi::TryUpdateLetter(char letter) {
  int letterIndex = (int)letter - (int)'A';
  if (letterIndex < 0 || letterIndex >= 26) {
    return false;
  }

  this->letter = letter;
  auto x = letterIndex % 8;
  auto y = letterIndex / 8;
  CutSprite(x, y);
  return true;
}

}  // namespace ui
}  // namespace play
}  // namespace sg
