# Shooting Game

Basic shooting game.

## Build

### Bazel

* bazel build //shooting-game
* ./bazel-bin/shooting-game/shooting-game

### CMake

* cmake .. -GNinja
* ninja

## Execute Build file

* need `chmod +x shooting-game` (add execute permission)
* need assets folder and files

## Use

* `SDL2`
* `Bazel`

## Commands

* bazel run //:buildifier

## Other Docs

* [Dev diary](docs/diary.md)
* [game design](docs/design.md)
