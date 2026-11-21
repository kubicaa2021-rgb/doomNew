#ifndef VECTOR4_HPP
#define VECTOR4_HPP
class Vector4 {
public:
  float x{0}, y{0}, z{0}, w{0};
  Vector4() {}
  Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};
#endif // !VECTOR4_HPP
