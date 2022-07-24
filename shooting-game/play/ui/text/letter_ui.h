#ifndef __LETTER_UI_H_
#define __LETTER_UI_H_

#include <SDL2/SDL.h>

#include "shooting-game/core/entity_registry.h"

namespace sg {
namespace play {
namespace ui {
class LetterUi : public core::entity::Entity {
 public:
  LetterUi();
  ~LetterUi();

  void SetPosition(int posX, int posY);
  // Return success.
  bool TryUpdateLetter(char letter);

 private:
  static const int SIZE = 16;
  // The letter that entity will show.
  char letter;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
