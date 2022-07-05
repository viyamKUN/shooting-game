#include "game.h"

namespace sg::gamelogic {
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

  entities.push_back(new Entity("player.bmp"));
  entities.push_back(new Entity("box.bmp"));
  for (auto entity : entities) {
    entity->OnLoad();
  }
  return true;
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
}

}  // namespace GameLogic
