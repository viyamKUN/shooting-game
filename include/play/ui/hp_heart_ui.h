#ifndef __HP_HEART_UI_H_
#define __HP_HEART_UI_H_

#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace ui {
class HpHeartUI : public Entity {
 public:
  HpHeartUI();
  ~HpHeartUI();

  void Init();
  void UpdatePosition(int posX, int posY);
  void UpdateState(bool isFill);
  int GetWidth();

 private:
  static const int WIDTH = 16;
  static const int HEIGHT = 16;
};

}  // namespace ui
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
#endif
