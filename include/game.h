#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>

#include <iostream>
#include <list>

#include "config.h"
#include "entity.h"
#include "event.h"
#include "play/player.h"
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

 private:
  Game();
  bool OnInit();
  void RegisterEntities();
  void OnEvent(SDL_Event* event);
  void OnLoop();
  void DestroyTargets();
  void OnRender();
  void OnCleanUp();

  static Game* instance;
  std::list<Entity*> entities;
  std::list<Entity*> destroyRegistry;
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
};
}  // namespace gamelogic
}  // namespace sg

#endif
