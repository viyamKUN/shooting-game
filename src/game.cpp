#include "game.h"

#include <SDL.h>

#include <iostream>

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
  return true;
}

void Game::OnEvent(SDL_Event *event) {}

void Game::OnLoop() {}

void Game::OnRender() {}

void Game::OnCleanUp() {}

void Game::OnExit() { SDL_Quit(); }

void Game::OnKeyDown(SDLKey key, SDLMod mod, Uint16 unicode) {
  std::cout << "Input Key: " << SDL_GetKeyName(key) << std::endl;
}

}  // namespace GameLogic
