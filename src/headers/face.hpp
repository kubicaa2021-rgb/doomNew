#ifndef FACE_HPP
#define FACE_HPP
#include "vector2.hpp"
#include "vertex.hpp"
class Face3D {
public:
  Face3D();
  Vertex vertices[3];
};
class Face2D {
public:
  Face2D();
  Vector2 vertices[3];
};

inline Face3D::Face3D() {}
inline Face2D::Face2D() {}
#endif // !FACE_HPP
