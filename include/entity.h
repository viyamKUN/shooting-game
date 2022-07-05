#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include "animation.h"
#include "surface.h"
#include "transform.h"

namespace sg::gamelogic {
class Entity {
 public:
  Transform* transform;
  Surface* spriteRenderer;

 public:
  Entity(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Entity();

  void SetAnimation(int animationType, int maxFrame);
  void OnLoad();
  virtual void OnLoop();
  virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
  void OnRender(SDL_Renderer* renderer);
  virtual void OnCleanUp();
};

}  // namespace sg::gamelogic
#endif
