#ifndef __NUMBER_UI_H_
#define __NUMBER_UI_H_

#include <SDL.h>

#include "gamelogic/entity.h"

namespace sg {
namespace play {
namespace ui {
class NumberUI : public gamelogic::Entity {
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
