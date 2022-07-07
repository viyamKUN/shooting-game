#include "game.h"

namespace sg {
namespace gamelogic {
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
    OnLoop();
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

  RegistEntities();
  for (auto entity : entities) {
    entity->OnLoad();
  }
  return true;
}

void Game::RegistEntities() {
  play::Player* player = new play::Player();
  entities.push_back(player);

  play::Bullet* bullet = new play::Bullet(SCREEN_WIDTH / 2, 400, 1);
  entities.push_back(bullet);

  Entity* box = new Entity("box.bmp", 32, 32, SCREEN_WIDTH / 2, 100);
  entities.push_back(box);
}

void Game::OnEvent(SDL_Event* event) { Event::OnEvent(event); }

void Game::OnLoop() {
  for (auto entity : entities) {
    entity->OnLoop();
  }
}

void Game::OnRender() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  for (auto entity : entities) {
    entity->OnRender(renderer);
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

}  // namespace gamelogic
}  // namespace sg
