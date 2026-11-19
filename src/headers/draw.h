#ifndef DRAW_H
#define DRAW_H

#include "face.hpp"
#include "player.h"
#include <SDL3/SDL_render.h>

/**
 * @class DrawUtil
 * @brief Drawin utilities
 *
 */
class DrawUtil {
public:
  DrawUtil();

  void drawPlayer(const Player &pl);

  void drawTrinagle(const Face2D &face);
  void drawTrinagleOutline(const Face2D &face);

private:
  SDL_Texture *whiteTex;
  bool createWhiteTex();
};
#endif // !DRAW_H
