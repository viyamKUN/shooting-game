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

  if ((int)letter >= (int)'0' && (int)letter <= (int)'9') {
    // Interger letter
    letterIndex = (int)letter - (int)'0';
    // 4 is basic number
    CutSprite(letterIndex % 8 * SIZE,
              (NUMBER_ROW_STARTING_COUNT + letterIndex / 8) * SIZE);
    return true;
  } else if (letterIndex < 0 || letterIndex >= 26) {
    // Update letter image to blank image. (last block)
    CutSprite(7 * SIZE, 7 * SIZE);
    if ((int)letter == (int)' ') {
      // Empty letter.
      return true;
    }
    return false;
  } else {
    // A~Z
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
