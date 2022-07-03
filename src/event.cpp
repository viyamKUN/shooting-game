#include "event.h"

#include <SDL.h>

namespace GameLogic {
Event::Event() {}

Event::~Event() {}

void Event::OnEvent(SDL_Event* event) {
  switch (event->type) {
    case SDL_ACTIVEEVENT:
      CallActiveEvent(&event->active);
      break;

    case SDL_KEYDOWN:
      OnKeyDown(event->key.keysym.sym, event->key.keysym.mod,
                event->key.keysym.unicode);
      break;

    case SDL_KEYUP:
      OnKeyUp(event->key.keysym.sym, event->key.keysym.mod,
              event->key.keysym.unicode);
      break;

    case SDL_MOUSEBUTTONDOWN:
      CallMouseEvent(&event->button, true);
      break;

    case SDL_MOUSEBUTTONUP:
      CallMouseEvent(&event->button, false);
      break;

    case SDL_MOUSEMOTION:
      OnMouseMove(event->motion.x, event->motion.y, event->motion.xrel,
                  event->motion.yrel,
                  (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                  (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                  (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
      break;

    case SDL_QUIT:
      OnQuit();
      break;

    case SDL_VIDEORESIZE:
      OnResize(event->resize.w, event->resize.h);
      break;

    case SDL_VIDEOEXPOSE:
      OnExpose();
      break;

    default:
      OnUser(event->user.type, event->user.code, event->user.data1,
             event->user.data2);
      break;
  }
}

// 윈도우 활성화 관련 이벤트를 구분하여 호출함
void Event::CallActiveEvent(SDL_ActiveEvent* activeEvent) {
  bool isGained = activeEvent->gain;
  switch (activeEvent->state) {
    case SDL_APPMOUSEFOCUS:
      if (isGained)
        OnMouseFocus();
      else
        OnMouseBlur();
      break;

    case SDL_APPINPUTFOCUS:
      if (isGained)
        OnInputFocus();
      else
        OnInputBlur();
      break;

    case SDL_APPACTIVE:
      if (isGained)
        OnRestore();
      else
        OnMinimize();
      break;
  }
}

void Event::CallMouseEvent(SDL_MouseButtonEvent* buttonEvent, bool isDown) {
  switch (buttonEvent->button) {
    case SDL_BUTTON_LEFT:
      if (isDown)
        OnLButtonDown(buttonEvent->x, buttonEvent->y);
      else
        OnLButtonUp(buttonEvent->x, buttonEvent->y);
      break;

    case SDL_BUTTON_RIGHT:
      if (isDown)
        OnRButtonDown(buttonEvent->x, buttonEvent->y);
      else
        OnRButtonUp(buttonEvent->x, buttonEvent->y);
      break;

    case SDL_BUTTON_MIDDLE:
      if (isDown)
        OnMButtonDown(buttonEvent->x, buttonEvent->y);
      else
        OnMButtonUp(buttonEvent->x, buttonEvent->y);
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
