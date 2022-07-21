#ifndef __HP_UI_H_
#define __HP_UI_H_

#include "shooting-game/play/game_settings.h"
#include "shooting-game/play/ui/hp_heart_ui.h"

namespace sg {
namespace play {
namespace ui {
class HpUi {
 public:
  HpUi();
  ~HpUi();
  void Init();
  void UpdateHp(int hp);

 private:
  const int HEART_UI_DISTANCE = 8;
  const int X_POS = 24;
  const int Y_POS = 24;
  HpHeartUI* heartUIs[PLAYER_MAX_HP];
};

}  // namespace ui
}  // namespace play
}  // namespace sg
#endif
