#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "vector4.hpp"
#include <SDL3/SDL_pixels.h>
class Vertex {
public:
  Vector4 position;
  SDL_Color color{255, 255, 255, 255};
  void convertToScreenSpace(int w, int h);

private:
};

inline void Vertex::convertToScreenSpace(int w, int h) {
  position.x = (position.x * 0.5f + 0.5f) * w;
  position.y = (1.0f - (position.y * 0.5f + 0.5f)) * h;
}

#endif // !VERTEX_HPP
