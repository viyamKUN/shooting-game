#include "play/play_manager.h"

#include "gamelogic/game.h"
#include "play/service_provider.h"

namespace sg {
namespace play {

PlayManager::PlayManager() : score(0) {}

PlayManager::~PlayManager() {}

void PlayManager::InitScene(SCENE scene) {
  switch (scene) {
    case GAME_SCENE_START: {
      SDL_Log("Hello, User!");

      play::Background* background = new play::Background();
      gamelogic::Game::GetInstance()->RegisterEntity(background);

      play::ServiceProvider::GetInstance()->GetUIManager()->InitStartUI();
      break;
    }

    case GAME_SCENE_GAME: {
      SDL_Log("Start Game!");

      player = new play::Player();
      gamelogic::Game::GetInstance()->RegisterEntity(player);

      enemySpawner = new play::EnemySpawner();
      gamelogic::Game::GetInstance()->RegisterEntity(enemySpawner);

      play::ServiceProvider::GetInstance()->GetUIManager()->InitGameUI();

      OnStartGame();
      break;
    }
  }
}

void PlayManager::OnStartGame() {
  // Reset player data.
  player->ResetData();

  // Reset score.
  score = 0;
  ServiceProvider::GetInstance()->GetUIManager()->UpdateScore(score);
}

void PlayManager::OnGameOver() {
  SDL_Log("Player Die!");
  SDL_Log("Score is %d", score);
  SDL_Log("[SPACE]: Restart  [ESCAPE]: Quit");

  // Show game over UI.
  ServiceProvider::GetInstance()->GetUIManager()->ShowGameOverUI();

  // Stop the game.
  gamelogic::Game::GetInstance()->SetPause(true);

  // Off all of enemy, blood and bullet entities.
  enemySpawner->ClearEnemies();
  ServiceProvider::GetInstance()->GetBulletPool()->ClearBullets();
  ServiceProvider::GetInstance()->GetBloodPool()->ClearBloods();
}

void PlayManager::AddScore(int amt) {
  score += amt;
  play::ServiceProvider::GetInstance()->GetUIManager()->UpdateScore(score);
}

}  // namespace play
}  // namespace sg
