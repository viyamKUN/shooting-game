#ifndef __GAME_SETTINGS_H_
#define __GAME_SETTINGS_H_

namespace sg {
namespace gamelogic {
namespace play {

#define PLAYER "player"
#define PLAYER_BULLET "bullet"
#define ENEMY "enemy"
#define ENEMY_BULLET "enemyBullet"
// Player's maximum hp.
#define MAX_HP 5

enum FACTION { NONE, FACTION_PLAYER, FACTION_ENEMY };

}  // namespace play
}  // namespace gamelogic
}  // namespace sg

#endif
