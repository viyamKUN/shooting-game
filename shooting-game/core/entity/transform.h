#ifndef __TRANSFORM_H_
#define __TRANSFORM_H_

#include <tuple>

#include "shooting-game/core/coordination.h"

namespace sg {
namespace core {
namespace entity {

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

}  // namespace entity
}  // namespace core
}  // namespace sg

#endif
