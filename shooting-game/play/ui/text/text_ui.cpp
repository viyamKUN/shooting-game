#include "shooting-game/play/ui/text/text_ui.h"

namespace sg {
namespace play {
namespace ui {

TextUi::TextUi() : text(""), posX(0), posY(0) {}

TextUi::~TextUi() { letterUis.clear(); }

void TextUi::Close() {
  for (auto text : letterUis) {
    text->SetIsActive(false);
  }
}

void TextUi::UpdatePos(int x, int y) {
  posX = x;
  posY = y;
}

void TextUi::UpdateText(std::string text) {
  this->text = text;
  if (text.length() > letterUis.size()) {
    AddLetterEntities(text.length());
  }
  auto index = 0;
  for (auto letter : letterUis) {
    letter->TryUpdateLetter(text[index]);
    letter->SetPosition(
        posX + GetLetterPosition(index, letter->GetScaledSizeX()), posY);
    index++;
  }
}

std::string TextUi::GetText() { return text; }

void TextUi::AddLetterEntities(int targetSize) {
  while (letterUis.size() < targetSize) {
    letterUis.push_back(new LetterUi());
  }
}

int TextUi::GetLetterPosition(int letterIndex, int letterSize) {
  return letterSize * (letterIndex - text.length() / 2);
}

}  // namespace ui
}  // namespace play
}  // namespace sg
