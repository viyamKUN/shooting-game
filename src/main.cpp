#include <iostream>

#include "game.h"

int main(int argc, char** argv) {
  std::cout << "Run Game..." << std::endl;
  auto game = sg::gamelogic::Game::GetInstance();
  game->OnExecute();
  return EXIT_SUCCESS;
}
