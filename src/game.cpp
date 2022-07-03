#include "game.h"

namespace GameLogic {
Game::Game() {
  std::cout << "Game is running..." << std::endl;
  running = true;
  windowSurface = NULL;
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
  }
  OnCleanUp();
  return 0;
}

bool Game::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  windowSurface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (windowSurface == NULL) {
    return false;
  }
  SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

  Entity box("box.bmp");
  entities.push_back(&box);
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
  for (auto entity : entities) {
    entity->OnRender(windowSurface);
  }
  SDL_Flip(windowSurface);
}

void Game::OnCleanUp() {
  SDL_FreeSurface(windowSurface);
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

void Game::OnKeyDown(SDLKey key, SDLMod mod, Uint16 unicode) {
  Event::OnKeyDown(key, mod, unicode);
}

}  // namespace GameLogic
