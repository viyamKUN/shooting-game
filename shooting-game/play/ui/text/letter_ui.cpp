#include "shooting-game/play/ui/text/letter_ui.h"

namespace sg {
namespace play {
namespace ui {
LetterUi::LetterUi() : Entity("letters.bmp", SIZE, SIZE, 0, 0) {
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
    // TODO: If letter is integer, make interger image.
    // Update letter image to blank image. (last block)
    CutSprite(7 * SIZE, 7 * SIZE);
    if ((int)letter == (int)' ') {
      return true;
    }
    return false;
  } else {
    this->letter = letter;
    auto x = letterIndex % 8 * SIZE;
    auto y = letterIndex / 8 * SIZE;
    CutSprite(x, y);
    return true;
  }
}

int LetterUi::GetScaledSizeX() {
  return spriteRenderer->GetSize()->getX() * transform->GetScale()->getX();
}

}  // namespace ui
}  // namespace play
}  // namespace sg
