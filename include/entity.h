#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include "surface.h"
#include "transform.h"

namespace sg::gamelogic {
class Entity {
 private:
  Surface* spriteSurface;
  Transform* transform;

 public:
  Entity(const char* spriteName, int sizeX, int sizeY, int positionX,
         int positionY);
  ~Entity();

  void OnLoad();
  void OnLoop();
  void OnRender(SDL_Renderer* renderer);
  void OnCleanUp();
};

}  // namespace sg::gamelogic
#endif
