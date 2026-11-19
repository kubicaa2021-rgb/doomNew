#ifndef QUATERNION_H
#define QUATERNION_H

#include "util.h"
#include "vector3.hpp"
#include <cmath>

class Quaternion {
public:
  float w, x, y, z;

  Quaternion operator*(const Quaternion &A) const;

  static Quaternion FromAxisAngle(const Vector3 &v, const float &angle);

  void Normalize();
  Quaternion Inversed() const;
};

inline Quaternion Quaternion::FromAxisAngle(const Vector3 &v,
                                            const float &angle) {
  Vector3 norm = v.normalized(); // {{{
  float w_axis = cosf(angle / 2.0f);
  float s = sinf(angle / 2.0f);
  return {w_axis, norm.x * s, norm.y * s, norm.z * s};
}; // }}}

inline Quaternion Quaternion::operator*(const Quaternion &A) const {
  Vector3 va = {x, y, z}; // {{{
  Vector3 vb = {A.x, A.y, A.z};

  float newW = w * A.w - Vector3::dotProduct(va, vb);
  Vector3 newV = (vb * w) + (va * A.w) + Vector3::crossProduct(va, vb);

  return {newW, newV.x, newV.y, newV.z};
}; // }}}
inline void Quaternion::Normalize() {
  // {{{
  float len = w * w + x * x + y * y + z * z;
  if (Util::isApxEqual(len, 0, 0.0001f)) {
    w = 1;
    x = 0;
    y = 0;
    z = 0;
  }
  float invLen = 1.0f / sqrtf(len);

  w = w * invLen;
  x = x * invLen;
  y = y * invLen;
  z = z * invLen;
}; // }}}

inline Quaternion Quaternion::Inversed() const { return {w, -x, -y, -z}; }

#endif // !QUATERNION_H
