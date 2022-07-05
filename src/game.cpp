#include "game.h"

namespace GameLogic {
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

  SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
  if (window == NULL) return false;

  SDL_SetWindowTitle(window, "Shooting Game!!");
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  Entity box("box.bmp");
  entities.push_back(&box);
  for (auto entity : entities) {
    entity->OnLoad(renderer);
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
  for (auto entity : entities) {
    // entity->OnRender(renderer);
  }
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
