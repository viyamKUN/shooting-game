#include "surface.h"

#include <SDL.h>

namespace sg {
namespace gamelogic {

Surface::Surface(char* path, int sizeX, int sizeY)
    : angle(0),
      flip(SDL_FLIP_NONE),
      texture(NULL),
      animation(NULL),
      assetPath(path),
      surfConfig((SurfaceConfig){SURF_TYPE_SINGLE, new Coordination(0, 0),
                                 new Coordination(sizeX, sizeY)}) {}

Surface::~Surface() {}

void Surface::InitAnimation() { animation = new Animation(); }

void Surface::AddAnimation(Uint16 state, Uint16 animType, int maxFrame) {
  animation->AddAnimationState(state, animType, maxFrame);
}

void Surface::CutSurface(int posX, int posY) {
  surfConfig.surfaceType = SURF_TYPE_MULTIPLE;
  surfConfig.position->setX(posX);
  surfConfig.position->setY(posY);
}

void Surface::SetScale(int x, int y) { transform->SetScale(x, y); }

void Surface::Flip(SDL_RendererFlip flipType) { flip = flipType; }

void Surface::ChangeAnimationState(int state) {
  animation->SetAnimationState(state);
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
  auto scale = transform->GetScale();
  destRect.x = transform->GetPosition()->getX();
  destRect.y = transform->GetPosition()->getY();
  destRect.w = surfConfig.size->getX() * scale->getX();
  destRect.h = surfConfig.size->getY() * scale->getY();

  if (animation) {
    SDL_Rect srcRect;
    srcRect.x = surfConfig.size->getX() * animation->GetCurrentFrame();
    srcRect.y = surfConfig.size->getY() * animation->GetAnimationState();
    srcRect.w = surfConfig.size->getX();
    srcRect.h = surfConfig.size->getY();
    SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, NULL, flip);
  } else if (surfConfig.surfaceType == SURF_TYPE_MULTIPLE) {
    SDL_Rect srcRect;
    srcRect.x = surfConfig.position->getX();
    srcRect.y = surfConfig.position->getY();
    srcRect.w = surfConfig.size->getX();
    srcRect.h = surfConfig.size->getY();
    SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, NULL, flip);
  } else {
    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, angle, NULL, flip);
  }
}

void Surface::OnClear() {
  SDL_FreeSurface(src);
  SDL_DestroyTexture(texture);
}

}  // namespace gamelogic
}  // namespace sg
