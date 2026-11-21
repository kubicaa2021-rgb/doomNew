#include "vector3.hpp"
#include "vector4.hpp"
#include <array>
#include <iostream>
#ifndef MATRIX4_HPP
#define MATRIX$_HPP
/**
 * @class Matrix4
 * @brief Default construction to Identity matrix
 *
 */
class Matrix4 {
public:
  std::array<std::array<float, 4>, 4> data{0};

  void print();

  std::array<float, 4> &operator[](int index) { return data[index]; };
  const std::array<float, 4> &operator[](int index) const {
    return data[index];
  };
  Matrix4 operator*(const Matrix4 &m) const;
  Vector4 operator*(const Vector4 &v) const;
  Matrix4() { data[0][0] = data[1][1] = data[2][2] = data[3][3] = 1; }
  Matrix4(std::array<std::array<float, 4>, 4> values) : data(values) {}
  Matrix4 transposed() const;

private:
};

inline Matrix4 Matrix4::operator*(const Matrix4 &m) const {
  Matrix4 A; // {{{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A[i][j] = data[i][0] * m[0][j] + data[i][1] * m[1][j] +
                data[i][2] * m[2][j] + data[i][3] * m[3][j];
    }
  }
  return A;
} // }}}

inline Vector4 Matrix4::operator*(const Vector4 &v) const {
  Vector4 A = {v.x, v.y, v.z, 1}; // {{{
  Vector4 B;
  B.x =
      data[0][0] * A.x + data[0][1] * A.y + data[0][2] * A.z + data[0][3] * A.w;
  B.y =
      data[1][0] * A.x + data[1][1] * A.y + data[1][2] * A.z + data[1][3] * A.w;
  B.z =
      data[2][0] * A.x + data[2][1] * A.y + data[2][2] * A.z + data[2][3] * A.w;
  B.w =
      data[3][0] * A.x + data[3][1] * A.y + data[3][2] * A.z + data[3][3] * A.w;
  return B;
} // }}}

inline void Matrix4::print() {
  // {{{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << data[i][j] << " | ";
    }
    std::cout << std::endl;
  }
} // }}}

inline Matrix4 Matrix4::transposed() const {
  Matrix4 ret; // {{{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ret[i][j] = data[j][i];
    }
  }
  return ret;
} // }}}

#endif // !MATRIX4_HPP
