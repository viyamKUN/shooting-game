#ifndef __TEXT_UI_H_
#define __TEXT_UI_H_

#include <iostream>

#include "shooting-game/play/ui/text/letter_ui.h"

namespace sg {
namespace play {
namespace ui {
class TextUi {
 public:
  TextUi();
  ~TextUi();

  void UpdatePos(int x, int y);
  void UpdateText(std::string text);
  std::string GetText();

 private:
  std::string text;
  int capacity;
  int posX;
  int posY;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
