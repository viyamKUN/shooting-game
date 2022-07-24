#ifndef __UI_MANAGER_H_
#define __UI_MANAGER_H_

#include "game_over_ui.h"
#include "game_start_ui.h"
#include "hp_ui.h"
#include "score_ui.h"

namespace sg {
namespace play {
namespace ui {
class UiManager {
 public:
  UiManager();
  ~UiManager();

  void InitStartUI();
  void OffStartUI();

  void InitGameUI();
  void UpdateHp(int hp);

  void UpdateScore(int score);

  void ShowGameOverUI(int score);
  void OffGameOverUI();

 private:
  HpUi* hpUi;
  ScoreUi* scoreUI;
  GameOverUi* gameOverUI;
  GameStartUi* gameStartUI;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
