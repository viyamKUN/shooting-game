#include "surface.h"

#include <SDL.h>

namespace sg::gamelogic {

Surface::Surface(char* path) {
  assetPath = path;
  texture = NULL;
}

Surface::~Surface() {}

void Surface::OnLoad(Transform* transform) {
  this->transform = transform;
  src = SDL_LoadBMP(assetPath);
  if (src == NULL) SDL_GetError();
}

void Surface::OnDraw(SDL_Renderer* renderer) {
  texture = SDL_CreateTextureFromSurface(renderer, src);
  SDL_Rect destRect;
  destRect.x = transform->GetPosition()->getX();
  destRect.y = transform->GetPosition()->getY();
  destRect.w = transform->GetSize()->getX();
  destRect.h = transform->GetSize()->getY();
  SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void Surface::OnClear() {
  SDL_FreeSurface(src);
  SDL_DestroyTexture(texture);
}

}  // namespace sg::gamelogic
