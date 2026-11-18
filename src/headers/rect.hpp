#ifndef RECT_H
#define RECT_H

#include <SDL3/SDL_mutex.h>
#include <SDL3/SDL_pixels.h>
/*
@brief Basic rectangle class
@consturctor*/
class Rect {
public:
  Rect();
  Rect(float x, float y, float width, float height, SDL_Color color);

  Rect(float x, float y, float width, float height);

  float x, y, width, height;
  SDL_Color color{200, 20, 200, 255};

private:
};

inline Rect::Rect() {}
inline Rect::Rect(float x, float y, float width, float height, SDL_Color color)
    : x(x), y(y), width(width), height(height), color(color) {}
inline Rect::Rect(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height) {}
#endif // !RECT_H

SDL_TRY_ACQUIRE(x, y)
