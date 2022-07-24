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

  void Close();
  void UpdatePos(int x, int y);
  void UpdateText(std::string text);
  std::string GetText();

 private:
  std::string text;
  int posX;
  int posY;

  std::list<LetterUi*> letterUis;

  void AddLetterEntities(int targetSize);
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif