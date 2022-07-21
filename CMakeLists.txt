cmake_minimum_required(VERSION 3.10)

project(shooting-game)
set(CMAKE_CXX_STANDARD 17)

# Build rules

include_directories(./include)
add_executable(shooting-game
    src/play/ui/hp_heart_ui.cpp
    src/play/ui/hp_ui.cpp
    src/play/ui/number_ui.cpp
    src/play/ui/score_ui.cpp
    src/play/ui/ui_manager.cpp
    src/play/enemy/enemy_hit_effect.cpp
    src/play/enemy/enemy_blood_pool.cpp
    src/play/enemy/enemy.cpp
    src/play/enemy/enemy_spawner.cpp
    src/play/player/player_walk_effect.cpp
    src/play/player/player.cpp
    src/play/background.cpp
    src/play/bullet.cpp
    src/play/bullet_pool.cpp
    src/play/service_provider.cpp
    src/play/play_manager.cpp
    src/gamelogic/object_pool.cpp
    src/gamelogic/animation.cpp
    src/gamelogic/collider.cpp
    src/gamelogic/coordination.cpp
    src/gamelogic/transform.cpp
    src/gamelogic/entity.cpp
    src/gamelogic/surface.cpp
    src/gamelogic/event.cpp
    src/gamelogic/game.cpp
    src/main.cpp
)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
target_link_libraries(shooting-game OpenGL::GL SDL2::SDL2)
