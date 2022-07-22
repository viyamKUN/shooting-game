#include "shooting-game/core/visual/surface.h"

#include <SDL2/SDL.h>

namespace sg {
namespace core {
namespace visual {

Surface::Surface(char* path, int sizeX, int sizeY)
    : texture(NULL),
      animation(NULL),
      assetPath(path),
      angle(0),
      flip(SDL_FLIP_NONE),
      surfConfig((SurfaceConfig){SURF_TYPE_SINGLE, new Coordination(0, 0),
                                 new Coordination(sizeX, sizeY)}) {}

Surface::~Surface() {
  if (tiles.size() > 0) {
    for (auto line : tiles) {
      for (auto iter = line.begin(); iter != line.end();) {
        delete (*iter);
      }
    }
    tiles.clear();
  }
  delete animation;
}

void Surface::InitAnimation() { animation = new Animation(); }

void Surface::AddAnimation(Uint16 state, Uint16 animType, int maxFrame) {
  animation->AddAnimationState(state, animType, maxFrame);
}

void Surface::CutSurface(int posX, int posY) {
  surfConfig.surfaceType = SURF_TYPE_MULTIPLE;
  surfConfig.position->setX(posX);
  surfConfig.position->setY(posY);
}

Coordination* Surface::GetSize() { return surfConfig.size; }

void Surface::Flip(SDL_RendererFlip flipType) { flip = flipType; }

void Surface::ChangeAnimationState(int state) {
  animation->SetAnimationState(state);
}

void Surface::ResetAnimation() {
  if (animation) {
    animation->ResetAnimation();
  }
}

bool Surface::IsAnimationOver() {
  if (animation == NULL) return false;
  return animation->GetIsAnimationOver();
}

void Surface::SetTileData(std::list<std::list<Coordination*>> data) {
  tiles = data;
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
    // Render proper frame of animation;
    DrawAnimationFrame(renderer, &destRect);
  } else if (surfConfig.surfaceType == SURF_TYPE_MULTIPLE) {
    // Render part of image.
    DrawCutImage(renderer, &destRect);
  } else if (tiles.size() > 0) {
    // Render tiles.
    DrawTileMap(renderer);
  } else {
    // Render whole image.
    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, angle, NULL, flip);
  }
}

void Surface::OnClear() {
  SDL_FreeSurface(src);
  SDL_DestroyTexture(texture);
}

void Surface::DrawAnimationFrame(SDL_Renderer* renderer, SDL_Rect* destRect) {
  SDL_Rect srcRect;
  srcRect.x = surfConfig.size->getX() * animation->GetCurrentFrame();
  srcRect.y = surfConfig.size->getY() * animation->GetAnimationState();
  srcRect.w = surfConfig.size->getX();
  srcRect.h = surfConfig.size->getY();
  SDL_RenderCopyEx(renderer, texture, &srcRect, destRect, angle, NULL, flip);
}

void Surface::DrawCutImage(SDL_Renderer* renderer, SDL_Rect* destRect) {
  SDL_Rect srcRect;
  srcRect.x = surfConfig.position->getX();
  srcRect.y = surfConfig.position->getY();
  srcRect.w = surfConfig.size->getX();
  srcRect.h = surfConfig.size->getY();
  SDL_RenderCopyEx(renderer, texture, &srcRect, destRect, angle, NULL, flip);
}

void Surface::DrawTileMap(SDL_Renderer* renderer) {
  int x, y = 0;
  for (auto line : tiles) {
    x = 0;
    for (auto tile : line) {
      // Decide position for tile pos. It is based on tile index.
      SDL_Rect destRect;
      destRect.x = x * surfConfig.size->getX();
      destRect.y = y * surfConfig.size->getY();
      destRect.w = surfConfig.size->getX();
      destRect.h = surfConfig.size->getY();

      // Decide position for source. It is based on exist data.
      SDL_Rect srcRect;
      srcRect.x = surfConfig.size->getX() * tile->getX();
      srcRect.y = surfConfig.size->getY() * tile->getY();
      srcRect.w = surfConfig.size->getX();
      srcRect.h = surfConfig.size->getY();
      SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, NULL,
                       flip);
      x++;
    }
    y++;
  }
}

}  // namespace visual
}  // namespace core
}  // namespace sg
