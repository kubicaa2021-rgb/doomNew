#ifndef MAP_H
#define MAP_H

#include <vector>
class Map {
public:
  Map();
  static constexpr int kTileSize = 50;

  inline static std::vector<std::vector<int>> tiles = {
      {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

private:
};
#endif // !MAP_H
