#include "shooting-game/play/ui/text/text_ui.h"

namespace sg {
namespace play {
namespace ui {

TextUi::TextUi() : capacity(5), posX(0), posY(0), text("") {}

TextUi::~TextUi() {}

void TextUi::UpdatePos(int x, int y) {
  posX = x;
  posY = y;
}

void TextUi::UpdateText(std::string text) { this->text = text; }

std::string TextUi::GetText() { return text; }

}  // namespace ui
}  // namespace play
}  // namespace sg
