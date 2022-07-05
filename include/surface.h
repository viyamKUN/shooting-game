#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

namespace GameLogic {
class Surface {
 private:
  const char* assetPath;
  SDL_Texture* texture;

 public:
  Surface(const char* path);
  ~Surface();

  void OnLoad(SDL_Renderer* renderer);
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();
};
}  // namespace GameLogic
#endif
