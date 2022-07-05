#include "event.h"

#include <SDL.h>

#include <iostream>

namespace sg::gamelogic {
Event::Event() {}

Event::~Event() {}

void Event::OnEvent(SDL_Event* event) {
  switch (event->type) {
    case SDL_WINDOWEVENT:
      CallActiveEvent(&event->window);
      break;

    case SDL_KEYDOWN:
      OnKeyDown(event->key.keysym.sym, event->key.keysym.mod);
      break;

    case SDL_KEYUP:
      OnKeyUp(event->key.keysym.sym, event->key.keysym.mod);
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

    case SDL_WINDOWEVENT_SIZE_CHANGED:
      OnResize(event->window.data1, event->window.data2);
      break;

    case SDL_WINDOWEVENT_EXPOSED:
      OnExpose();
      break;

    default:
      OnUser(event->user.type, event->user.code, event->user.data1,
             event->user.data2);
      break;
  }
}

// 윈도우 활성화 관련 이벤트를 구분하여 호출함
void Event::CallActiveEvent(SDL_WindowEvent* windowEvent) {
  switch (windowEvent->event) {
    case SDL_WINDOWEVENT_ENTER:
      OnMouseFocus();
      break;

    case SDL_WINDOWEVENT_LEAVE:
      OnMouseBlur();
      break;

    case SDL_WINDOWEVENT_FOCUS_GAINED:
      OnInputFocus();
      break;

    case SDL_WINDOWEVENT_FOCUS_LOST:
      OnInputBlur();
      break;

    case SDL_WINDOWEVENT_SHOWN:
      OnRestore();
      break;

    case SDL_WINDOWEVENT_CLOSE:
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
void Event::OnKeyDown(SDL_Keycode key, Uint16 mod) {
  std::cout << "Input Key: " << SDL_GetKeyName(key) << std::endl;
}
void Event::OnKeyUp(SDL_Keycode key, Uint16 mod) {}
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
void Event::OnQuit() { std::cout << "Quit the game." << std::endl; }
void Event::OnUser(Uint8 type, int code, void* data, void* data2) {}

}  // namespace sg::gamelogic
