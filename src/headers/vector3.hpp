#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <vector>
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
  Vector3 normalized() const;
  /*
@brief Gets vector magnitude(length)
@return `float` Length
*/
  float getMagnitude() const;

  static float dotProduct(const Vector3 &a, const Vector3 &b);
  static Vector3 crossProduct(const Vector3 &a, const Vector3 &b);

  Vector3 operator*(const float &n) const;
  Vector3 operator+(const Vector3 &v) const;
};

inline Vector3::Vector3() {}

inline Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

inline float Vector3::getMagnitude() const {
  return (std::sqrt(x * x + y * y + z * z));
}

inline Vector3 Vector3::normalized() const {
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

inline Vector3 Vector3::crossProduct(const Vector3 &a, const Vector3 &b) {
  return {a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y};
}

// Operators

inline Vector3 Vector3::operator*(const float &n) const {
  return {this->x * n, this->y * n, this->z * n};
}

inline Vector3 Vector3::operator+(const Vector3 &v) const {
  return {this->x + v.x, this->y + v.y, this->z + v.z};
}

#endif // !VECTOR3_H
