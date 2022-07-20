#include "play/background.h"

namespace sg {
namespace gamelogic {
namespace play {

Background::Background() : Entity("tiles.bmp", 16, 16, 0, 0) {
  std::list<std::list<Coordination*>> data;
  for (int y = 0; y < SCREEN_HEIGHT / 16 + 1; y++) {
    std::list<Coordination*> lineData;
    for (int x = 0; x < SCREEN_WIDTH / 16 + 1; x++) {
    }
    data.push_back(lineData);
  }
  spriteRenderer->SetTileData(data);
}

Background::~Background() {}

}  // namespace play
}  // namespace gamelogic
}  // namespace sg
