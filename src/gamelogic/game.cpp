#include "gamelogic/game.h"

namespace sg {
namespace gamelogic {

Game* Game::instance = NULL;

Game* Game::GetInstance() {
  if (instance == NULL) {
    instance = new Game();
  }
  return instance;
}

Game::Game() {
  std::cout << "Game is running..." << std::endl;
  running = true;
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
    OnLoop();
    OnCollision();
    OnRender();
    SDL_Delay(16);
  }
  OnCleanUp();
  return 0;
}

bool Game::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Init Fail" << std::endl;
    return false;
  }

  window =
      SDL_CreateWindow("Shooting Game!!", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (window == NULL) return false;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  RegisterEntities();
  return true;
}

void Game::RegisterEntities() {
  play::Background* background = new play::Background();
  RegisterEntity(background);

  play::Player* player = new play::Player();
  RegisterEntity(player);

  play::EnemySpawner* spawner = new play::EnemySpawner();
  RegisterEntity(spawner);

  play::ui::UiManager::GetInstance()->Init();
}

void Game::RegisterEntity(Entity* entity) {
  entities.push_back(entity);
  entity->OnLoad();
  entity->SetIsActive(true);
}

void Game::RegisterEntityDestroy(Entity* entity) {
  destroyRegistry.push_back(entity);
}

void Game::OnEvent(SDL_Event* event) { Event::OnEvent(event); }

void Game::OnLoop() {
  for (auto entity : entities) {
    if (entity->GetIsActive()) {
      entity->OnLoop();
    }
  }
  DestroyTargets();
}

void Game::DestroyTargets() {
  if (destroyRegistry.empty()) return;
  for (auto entity : destroyRegistry) {
    entities.remove(entity);
    entity->OnCleanUp();
    delete entity;
  }
  destroyRegistry.clear();
}

void Game::OnCollision() {
  for (auto entity : entities) {
    for (auto target : entities) {
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
  for (auto entity : entities) {
    if (entity->GetIsActive()) {
      entity->OnRender(renderer);
    }
  }
  SDL_RenderPresent(renderer);
}

void Game::OnCleanUp() {
  for (auto entity : entities) {
    entity->OnCleanUp();
  }
  entities.clear();
  SDL_Quit();
}

void Game::OnQuit() {
  Event::OnQuit();
  running = false;
}

void Game::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  Event::OnKeyDown(key, mod);
  for (auto entity : entities) {
    entity->OnKeyDown(key, mod);
  }
}

void Game::OnKeyUp(SDL_Keycode key, Uint16 mod) {
  Event::OnKeyUp(key, mod);
  for (auto entity : entities) {
    entity->OnKeyUp(key, mod);
  }
}

void Game::OnKey(SDL_Keycode key) {
  Event::OnKey(key);
  for (auto entity : entities) {
    entity->OnKey(key);
  }
}

}  // namespace gamelogic
}  // namespace sg
