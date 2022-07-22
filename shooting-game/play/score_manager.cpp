#include "shooting-game/play/score_manager.h"

namespace sg {
namespace play {

ScoreManager::ScoreManager() {}

ScoreManager::~ScoreManager() {}

void ScoreManager::SetScoreChangedEvent(
    std::function<void(int)> scoreChangedEvent) {
  this->scoreChangedEvent = scoreChangedEvent;
}

void ScoreManager::ChangeScore(int value) {
  score = value;
  scoreChangedEvent(score);
}

void ScoreManager::AddScore(int value) {
  score += value;
  scoreChangedEvent(score);
}

int ScoreManager::GetScore() { return score; }

}  // namespace play
}  // namespace sg
