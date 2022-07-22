#include <iostream>

#include "shooting-game/core/game.h"

int main(int argc, char** argv) {
  std::cout << "Run Game..." << std::endl;
  auto game = new sg::core::Game();
  game->OnExecute();
  delete (game);
  return EXIT_SUCCESS;
}
