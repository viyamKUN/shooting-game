#ifndef __GAME_SETTINGS_H_
#define __GAME_SETTINGS_H_

namespace sg {
namespace gamelogic {
namespace play {

#define PLAYER "player"
#define BULLET "bullet"
#define ENEMY "enemy"
// Player's maximum hp.
#define PLAYER_MAX_HP 5

enum FACTION { NONE, FACTION_PLAYER, FACTION_ENEMY };

enum SIDE { LEFT, RIGHT };

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
