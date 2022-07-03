#include "surface.h"

#include <SDL.h>

namespace GameLogic {

Surface::Surface(const char* path) {
  assetPath = path;
  src = NULL;
}

Surface::~Surface() {}

void Surface::OnLoad() {
  SDL_Surface* tempSurface;
  tempSurface = SDL_LoadBMP(assetPath);
  if (tempSurface == NULL) {
    return;
  }
  src = SDL_DisplayFormat(tempSurface);
  SDL_FreeSurface(tempSurface);
}

void Surface::OnDraw(SDL_Surface* destSurface) {
  SDL_Rect destRect;
  destRect.x = 0;
  destRect.y = 0;
  SDL_BlitSurface(src, NULL, destSurface, &destRect);
}

void Surface::OnClear() { SDL_FreeSurface(src); }
}  // namespace GameLogic
