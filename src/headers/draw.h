#ifndef DRAW_H
#define DRAW_H

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

private:
  SDL_Texture *whiteTex;
  bool createWhiteTex();
};
#endif // !DRAW_H
