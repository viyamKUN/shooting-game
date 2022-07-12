#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SDL.h>

#include <list>

#include "animation.h"
#include "collider.h"
#include "surface.h"
#include "transform.h"

namespace sg {
namespace gamelogic {
class Entity {
 public:
  Entity(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Entity();

  void OnLoad();

  // Base init animation. You need to add animation states.
  virtual void SetAnimation();
  // If entity need part of image, set the destination Rect to Cut
  void CutSprite(int posX, int posY);

  // Update Tag. Tag is classify for entity.
  void SetTag(const char* tag);
  bool CompareTag(const char* tag);

  // Collider Can detect collision.
  void SetCollider(int sizeX, int sizeY);
  Collider* GetCollider();

  virtual void OnLoop();
  virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
  virtual void OnKeyUp(SDL_Keycode key, Uint16 mod);
  virtual void OnKey(SDL_Keycode key);

  // If collision appear, run OnCollisionDetect().
  void OnCollision(Entity* target);
  void OnRender(SDL_Renderer* renderer);
  // Register in destroy targets.
  // After Loop, parent entity will destroy whole targets.
  void Destroy();
  void OnCleanUp();

 protected:
  Transform* transform;
  Surface* spriteRenderer;
  Collider* collider;

  virtual void OnCollisionDetect(Entity* target);

 private:
  const char* tag;
};

}  // namespace gamelogic
}  // namespace sg
#endif
