#include "play/background.h"

namespace sg {
namespace play {

Background::Background() : Entity("tiles.bmp", TILE_SIZE, TILE_SIZE, 0, 0) {
  std::list<std::list<gamelogic::Coordination*>> data;
  auto yCount = SCREEN_HEIGHT / TILE_SIZE + 1;
  auto xCount = SCREEN_WIDTH / TILE_SIZE + 1;

  srand(time(NULL));
  for (int y = 0; y < yCount; y++) {
    std::list<gamelogic::Coordination*> lineData;
    for (int x = 0; x < xCount; x++) {
      lineData.push_back(new gamelogic::Coordination(rand() % TILE_CUT_COUNT,
                                                     rand() % TILE_CUT_COUNT));
    }
    data.push_back(lineData);
  }
  spriteRenderer->SetTileData(data);
}

Background::~Background() {}

}  // namespace play
}  // namespace sg
