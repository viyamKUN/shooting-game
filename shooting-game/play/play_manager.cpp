#include "shooting-game/play/play_manager.h"

namespace sg {
namespace play {

PlayManager* PlayManager::instance = NULL;

PlayManager* PlayManager::GetInstance() {
  if (instance == NULL) {
    instance = new PlayManager();
  }
  return instance;
}

PlayManager::PlayManager() : score(0), currentScene(GAME_SCENE_NONE) {}

PlayManager::~PlayManager() {}

void PlayManager::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  switch (currentScene) {
    case GAME_SCENE_START:
      if (key == SDLK_RETURN) {
        SDL_Log("Start Game!");

        InitScene(GAME_SCENE_GAME);
        play::ServiceProvider::GetInstance()->GetUIManager()->OffStartUI();
      }
      break;

    case GAME_SCENE_OVER:
      if (key == SDLK_SPACE) {
        SDL_Log("Restart Game!");

        SetIsActive(false);
        // TODO
        // gamelogic::Game::GetInstance()->SetPause(false);
        OnStartGame();
      } else if (key == SDLK_ESCAPE) {
        // gamelogic::Game::GetInstance()->OnQuit();
      }
      break;

    default:
      break;
  }
}

void PlayManager::InitScene(SCENE scene) {
  switch (scene) {
    case GAME_SCENE_START: {
      SDL_Log("Hello, User!");
      currentScene = GAME_SCENE_START;

      play::Background* background = new play::Background();
      gamelogic::EntityRegistry::GetInstance()->RegistEntity(background);

      play::ServiceProvider::GetInstance()->GetUIManager()->InitStartUI();
      break;
    }

    case GAME_SCENE_GAME: {
      player = new play::Player(std::bind(&PlayManager::OnGameOver, instance));
      gamelogic::EntityRegistry::GetInstance()->RegistEntity(player);

      enemySpawner = new play::EnemySpawner();
      gamelogic::EntityRegistry::GetInstance()->RegistEntity(enemySpawner);

      play::ServiceProvider::GetInstance()->GetUIManager()->InitGameUI();

      OnStartGame();
      break;
    }

    case GAME_SCENE_OVER: {
      break;
    }

    case GAME_SCENE_NONE: {
      SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "You can't initialize NONE scene.");
      break;
    }
  }
}

void PlayManager::OnStartGame() {
  currentScene = GAME_SCENE_GAME;

  // Reset player data.
  player->ResetData();

  // Reset score.
  score = 0;
  ServiceProvider::GetInstance()->GetUIManager()->UpdateScore(score);
}

void PlayManager::OnGameOver() {
  currentScene = GAME_SCENE_OVER;

  SDL_Log("Player Die!");
  SDL_Log("Score is %d", score);
  SDL_Log("[SPACE]: Restart  [ESCAPE]: Quit");

  // Show game over UI.
  ServiceProvider::GetInstance()->GetUIManager()->ShowGameOverUI();

  // Stop the game.
  // gamelogic::Game::GetInstance()->SetPause(true);

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
