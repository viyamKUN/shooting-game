#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>

#include <iostream>
#include <list>

#include "shooting-game/gamelogic/config.h"
#include "shooting-game/gamelogic/entity.h"
#include "shooting-game/gamelogic/entity_registry.h"
#include "shooting-game/gamelogic/event.h"
#include "shooting-game/gamelogic/surface.h"
#include "shooting-game/play/play_manager.h"

namespace sg {
namespace gamelogic {
class Game : Event {
 public:
  static Game* GetInstance();

  ~Game();

  int OnExecute();
  void OnQuit();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnKey(SDL_Keycode key);
  void SetPause(bool pause);

 private:
  Game();
  bool OnInit();
  void OnEvent(SDL_Event* event);
  void OnLoop();
  void DestroyTargets();
  void OnCollision();
  void OnRender();
  void OnCleanUp();

  static Game* instance;

  bool isPause;
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}  // namespace gamelogic
}  // namespace sg

#endif
