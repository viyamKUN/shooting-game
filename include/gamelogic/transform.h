#ifndef __TRANSFORM_H_
#define __TRANSFORM_H_

#include <tuple>

#include "coordination.h"

namespace sg {
namespace gamelogic {
class Transform {
 private:
  Coordination* position;
  Coordination* scale;

 public:
  Transform();
  Transform(int posX, int posY);
  ~Transform();

  Coordination* GetPosition();
  Coordination* GetScale();

  void Translate(int x, int y);
  void SetScale(int x, int y);
  void SetPosition(int x, int y);
};
}  // namespace gamelogic
}  // namespace sg

#endif
