#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>

#include <iostream>
#include <list>

#include "config.h"
#include "entity.h"
#include "event.h"
#include "play/service_provider.h"
#include "surface.h"

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
  void RegisterEntity(Entity* entity);
  void RegisterEntityDestroy(Entity* entity);
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

  std::list<Entity*> entities;
  std::list<Entity*> destroyRegistry;

  bool isPause;
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}  // namespace gamelogic
}  // namespace sg

#endif
