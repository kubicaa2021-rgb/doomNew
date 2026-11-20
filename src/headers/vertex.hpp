#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "vector3.hpp"
#include <SDL3/SDL_pixels.h>
class Vertex {
public:
  Vector3 position;
  SDL_Color color;
  void convertToScreenSpace(int w, int h);

private:
};

inline void Vertex::convertToScreenSpace(int w, int h) {
  position.x = static_cast<float>(w) / 2 + (position.x * w);
  position.y = static_cast<float>(h) / 2 + (position.y * h);
}

#endif // !VERTEX_HPP
