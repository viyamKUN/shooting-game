#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>

#include <iostream>
#include <list>

#include "shooting-game/core/config.h"
#include "shooting-game/core/entity_registry.h"
#include "shooting-game/core/event.h"
#include "shooting-game/play/play_manager.h"

namespace sg {
namespace core {
class Game : Event {
 public:
  Game();
  ~Game();

  int OnExecute();
  void OnQuit();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnKey(SDL_Keycode key);
  void SetPause(bool pause);

 private:
  bool OnInit();
  void OnEvent(SDL_Event* event);
  void OnLoop();
  void DestroyTargets();
  void OnCollision();
  void OnRender();
  void OnCleanUp();

  bool isPause;
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}  // namespace core
}  // namespace sg

#endif
