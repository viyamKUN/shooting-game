#ifndef __HP_UI_H_
#define __HP_UI_H_

#include "hp_heart_ui.h"
#include "play/game_settings.h"

namespace sg {
namespace gamelogic {
namespace play {
namespace ui {
class HpUi {
 public:
  HpUi();
  ~HpUi();
  void Init();
  void UpdateHp(int hp);

 private:
  HpHeartUI* heartUIs[PLAYER_MAX_HP];
};

}  // namespace ui
}  // namespace play
}  // namespace gamelogic
}  // namespace sg
#endif
