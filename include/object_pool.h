#ifndef __OBJECT_POOL_H_
#define __OBJECT_POOL_H_

#include <iostream>
#include <list>

namespace sg {
namespace gamelogic {

template <class T>
class ObjectPool {
 public:
  ObjectPool(int maxCount);
  ~ObjectPool();

  T* GetObject();

 private:
  std::list<T*> objects;
};

template <class T>
ObjectPool<T>::ObjectPool(int maxCount) {
  for (int i = 0; i < maxCount; i++) {
    objects.push_back(new T());
  }
}

template <class T>
ObjectPool<T>::~ObjectPool() {}

template <class T>
T* ObjectPool<T>::GetObject() {
  for (auto obj : objects) {
    // TODO: check valid object
    if (true) return obj;
  }
  return NULL;
}

}  // namespace gamelogic
}  // namespace sg

#endif
