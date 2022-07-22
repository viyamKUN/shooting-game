#include "shooting-game/core/game.h"

namespace sg {
namespace core {

Game::Game() {
  std::cout << "Game is running..." << std::endl;
  running = true;
  isPause = false;
  window = NULL;
  renderer = NULL;
}

Game::~Game() {}

// 게임 루프를 실행함
int Game::OnExecute() {
  if (OnInit() == false) return -1;

  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      OnEvent(&event);
    }
    Event::OnRetainKeyEvents();
    if (isPause) {
      // Pass loops.
    } else {
      OnLoop();
      OnCollision();
    }
    OnRender();
    SDL_Delay(16);
  }
  OnCleanUp();
  return 0;
}

bool Game::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    SDL_Log("Init Fail");
    return false;
  }

  window =
      SDL_CreateWindow("Shooting Game!!", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (window == NULL) return false;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  play::PlayManager::GetInstance()->InitScene(play::GAME_SCENE_START);
  EntityRegistry::GetInstance()->RegistEntity(play::PlayManager::GetInstance());
  return true;
}

void Game::SetPause(bool pause) { isPause = pause; }

void Game::OnEvent(SDL_Event* event) { Event::OnEvent(event); }

void Game::OnLoop() {
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    if (entity->GetIsActive()) {
      entity->OnLoop();
    }
  }
}

void Game::OnCollision() {
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    for (auto target : EntityRegistry::GetInstance()->GetRegistry()) {
      if (target == entity) continue;
      if (entity->GetIsActive() && target->GetIsActive()) {
        entity->OnCollision(target);
      }
    }
  }
}

void Game::OnRender() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    if (entity->GetIsActive()) {
      entity->OnRender(renderer);
    }
  }
  SDL_RenderPresent(renderer);
}

void Game::OnCleanUp() {
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    entity->OnCleanUp();
  }
  EntityRegistry::GetInstance()->CleanUpRegistry();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::OnQuit() {
  Event::OnQuit();
  running = false;
}

void Game::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  Event::OnKeyDown(key, mod);
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    if (!entity->GetIsActive()) continue;
    entity->OnKeyDown(key, mod);
  }
}

void Game::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  Event::OnKeyUp(key, mod);
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    entity->OnKeyUp(key, mod);
  }
}

void Game::OnKey(SDL_Keycode key) {
  Event::OnKey(key);
  for (auto entity : EntityRegistry::GetInstance()->GetRegistry()) {
    entity->OnKey(key);
  }
}

}  // namespace core
}  // namespace sg
