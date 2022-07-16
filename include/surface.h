#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>

#include "animation.h"
#include "transform.h"

namespace sg {
namespace gamelogic {

enum SURF_TYPE { SURF_TYPE_SINGLE, SURF_TYPE_MULTIPLE };

struct SurfaceConfig {
 public:
  Uint16 surfaceType;
  Coordination* position;
  Coordination* size;
};

class Surface {
 public:
  Surface(char* path, int sizeX, int sizeY);
  ~Surface();

  void InitAnimation();
  void AddAnimation(Uint16 state, Uint16 animType, int maxFrame);
  void CutSurface(int posX, int posY);
  void SetScale(int x, int y);
  Coordination* GetSize();
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
  struct SurfaceConfig surfConfig;

  const int TRANS_R = 254;
  const int TRANS_G = 0;
  const int TRANS_B = 255;
};

}  // namespace gamelogic
}  // namespace sg

#endif
