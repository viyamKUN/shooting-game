#ifndef __NUMBER_UI_H_
#define __NUMBER_UI_H_

#include <SDL2/SDL.h>

#include "shooting-game/core/entity_registry.h"

namespace sg {
namespace play {
namespace ui {
class NumberUI : public core::Entity {
 public:
  NumberUI();
  ~NumberUI();

  void SetPosition(int posX, int posY);
  void UpdateNumber(int num);

 private:
  static const int SIZE = 16;
  // The number that entity will show.
  int number;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
