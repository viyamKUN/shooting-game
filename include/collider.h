#ifndef __COLLIDER_H_
#define __COLLIDER_H_

#include <SDL.h>

#include "transform.h"

namespace sg {
namespace gamelogic {

class Collider {
 public:
  Collider(int sizeX, int sizeY, int posX, int posY);
  ~Collider();

  void UpdatePos(Transform* transform);
  SDL_bool HasIntersection(Collider* target);
  SDL_Rect* GetCollider();

 private:
  SDL_Rect* collider;
};

}  // namespace gamelogic
}  // namespace sg

#endif
