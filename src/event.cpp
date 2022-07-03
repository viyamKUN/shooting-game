#include "event.h"

#include <SDL.h>

namespace GameLogic {
Event::Event() {}

Event::~Event() {}

void Event::OnEvent(SDL_Event* event) {
  switch (event->type) {
    case SDL_ACTIVEEVENT:
      break;

    case SDL_KEYDOWN:
      OnKeyDown(event->key.keysym.sym, event->key.keysym.mod,
                event->key.keysym.unicode);
      break;

    case SDL_KEYUP:
      OnKeyUp(event->key.keysym.sym, event->key.keysym.mod,
              event->key.keysym.unicode);
      break;
      ;

    case SDL_QUIT:
      OnQuit();
      break;

    default:
      break;
  }
}

void Event::OnInputFocus() {}
void Event::OnInputBlur() {}
void Event::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {}
void Event::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {}
void Event::OnMouseFocus() {}
void Event::OnMouseBlur() {}
void Event::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,
                        bool Right, bool Middle) {}
void Event::OnMouseWheel(bool up, bool down) {}
void Event::OnLButtonDown(int mX, int mY) {}
void Event::OnRButtonDown(int mX, int mY) {}
void Event::OnMButtonDown(int mX, int mY) {}
void Event::OnLButtonUp(int mX, int mY) {}
void Event::OnRButtonUp(int mX, int mY) {}
void Event::OnMButtonUp(int mX, int mY) {}
void Event::OnMinimize() {}
void Event::OnRestore() {}
void Event::OnResize(int w, int h) {}
void Event::OnExpose() {}
void Event::OnQuit() {}
void Event::OnUser(Uint8 type, int code, void* data, void* data2) {}

}  // namespace GameLogic
