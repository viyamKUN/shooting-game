#ifndef __COLLIDER_H_
#define __COLLIDER_H_

#include <SDL2/SDL.h>

#include "shooting-game/core/entity/transform.h"

namespace sg {
namespace core {
namespace entity {

class Collider {
 public:
  Collider(int sizeX, int sizeY, Transform* transform);
  ~Collider();

  void UpdatePos(Transform* transform);
  SDL_bool HasIntersection(Collider* target);
  SDL_Rect* GetCollider();
  void SetActive(bool isOn);
  bool GetActive();

 private:
  SDL_Rect* collider;
  bool isActive;
};

}  // namespace entity
}  // namespace core
}  // namespace sg

#endif
