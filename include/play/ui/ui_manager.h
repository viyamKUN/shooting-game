#ifndef __UI_MANAGER_H_
#define __UI_MANAGER_H_

#include "hp_ui.h"
#include "score_ui.h"

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
  void UpdateScore(int score);

 private:
  static UiManager* instance;
  HpUi* hpUi;
  ScoreUi* scoreUI;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
