#ifndef __UI_MANAGER_H_
#define __UI_MANAGER_H_

#include "hp_ui.h"

namespace sg {
namespace play {
namespace ui {
class UiManager {
 public:
  static UiManager* GetInstance();

  UiManager();
  ~UiManager();

  void Init();
  void UpdateHp(int hp);

 private:
  static UiManager* instance;
  HpUi* hpUi;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
