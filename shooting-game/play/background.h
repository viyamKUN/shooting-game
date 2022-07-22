#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include <list>

#include "shooting-game/core/config.h"
#include "shooting-game/core/coordination.h"
#include "shooting-game/core/entity.h"

namespace sg {
namespace play {
class Background : public core::Entity {
 public:
  Background();
  ~Background();

 private:
  static const int TILE_SIZE = 16;
  static const int TILE_CUT_COUNT = 8;
};

}  // namespace play
}  // namespace sg

#endif
