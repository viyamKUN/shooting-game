#ifndef __PLAY_MANAGER_H_
#define __PLAY_MANAGER_H_

#include "play/background.h"
#include "play/enemy/enemy_spawner.h"
#include "play/player/player.h"

namespace sg {
namespace play {
class PlayManager {
 public:
  PlayManager();
  ~PlayManager();

  void InitScene();
  void OnStartGame();
  // Show game over ui and wait for restart or quit input.
  void OnGameOver();
  void AddScore(int amt);

 private:
  int score;
};

}  // namespace play
}  // namespace sg
#endif
