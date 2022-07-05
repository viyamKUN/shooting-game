#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

#include "animation.h"
#include "transform.h"

namespace sg::gamelogic {
class Surface {
 private:
  char* assetPath;
  SDL_Surface* src;
  SDL_Texture* texture;
  Transform* transform;
  Animation* animation;

 public:
  Surface(char* path);
  ~Surface();

  void SetAnimation(int animationType, int maxFrame);
  void OnLoad(Transform* transform);
  void OnLoop();
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();
};
}  // namespace sg::gamelogic
#endif
