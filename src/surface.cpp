#include "surface.h"

#include <SDL.h>

namespace sg::gamelogic {

Surface::Surface(char* path) {
  assetPath = path;
  texture = NULL;
}

Surface::~Surface() {}

void Surface::OnLoad() {
  src = SDL_LoadBMP(assetPath);
  if (src == NULL) SDL_GetError();
}

void Surface::OnDraw(SDL_Renderer* renderer) {
  texture = SDL_CreateTextureFromSurface(renderer, src);
  SDL_Rect destRect;
  destRect.x = 0;
  destRect.y = 0;
  destRect.w = 32;
  destRect.h = 32;
  SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void Surface::OnClear() {
  SDL_FreeSurface(src);
  SDL_DestroyTexture(texture);
}

}  // namespace sg::gamelogic
