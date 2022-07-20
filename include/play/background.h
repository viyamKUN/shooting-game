#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include <list>

#include "config.h"
#include "coordination.h"
#include "entity.h"

namespace sg {
namespace gamelogic {
namespace play {
class Background : public Entity {
 public:
  Background();
  ~Background();

 private:
  static const int TILE_SIZE = 16;
  static const int TILE_CUT_COUNT = 8;
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
