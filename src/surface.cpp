#include "surface.h"

#include <SDL.h>

namespace GameLogic {

Surface::Surface(const char* path) {
  assetPath = path;
  texture = NULL;
}

Surface::~Surface() {}

void Surface::OnLoad(SDL_Renderer* renderer) {
  SDL_Surface* src = SDL_LoadBMP(assetPath);
  if (src == NULL) {
    std::cout << "BMP Load Failed. PATH: " << assetPath << std::endl;
    SDL_GetError();
    return;
  }
  texture = SDL_CreateTextureFromSurface(renderer, src);
  SDL_FreeSurface(src);
}

void Surface::OnDraw(SDL_Renderer* renderer) {
  SDL_Rect destRect;
  destRect.x = 0;
  destRect.y = 0;
  SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void Surface::OnClear() { SDL_DestroyTexture(texture); }

}  // namespace GameLogic
