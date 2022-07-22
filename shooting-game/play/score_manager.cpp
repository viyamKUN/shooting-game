#include "shooting-game/play/score_manager.h"

namespace sg {
namespace play {

ScoreManager::ScoreManager() {}

ScoreManager::~ScoreManager() {}

void ScoreManager::ChangeScore(int value) { score = value; }

void ScoreManager::AddScore(int value) { score += value; }

int ScoreManager::GetScore() { return score; }

}  // namespace play
}  // namespace sg
