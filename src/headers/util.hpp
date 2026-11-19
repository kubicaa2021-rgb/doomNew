#ifndef UTIL_H
#define UTIL_H
#include <cstdlib>
class Util {
public:
  static bool isApxEqual(const float &A, const float &B, const float &C);
};

inline bool Util::isApxEqual(const float &A, const float &B, const float &C) {
  return (std::abs(A - B) < C);
};
#endif // !UTIL_H
