#ifndef __ENTITY_H_
#define __ENTITY_H_

#include "shooting-game/core/entity/collider.h"
#include "shooting-game/core/entity/visual/surface.h"

namespace sg {
namespace core {
namespace entity {

class Entity {
 public:
  Entity();
  Entity(const char* spriteName, int sizeX, int sizeY, int posX, int posY);
  ~Entity();
  virtual entity::Entity* Clone();

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
  void SetActiveCollider(bool isOn);
  Collider* GetCollider();

  void SetIsActive(bool active);
  bool GetIsActive();

  virtual void OnLoop();
  virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
  virtual void OnKeyUp(SDL_Keycode key, Uint16 mod);
  virtual void OnKey(SDL_Keycode key);

  // If collision appear, run OnCollisionDetect().
  void OnCollision(entity::Entity* target);
  void OnRender(SDL_Renderer* renderer);
  void OnCleanUp();

 protected:
  Transform* transform;
  visual::Surface* spriteRenderer;
  Collider* collider;

  virtual void OnCollisionDetect(entity::Entity* target);

 private:
  const char* tag;
  const char* spriteName;
  bool isActive;
};

}  // namespace entity
}  // namespace core
}  // namespace sg

#endif
