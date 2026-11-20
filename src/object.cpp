#include "object.h"
#include "quaternion.hpp"

void Object::updateModelMatrix() {
  Matrix4 scaleM;
  Matrix4 rotationM;
  Matrix4 translationM;

  // Updating scale matrix
  scaleM[0][0] *= scale.x;
  scaleM[1][1] *= scale.y;
  scaleM[2][2] *= scale.z;

  // Rotation matrix
  rotationM = rotation.toMatrix4();

  // Translation matrix
  translationM[0][3] = position.x;
  translationM[1][3] = position.y;
  translationM[2][3] = position.z;

  modelMatrix = translationM * rotationM * scaleM;
}
