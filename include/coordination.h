#ifndef __COORDINATION_H_
#define __COORDINATION_H_

namespace sg::gamelogic {
class Coordination {
 private:
  int x;
  int y;

 public:
  Coordination(int x, int y);
  ~Coordination();
  int getX();
  int getY();
  void setX(int x);
  void setY(int y);
};

}  // namespace sg::gamelogic

#endif
