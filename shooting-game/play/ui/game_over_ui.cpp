#include "shooting-game/play/ui/game_over_ui.h"

#include "shooting-game/gamelogic/entity_registry.h"
// #include "shooting-game/play/play_manager.h"

namespace sg {
namespace play {
namespace ui {

GameOverUi::GameOverUi() : Entity("black.bmp", 16, 16, 0, 0) {
  transform->SetScale(SCREEN_WIDTH, SCREEN_HEIGHT);
  gamelogic::EntityRegistry::GetInstance()->RegistEntity(this);
}

GameOverUi::~GameOverUi() {}

void GameOverUi::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  if (key == SDLK_SPACE) {
    SDL_Log("Game Restart...");
    SetIsActive(false);
    // TODO
    // gamelogic::Game::GetInstance()->SetPause(false);
    // PlayManager::GetInstance()->OnStartGame();
  } else if (key == SDLK_ESCAPE) {
    // gamelogic::Game::GetInstance()->OnQuit();
  }
}

}  // namespace ui
}  // namespace play
}  // namespace sg
