#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

namespace GameLogic {
class Surface {
 private:
  const char* assetPath;
  SDL_Surface* src;

 public:
  Surface(const char* path);
  ~Surface();

  void OnLoad();
  void OnDraw(SDL_Surface* destSurface);
  void OnClear();
};
}  // namespace GameLogic
#endif
