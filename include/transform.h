#ifndef __TRANSFORM_H_
#define __TRANSFORM_H_

#include <tuple>

#include "coordination.h"

namespace sg::gamelogic {
class Transform {
 private:
  Coordination* size;
  Coordination* position;

 public:
  Transform();
  Transform(int sizeX, int sizeY);
  Transform(int sizeX, int sizeY, int posX, int posY);
  ~Transform();

  Coordination* GetSize();
  Coordination* GetPosition();
};
}  // namespace sg::gamelogic

#endif
