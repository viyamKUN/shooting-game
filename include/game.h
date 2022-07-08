#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>

#include <iostream>
#include <vector>

#include "config.h"
#include "entity.h"
#include "event.h"
#include "play/player.h"
#include "surface.h"
namespace sg {
namespace gamelogic {
class Game : Event {
 private:
  std::vector<Entity*> entities;
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;

 public:
  Game();
  ~Game();

  int OnExecute();

 private:
  bool OnInit();
  void RegisterEntities();
  void OnEvent(SDL_Event* event);
  void OnLoop();
  void OnRender();
  void OnCleanUp();

 public:
  void OnQuit();
  void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnKeyUp(SDL_Keycode key, Uint16 mod);
};
}  // namespace gamelogic
}  // namespace sg

#endif
