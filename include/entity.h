#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include <list>

#include "animation.h"
#include "surface.h"
#include "transform.h"

namespace sg {
namespace gamelogic {
class Entity {
 public:
  Entity(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Entity();

  void OnLoad();
  void RegisterChildEntity(Entity* entity);
  void RegisterParentEntity(Entity* entity);
  void AddDestoryTargetEntity(Entity* entity);
  void RemoveDestroyTargets();

  virtual void SetAnimation();
  // If entity need part of image, set the destination Rect to Cut
  void CutSprite(int posX, int posY);
  virtual void OnLoop();
  virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
  virtual void OnKeyUp(SDL_Keycode key, Uint16 mod);
  void OnRender(SDL_Renderer* renderer);
  void Destroy();
  virtual void OnCleanUp();

 protected:
  Transform* transform;
  Surface* spriteRenderer;
  std::list<Entity*> entities;
  std::list<Entity*> destroyTargets;
  Entity* parent;
};

}  // namespace gamelogic
}  // namespace sg
#endif
