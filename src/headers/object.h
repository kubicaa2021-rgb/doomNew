#ifndef OBJECT_H
#define OBJECT_H
#include "face.hpp"
#include "quaternion.hpp"
#include "vector3.hpp"
#include <vector>
class DrawUtil;

class Object {

public:
  Vector3 position;
  Quaternion rotation;
  Vector3 scale{1, 1, 1};
  Matrix4 modelMatrix;
  Mesh model;

  std::vector<Object *> childs;

  void updateModelMatrix();
};

#endif // !OBJECT_H
