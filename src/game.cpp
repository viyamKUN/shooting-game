#include "game.h"

#include <SDL.h>

#include <iostream>

namespace GameLogic {
Game::Game() {
  std::cout << "Game is running..." << std::endl;
  running = true;
  windowSurface = NULL;
  surface = new Surface("../assets/box.bmp");
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

  surface->OnLoad();
  return true;
}

void Game::OnEvent(SDL_Event *event) { Event::OnEvent(event); }

void Game::OnLoop() {}

void Game::OnRender() {
  surface->OnDraw(windowSurface);
  SDL_Flip(windowSurface);
}

void Game::OnCleanUp() {
  surface->OnClear();
  SDL_FreeSurface(windowSurface);
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
