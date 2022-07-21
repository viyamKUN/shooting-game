#include "play/ui/game_over_ui.h"

#include "gamelogic/game.h"

namespace sg {
namespace play {
namespace ui {

GameOverUi::GameOverUi() : Entity("black.bmp", 16, 16, 0, 0) {
  transform->SetScale(SCREEN_WIDTH, SCREEN_HEIGHT);
  gamelogic::Game::GetInstance()->RegisterEntity(this);
}

GameOverUi::~GameOverUi() {}

void GameOverUi::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  if (key == SDLK_SPACE) {
    SDL_Log("Game Restart...");
    SetIsActive(false);
  }
}

}  // namespace ui
}  // namespace play
}  // namespace sg
