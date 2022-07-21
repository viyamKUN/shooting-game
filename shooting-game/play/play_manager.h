#ifndef __PLAY_MANAGER_H_
#define __PLAY_MANAGER_H_

#include "shooting-game/gamelogic/entity_registry.h"
#include "shooting-game/play/background.h"
#include "shooting-game/play/enemy/enemy_spawner.h"
#include "shooting-game/play/game_settings.h"
#include "shooting-game/play/player/player.h"

namespace sg {
namespace play {
class PlayManager {
 public:
  PlayManager();
  ~PlayManager();

  static PlayManager* GetInstance();

  void InitScene(SCENE scene);
  void OnStartGame();
  // Show game over ui and wait for restart or quit input.
  void OnGameOver();
  void AddScore(int amt);

 private:
  play::EnemySpawner* enemySpawner;
  play::Player* player;
  int score;

  static PlayManager* instance;
};

}  // namespace play
}  // namespace sg
#endif
