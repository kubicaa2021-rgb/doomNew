#ifndef FACE_HPP
#define FACE_HPP
#include "vector2.hpp"
#include "vector3.hpp"
#include "vertex.hpp"
#include <vector>

class Face2D {
public:
  Face2D();
  Vector2 vertices[3];
};

class Face3D {
public:
  Face3D();
  Vector3 vertices[3];
};

class Mesh {
public:
  Mesh();
  std::vector<Vertex> vertices;
  std::vector<int> triangles;
};

inline Face2D::Face2D() {}
inline Mesh::Mesh() {}
#endif // !FACE_HPP
