#ifndef UTIL_HPP
#define UTIL_HPP
#include <cstdlib>
class Util {
public:
  static bool isApxEqual(const float &A, const float &B, const float &C);
};

inline bool Util::isApxEqual(const float &A, const float &B, const float &C) {
  return (std::abs(A - B) < C);
};
#endif // !UTIL_HPP
