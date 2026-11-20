#ifndef DRAW_H
#define DRAW_H

#include "face.hpp"
#include "object.h"
#include "player.h"
#include "vertex.hpp"
#include <SDL3/SDL_render.h>

/**
 * @class DrawUtil
 * @brief Drawin utilities
 *
 */
class DrawUtil {
public:
  DrawUtil();

  static void drawPlayer(const Player &pl);

  static void drawTrinagle(const Face2D &face);
  static void drawTrinagleOutline(const Face2D &face);

  static void drawObject(const Object &obj);

  static void drawTrinagleOutlineVertexNDC(const std::vector<Vertex> face);

private:
};
#endif // !DRAW_H
