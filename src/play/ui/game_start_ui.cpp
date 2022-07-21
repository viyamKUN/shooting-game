#include "play/ui/game_start_ui.h"

#include "gamelogic/game.h"
#include "play/service_provider.h"

namespace sg {
namespace play {
namespace ui {

GameStartUi::GameStartUi() : Entity() {
  SDL_Log("[Return] Start game.");
  gamelogic::Game::GetInstance()->RegisterEntity(this);
}

GameStartUi::~GameStartUi() {}

void GameStartUi::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  if (key == SDLK_RETURN) {
    ServiceProvider::GetInstance()->GetPlayManager()->InitScene(
        GAME_SCENE_GAME);
    SetIsActive(false);
  }
}

}  // namespace ui
}  // namespace play
}  // namespace sg
