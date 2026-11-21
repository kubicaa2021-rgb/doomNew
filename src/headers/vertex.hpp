#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "vector3.hpp"
class Vertex {
public:
  Vector3 position;
  void convertToScreenSpace(int w, int h);

private:
};

inline void Vertex::convertToScreenSpace(int w, int h) {
  position.x = (position.x * 0.5f + 0.5f) * w;
  position.y = (1.0f - (position.y * 0.5f + 0.5f)) * h;
}

#endif // !VERTEX_HPP
