#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL2/SDL.h>

#include <iostream>
#include <list>

#include "shooting-game/core/coordination.h"
#include "shooting-game/core/entity/transform.h"
#include "shooting-game/core/entity/visual/animation.h"

namespace sg {
namespace core {
namespace entity {
namespace visual {

enum SURF_TYPE { SURF_TYPE_SINGLE, SURF_TYPE_MULTIPLE };

struct SurfaceConfig {
 public:
  Uint16 surfaceType;
  Coordination* position;
  Coordination* size;
};

class Surface {
 public:
  Surface(const char* path, int sizeX, int sizeY);
  ~Surface();

  void InitAnimation();
  void AddAnimation(Uint16 state, Uint16 animType, int maxFrame);
  void CutSurface(int posX, int posY);
  Coordination* GetSize();
  void Flip(SDL_RendererFlip flipType);
  void ChangeAnimationState(int state);
  void ResetAnimation();
  bool IsAnimationOver();

  // The 'data' need positions of tile source. Big tile sprite asset will be
  // seperate in surface size.
  void SetTileData(std::list<std::list<Coordination*>> data);

  void OnLoad(Transform* transform);
  void OnLoop();
  void OnDraw(SDL_Renderer* renderer);
  void OnClear();

 private:
  const char* assetPath;
  SDL_Surface* src;
  SDL_Texture* texture;
  Transform* transform;
  Animation* animation;
  double angle;
  SDL_RendererFlip flip;
  struct SurfaceConfig surfConfig;

  std::list<std::list<Coordination*>> tiles;

  const int TRANS_R = 254;
  const int TRANS_G = 0;
  const int TRANS_B = 255;

  void DrawAnimationFrame(SDL_Renderer* renderer, SDL_Rect* destRect);
  void DrawCutImage(SDL_Renderer* renderer, SDL_Rect* destRect);
  // Render whole tiles.
  void DrawTileMap(SDL_Renderer* renderer);
};

}  // namespace visual
}  // namespace entity
}  // namespace core
}  // namespace sg

#endif
