#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

#include "animation.h"
#include "transform.h"

namespace sg {
namespace gamelogic {
class Surface {
 public:
  Surface(char* path);
  ~Surface();

  void SetAnimation(int animationType, int maxFrame);
  void SetScale(int x, int y);
  void Flip(SDL_RendererFlip flipType);
  void ChangeAnimationState(int state);

  void OnLoad(Transform* transform);
  void OnLoop();
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();

 private:
  char* assetPath;
  SDL_Surface* src;
  SDL_Texture* texture;
  Transform* transform;
  Animation* animation;
  double angle;
  SDL_RendererFlip flip;

  const int TRANS_R = 254;
  const int TRANS_G = 0;
  const int TRANS_B = 255;
};
}  // namespace gamelogic
}  // namespace sg

#endif
