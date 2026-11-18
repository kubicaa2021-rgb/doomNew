#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
/*
@brief 2D vector
@field `float` x,y
@brief default value is `0`
*/
class Vector2 {
public:
  Vector2();
  Vector2(float x, float y);
  float x{0}, y{0};
  /*
@brief Returns normalized vector
*/
  Vector2 normalized();
  /*
@brief Gets vector magnitude(length)
@return `float` Length
*/
  float getMagnitude();

  static float dotProduct(const Vector2 &a, const Vector2 &b);

  Vector2 &operator+=(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this;
  }
};

inline Vector2::Vector2() {}

inline Vector2::Vector2(float x, float y) : x(x), y(y) {}

inline float Vector2::getMagnitude() { return (std::sqrt(x * x + y * y)); }

inline Vector2 Vector2::normalized() {
  float check = this->getMagnitude();
  if (check == 0) {
    return {0, 0};
  }
  float len = 1 / check;
  return {x * len, y * len};
}

inline float Vector2::dotProduct(const Vector2 &a, const Vector2 &b) {
  return (a.x * b.x + a.y * b.y);
}

#endif // !VECTOR2_H
