#include "surface.h"

#include <SDL.h>

namespace sg {
namespace gamelogic {

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

void Surface::ChangeAnimationState(int state) {
  animation->SetAnimationState(state);
  // TODO: max Frame이 바꿔야함
}

void Surface::OnLoad(Transform* transform) {
  this->transform = transform;
  src = SDL_LoadBMP(assetPath);
  SDL_SetColorKey(src, SDL_TRUE,
                  SDL_MapRGB(src->format, TRANS_R, TRANS_G, TRANS_B));
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
    srcRect.y = transform->GetSize()->getY() * animation->GetAnimationState();
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

}  // namespace gamelogic
}  // namespace sg
