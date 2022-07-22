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

PlayManager::PlayManager() : currentScene(GAME_SCENE_NONE) {}

PlayManager::~PlayManager() {}

void PlayManager::SetEvents(std::function<void()> pause,
                            std::function<void()> resume,
                            std::function<void()> quit) {
  gamePause = pause;
  gameResume = resume;
  gameQuit = quit;
}

void PlayManager::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  switch (currentScene) {
    case GAME_SCENE_START:
      if (key == SDLK_RETURN) {
        SDL_Log("Start Game!");

        InitScene(GAME_SCENE_GAME);
        ServiceProvider::GetInstance()->GetUIManager()->OffStartUI();
      }
      break;

    case GAME_SCENE_OVER:
      if (key == SDLK_SPACE) {
        SDL_Log("Restart Game!");

        SetIsActive(false);
        gameResume();
        OnStartGame();
      } else if (key == SDLK_ESCAPE) {
        gameQuit();
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

      Background* background = new Background();
      core::EntityRegistry::GetInstance()->RegistEntity(background);

      ServiceProvider::GetInstance()->GetUIManager()->InitStartUI();
      break;
    }

    case GAME_SCENE_GAME: {
      player = new Player(std::bind(&PlayManager::OnGameOver, instance));
      core::EntityRegistry::GetInstance()->RegistEntity(player);

      enemySpawner = new EnemySpawner();
      core::EntityRegistry::GetInstance()->RegistEntity(enemySpawner);

      ServiceProvider::GetInstance()->GetUIManager()->InitGameUI();

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
  ServiceProvider::GetInstance()->UpdateScore(0);
}

void PlayManager::OnGameOver() {
  currentScene = GAME_SCENE_OVER;

  SDL_Log("Player Die!");
  auto score = ServiceProvider::GetInstance()->GetScore();
  SDL_Log("Score is %d", score);
  SDL_Log("[SPACE]: Restart  [ESCAPE]: Quit");

  // Show game over UI.
  ServiceProvider::GetInstance()->GetUIManager()->ShowGameOverUI();

  // Stop the game.
  gamePause();

  // Off all of enemy, blood and bullet entities.
  enemySpawner->ClearEnemies();
  ServiceProvider::GetInstance()->GetBulletPool()->ClearBullets();
  ServiceProvider::GetInstance()->GetBloodPool()->ClearBloods();
}

}  // namespace play
}  // namespace sg
