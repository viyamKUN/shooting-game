#ifndef __EVENT_H__
#define __EVENT_H__
#include <SDL2/SDL.h>

namespace sg {
namespace core {
//게임에서 발생할 수 있는 인풋 이벤트
class Event {
 public:
  Event();
  ~Event();

  virtual void OnEvent(SDL_Event* event);
  // Manages events that retain input.
  virtual void OnRetainKeyEvents();

 public:
  virtual void OnInputFocus();
  virtual void OnInputBlur();
  virtual void OnKeyDown(SDL_Keycode key, Uint16 mod);
  virtual void OnKeyUp(SDL_Keycode key, Uint16 mod);
  virtual void OnKey(SDL_Keycode key);
  virtual void OnMouseFocus();
  virtual void OnMouseBlur();
  virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,
                           bool Right, bool Middle);
  virtual void OnMouseWheel(bool up, bool down);
  virtual void OnLButtonDown(int mX, int mY);
  virtual void OnRButtonDown(int mX, int mY);
  virtual void OnMButtonDown(int mX, int mY);
  virtual void OnLButtonUp(int mX, int mY);
  virtual void OnRButtonUp(int mX, int mY);
  virtual void OnMButtonUp(int mX, int mY);
  virtual void OnMinimize();
  virtual void OnRestore();
  virtual void OnResize(int w, int h);
  virtual void OnExpose();
  virtual void OnQuit();
  virtual void OnUser(Uint8 type, int code, void* data, void* data2);

 private:
  const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
  void CallActiveEvent(SDL_WindowEvent* windowEvent);
  void CallMouseEvent(SDL_MouseButtonEvent* buttonEvent, bool isDown);
};
}  // namespace core
}  // namespace sg

#endif
