#include "shooting-game/play/ui/game_start_ui.h"

namespace sg {
namespace play {
namespace ui {

GameStartUi::GameStartUi() : Entity() {
  SDL_Log("[Return] Start game.");
  gamelogic::EntityRegistry::GetInstance()->RegistEntity(this);
}

GameStartUi::~GameStartUi() {}

void GameStartUi::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  if (key == SDLK_RETURN) {
    // TODO
    // PlayManager::GetInstance()->InitScene(GAME_SCENE_GAME);
    SetIsActive(false);
  }
}

}  // namespace ui
}  // namespace play
}  // namespace sg
