#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include <list>

#include "gamelogic/config.h"
#include "gamelogic/coordination.h"
#include "gamelogic/entity.h"

namespace sg {
namespace play {
class Background : public gamelogic::Entity {
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
