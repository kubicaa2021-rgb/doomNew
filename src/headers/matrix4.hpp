#include <array>
#include <iostream>
#ifndef MATRIX4_HPP
/**
 * @class Matrix4
 * @brief Default construction to Identity matrix
 *
 */
class Matrix4 {
public:
  std::array<std::array<float, 4>, 4> data;

  void print();

  std::array<float, 4> &operator[](int index) { return data[index]; };
  Matrix4 operator*(Matrix4 &m) const;
  Matrix4() { data[0][0] = data[1][1] = data[2][2] = data[3][3] = 1; }
  Matrix4(std::array<std::array<float, 4>, 4> values) : data(values) {}

private:
};

inline Matrix4 Matrix4::operator*(Matrix4 &m) const {
  Matrix4 A;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A[i][j] = data[i][0] * m[0][j] + data[i][1] * m[1][j] +
                data[i][2] * m[2][j] + data[i][3] * m[3][j];
    }
  }
  return A;
}

inline void Matrix4::print() {

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << data[i][j] << " | ";
    }
    std::cout << std::endl;
  }
}

#endif // !MATRIX4_HPP
