#ifndef __GAME_OVER_UI_H_
#define __GAME_OVER_UI_H_

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity_registry.h"
#include "shooting-game/play/ui/text/text_ui.h"

namespace sg {
namespace play {
namespace ui {
class GameOverUi : public core::entity::Entity {
 public:
  GameOverUi();
  ~GameOverUi();

  void Init();
  void Close();
  void Open();
  void UpdateScore(int score);

 private:
  TextUi* titleTextUi;
  TextUi* descTextUi;
};

}  // namespace ui
}  // namespace play
}  // namespace sg

#endif
