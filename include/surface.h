#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

#include "transform.h"

namespace sg::gamelogic {
class Surface {
 private:
  char* assetPath;
  SDL_Surface* src;
  SDL_Texture* texture;
  Transform* transform;

 public:
  Surface(char* path);
  ~Surface();

  void OnLoad(Transform* transform);
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();
};
}  // namespace sg::gamelogic
#endif
