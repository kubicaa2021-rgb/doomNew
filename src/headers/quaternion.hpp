#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "matrix4.hpp"
#include "util.hpp"
#include "vector3.hpp"
#include <cmath>

class Quaternion {
public:
  float w{1}, x{0}, y{0}, z{0};

  Quaternion operator*(const Quaternion &A) const;

  static Quaternion FromAxisAngle(const Vector3 &v, const float &angle);

  void Normalize();
  Quaternion InversedUnitQ() const;
  Matrix4 toMatrix4() const;
  Vector3 rotate(const Vector3 &v) const;
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
    return;
  }
  float invLen = 1.0f / sqrtf(len);

  w = w * invLen;
  x = x * invLen;
  y = y * invLen;
  z = z * invLen;
}; // }}}

inline Quaternion Quaternion::InversedUnitQ() const { return {w, -x, -y, -z}; }

inline Matrix4 Quaternion::toMatrix4() const {
  Matrix4 ret; // {{{
  ret[0] = {1 - 2 * (y * y + z * z), 2 * (x * y - w * z), 2 * (x * z + w * y),
            0};
  ret[1] = {2 * (x * y + w * z), 1 - 2 * (x * x + z * z), 2 * (y * z - w * x),
            0};
  ret[2] = {2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x * x + y * y),
            0};
  ret[3] = {0, 0, 0, 1};
  return ret;
} // }}}

inline Vector3 Quaternion::rotate(const Vector3 &v) const {
  Quaternion v_p = {0, v.x, v.y, v.z};
  v_p.Normalize();
  Quaternion p = (*this * v_p) * this->InversedUnitQ();
  return {p.x, p.y, p.z};
}

#endif // !QUATERNION_HPP
