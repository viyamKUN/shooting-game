#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

namespace GameLogic {
class Surface {
 private:
  char* assetPath;
  SDL_Surface* src;
  SDL_Texture* texture;

 public:
  Surface(char* path);
  ~Surface();

  void OnLoad();
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();
};
}  // namespace GameLogic
#endif
