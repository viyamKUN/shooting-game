#ifndef __SURFACE_H
#define __SURFACE_H

#include <SDL.h>

#include <iostream>
#include <list>

#include "animation.h"
#include "coordination.h"
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
  void ResetAnimationFrame();

  // The 'data' need positions of tile source. Big tile sprite asset will be
  // seperate in surface size.
  void SetTileData(std::list<std::list<Coordination*>> data);

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

  std::list<std::list<Coordination*>> tiles;

  const int TRANS_R = 254;
  const int TRANS_G = 0;
  const int TRANS_B = 255;

  void DrawAnimationFrame(SDL_Renderer* renderer, SDL_Rect* destRect);
  void DrawCutImage(SDL_Renderer* renderer, SDL_Rect* destRect);
  // Render whole tiles.
  void DrawTileMap(SDL_Renderer* renderer);
};

}  // namespace gamelogic
}  // namespace sg

#endif
