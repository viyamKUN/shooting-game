#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include "animation.h"
#include "surface.h"
#include "transform.h"

namespace sg {
namespace gamelogic {
class Entity {
 public:
  Transform* transform;
  Surface* spriteRenderer;

 public:
  Entity(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Entity();

  void OnLoad();
  void SetAnimation(int animationType, int maxFrame);
  virtual void OnLoop();
  virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
  virtual void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnRender(SDL_Renderer* renderer);
  virtual void OnCleanUp();
};

}  // namespace gamelogic
}  // namespace sg
#endif
