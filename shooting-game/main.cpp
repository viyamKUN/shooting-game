#include <iostream>

#include "shooting-game/gamelogic/game.h"

int main(int argc, char** argv) {
  std::cout << "Run Game..." << std::endl;
  auto game = new sg::gamelogic::Game();
  game->OnExecute();
  delete (game);
  return EXIT_SUCCESS;
}
