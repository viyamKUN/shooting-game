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
};

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
