#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
/*
@brief 3D vector
@field `float` x,y,z
@brief default value is `0`
*/
class Vector3 {
public:
  Vector3();
  Vector3(float x, float y, float z);
  float x{0}, y{0}, z{0};
  /*
@brief Returns normalized vector
*/
  Vector3 normalized();
  /*
@brief Gets vector magnitude(length)
@return `float` Length
*/
  float getMagnitude();

  static float dotProduct(const Vector3 &a, const Vector3 &b);
};

inline Vector3::Vector3() {}

inline Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

inline float Vector3::getMagnitude() {
  return (std::sqrt(x * x + y * y + z * z));
}

inline Vector3 Vector3::normalized() {
  float check = this->getMagnitude();
  if (check == 0) {
    return {0, 0, 0};
  }
  float len = 1 / check;
  return {x * len, y * len, z * len};
}

inline float Vector3::dotProduct(const Vector3 &a, const Vector3 &b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}

#endif // !VECTOR3_H
