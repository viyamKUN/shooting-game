#ifndef __SCORE_MANAGER_H_
#define __SCORE_MANAGER_H_

#include <iostream>

namespace sg {
namespace play {
class ScoreManager {
 public:
  ScoreManager();
  ~ScoreManager();

  void SetScoreChangedEvent(std::function<void(int)> scoreChangedEvent);
  void ChangeScore(int value);
  void AddScore(int value);
  int GetScore();

 private:
  int score;
  std::function<void(int)> scoreChangedEvent;
};

}  // namespace play
}  // namespace sg

#endif
