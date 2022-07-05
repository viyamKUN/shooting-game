#include <iostream>

#include "game.h"

int main(int argc, char** argv) {
  std::cout << "Run Game..." << std::endl;
  sg::gamelogic::Game game;
  game.OnExecute();
  return EXIT_SUCCESS;
}
