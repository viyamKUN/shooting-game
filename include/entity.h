#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include "surface.h"

namespace GameLogic {
class Entity {
 private:
  Surface* spriteSurface;

 public:
  Entity(const char* spriteName);
  ~Entity();

  void OnLoad();
  void OnLoop();
  void OnRender(SDL_Renderer* renderer);
  void OnCleanUp();
};

}  // namespace GameLogic
#endif
