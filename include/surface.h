#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

#include "animation.h"
#include "transform.h"

namespace sg {
namespace gamelogic {
class Surface {
 private:
  char* assetPath;
  SDL_Surface* src;
  SDL_Texture* texture;
  Transform* transform;
  Animation* animation;

 private:
  const int TRANS_R = 254;
  const int TRANS_G = 0;
  const int TRANS_B = 255;

 public:
  Surface(char* path);
  ~Surface();

  void SetAnimation(int animationType, int maxFrame);
  void ChangeAnimationState(int state);
  void OnLoad(Transform* transform);
  void OnLoop();
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();
};
}  // namespace gamelogic
}  // namespace sg

#endif
