#ifndef DRAW_H
#define DRAW_H

#include "map.h"
#include "player.h"
#include "vector2.hpp"
#include <SDL3/SDL_render.h>
#include <rect.hpp>

/**
 * @class DrawUtil
 * @brief Drawin utilities
 *
 */
class DrawUtil {
public:
  DrawUtil();
  void drawRectangle(const Rect &rec);
  void drawMap(const Map &map);
  // only for 2D top down protoype
  void drawPlayer(const Player &pl);
  void drawMap3D(const Map &map, const Player &pl);

  void rayCastDebug(const Player &pl);
  void rayCastCollisionDebug(const float &rayDirection, const Player &pl);
  float rayCast(const float &rayDirection, const Player &pl);

private:
  SDL_Texture *whiteTex;
  bool createWhiteTex();
  /**
   *in radians
   **/
};
#endif // !DRAW_H
