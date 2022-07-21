#include "play/play_manager.h"

#include "gamelogic/game.h"
#include "play/service_provider.h"

namespace sg {
namespace play {

PlayManager::PlayManager() : score(0) {}

PlayManager::~PlayManager() {}

void PlayManager::InitScene() {
  play::Background* background = new play::Background();
  gamelogic::Game::GetInstance()->RegisterEntity(background);

  play::Player* player = new play::Player();
  gamelogic::Game::GetInstance()->RegisterEntity(player);

  play::EnemySpawner* spawner = new play::EnemySpawner();
  gamelogic::Game::GetInstance()->RegisterEntity(spawner);

  play::ServiceProvider::GetInstance()->GetUIManager()->Init();
}

void PlayManager::OnStartGame() {}

void PlayManager::OnGameOver() {
  SDL_Log("Player Die!");

  // Show game over UI.
  ServiceProvider::GetInstance()->GetUIManager()->ShowGameOverUI();

  // Stop the game.
  gamelogic::Game::GetInstance()->SetPause(true);

  // TODO: Off all of blood and bullet entities.
}

void PlayManager::AddScore(int amt) {
  score += amt;
  play::ServiceProvider::GetInstance()->GetUIManager()->UpdateScore(score);
}

}  // namespace play
}  // namespace sg
