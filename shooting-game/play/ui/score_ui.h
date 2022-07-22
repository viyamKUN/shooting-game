#ifndef __SCORE_UI_H_
#define __SCORE_UI_H_

#include <SDL2/SDL.h>

#include "number_ui.h"
#include "shooting-game/core/config.h"
#include "shooting-game/core/entity/entity.h"

namespace sg {
namespace play {
namespace ui {
class ScoreUi {
 public:
  ScoreUi();
  ~ScoreUi();

  void Init();
  void UpdateNumber(int score);

 private:
  static const int MAX_NUMBER_COUNT = 5;
  static const int NUMBER_SIZE = 16;
  static const int POS_X = SCREEN_WIDTH - NUMBER_SIZE;
  static const int POS_Y = 24;
  NumberUI* numberUIs[MAX_NUMBER_COUNT];
};

}  // namespace ui
}  // namespace play
}  // namespace sg
#endif
