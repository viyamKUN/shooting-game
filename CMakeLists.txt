cmake_minimum_required(VERSION 3.10)

project(shooting-game)
set(CMAKE_CXX_STANDARD 17)

# Build rules

include_directories(./include)
add_executable(shooting-game
    src/play/bullet.cpp
    src/play/player.cpp
    src/animation.cpp
    src/collider.cpp
    src/coordination.cpp
    src/transform.cpp
    src/entity.cpp
    src/surface.cpp
    src/event.cpp
    src/game.cpp
    src/main.cpp
)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
target_link_libraries(shooting-game OpenGL::GL SDL2::SDL2)
