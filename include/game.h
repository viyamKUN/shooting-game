#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>

#include "event.h"
namespace GameLogic {
class Game : Event {
 private:
  bool running;
  SDL_Surface* windowSurface;

 public:
  Game();
  ~Game();

  int OnExecute();

 private:
  bool OnInit();
  void OnEvent(SDL_Event* event);
  void OnLoop();
  void OnRender();
  void OnCleanUp();

 public:
  void OnQuit();
  void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
};
}  // namespace GameLogic

#endif
