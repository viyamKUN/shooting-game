#ifndef __GAME_SETTINGS_H_
#define __GAME_SETTINGS_H_

namespace sg {
namespace play {

#define PLAYER "player"
#define BULLET "bullet"
#define ENEMY "enemy"
// Player's maximum hp.
#define PLAYER_MAX_HP 5

enum FACTION { NONE, FACTION_PLAYER, FACTION_ENEMY };

enum SIDE { LEFT, RIGHT };

enum SCENE { GAME_SCENE_NONE, GAME_SCENE_START, GAME_SCENE_GAME };

}  // namespace play
}  // namespace sg

#endif
