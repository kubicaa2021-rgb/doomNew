#include <iostream>
#ifndef MATRIX4_HPP
class Matrix4 {
public:
  int data[4][4];

  void print();

  int (&operator[](int index))[4] { return data[index]; };
  Matrix4 operator*(Matrix4 &m) const;

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
