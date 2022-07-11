#ifndef __COLLIDER_H_
#define __COLLIDER_H_

#include <SDL.h>

namespace sg {
namespace gamelogic {

class Collider {
 public:
  Collider(int sizeX, int sizeY, int posX, int posY);
  ~Collider();

  void UpdatePos(int posX, int posY);
  SDL_bool HasIntersection(Collider* target);
  SDL_Rect* GetCollider();

 private:
  SDL_Rect* collider;
};

}  // namespace gamelogic
}  // namespace sg

#endif
