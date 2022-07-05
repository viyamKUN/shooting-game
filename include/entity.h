#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include "animation.h"
#include "surface.h"
#include "transform.h"

namespace sg::gamelogic {
class Entity {
 private:
  Transform* transform;
  Surface* spriteRenderer;

 public:
  Entity(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Entity();

  void SetAnimation(int animationType, int maxFrame);
  void OnLoad();
  void OnLoop();
  void OnRender(SDL_Renderer* renderer);
  void OnCleanUp();
};

}  // namespace sg::gamelogic
#endif
