#ifndef __PLAY_MANAGER_H_
#define __PLAY_MANAGER_H_

#include "shooting-game/play/background.h"
#include "shooting-game/play/enemy/enemy_spawner.h"
#include "shooting-game/play/game_settings.h"
#include "shooting-game/play/player/player.h"
#include "shooting-game/play/service_provider.h"

namespace sg {
namespace play {
class PlayManager : public core::entity::Entity {
 public:
  PlayManager();
  ~PlayManager();

  static PlayManager* GetInstance();

  void SetEvents(std::function<void()> pause, std::function<void()> resume,
                 std::function<void()> quit);

  void OnKeyDown(SDL_Keycode key, Uint16 mod);

  void InitScene(SCENE scene);
  void OnStartGame();
  // Show game over ui and wait for restart or quit input.
  void OnGameOver();
  void AddScore(int amt);

 private:
  play::EnemySpawner* enemySpawner;
  play::Player* player;
  SCENE currentScene;

  std::function<void()> gamePause;
  std::function<void()> gameResume;
  std::function<void()> gameQuit;

  static PlayManager* instance;
};

}  // namespace play
}  // namespace sg
#endif
