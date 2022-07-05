#include "surface.h"

#include <SDL.h>

namespace sg::gamelogic {

Surface::Surface(char* path) {
  assetPath = path;
  texture = NULL;
  animation = NULL;
}

Surface::~Surface() {}

void Surface::SetAnimation(int animationType, int maxFrame) {
  if (animationType == ANIMATION_NONE) return;
  animation = new Animation(maxFrame, animationType);
}

void Surface::OnLoad(Transform* transform) {
  this->transform = transform;
  src = SDL_LoadBMP(assetPath);
  if (src == NULL) SDL_GetError();
}

void Surface::OnLoop() {
  if (animation) animation->OnAnimate();
}

void Surface::OnDraw(SDL_Renderer* renderer) {
  texture = SDL_CreateTextureFromSurface(renderer, src);
  SDL_Rect destRect;
  destRect.x = transform->GetPosition()->getX();
  destRect.y = transform->GetPosition()->getY();
  destRect.w = transform->GetSize()->getX();
  destRect.h = transform->GetSize()->getY();

  if (animation) {
    SDL_Rect srcRect;
    srcRect.x = transform->GetSize()->getX() * animation->GetCurrentFrame();
    // TODO: 이 값으로 애니메이션 종류를 바꿀 수 있음 (ex. run, walk)
    srcRect.y = 0;
    srcRect.w = transform->GetSize()->getX();
    srcRect.h = transform->GetSize()->getY();
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
  } else {
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
  }
}

void Surface::OnClear() {
  SDL_FreeSurface(src);
  SDL_DestroyTexture(texture);
}

}  // namespace sg::gamelogic
