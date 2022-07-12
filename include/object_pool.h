#ifndef __OBJECT_POOL_H_
#define __OBJECT_POOL_H_

namespace sg {
namespace gamelogic {
class ObjectPool {
 public:
  ObjectPool(int maxCount);
  ~ObjectPool();

 private:
  const int MAX_COUNT;
};

}  // namespace gamelogic
}  // namespace sg

#endif
