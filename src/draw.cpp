#include "draw.h"
#include "face.hpp"
#include "globals.h"
#include "object.h"
#include "player.h"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vertex.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <vector>

DrawUtil::DrawUtil() {}

// Only for 2D top down prototype
void DrawUtil::drawPlayer(const Player &pl) {
  // {{{
  // Draws player

  SDL_FRect dstRect{pl.position.x - pl.radius / 2.0f,
                    pl.position.z - pl.radius / 2.0f, pl.radius, pl.radius};

  SDL_SetRenderDrawColor(gRenderer, pl.color.r, pl.color.g, pl.color.b,
                         pl.color.a);
  SDL_RenderRect(gRenderer, &dstRect);
  // Draws direction
  Vector3 lineEnd = pl.camera.rotation.rotate({0, 0, 1});
  lineEnd = lineEnd * 50 + pl.position;

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);

  SDL_RenderLine(gRenderer, pl.position.x, pl.position.z, lineEnd.x, lineEnd.z);
} // }}}

void DrawUtil::drawTrinagle(const Face2D &face) {
  SDL_Vertex ver[3]; // {{{
  ver[0] = {face.vertices[0].x, face.vertices[0].y, 1, 0, 0, 1};
  ver[1] = {face.vertices[1].x, face.vertices[1].y, 0, 1, 0, 1};
  ver[2] = {face.vertices[2].x, face.vertices[2].y, 0, 0, 1, 1};

  SDL_RenderGeometry(gRenderer, nullptr, ver, 3, nullptr, 0);
} // }}}

void DrawUtil::drawTrinagleOutline(const Face2D &face) {
  // {{{
  SDL_FPoint points[4];

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);

  points[3] = {face.vertices[0].x, face.vertices[0].y};
  points[0] = {face.vertices[0].x, face.vertices[0].y};
  points[1] = {face.vertices[1].x, face.vertices[1].y};
  points[2] = {face.vertices[2].x, face.vertices[2].y};

  SDL_RenderLines(gRenderer, points, 4);

} // }}}

void DrawUtil::drawPolygonOutline(const std::vector<Vertex> &vertices) {
  // {{{
  std::vector<SDL_FPoint> points;
  for (const Vertex &v : vertices) {
    points.push_back({v.position.x, v.position.y});
  }
  points.push_back(points.front());

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);

  SDL_RenderLines(gRenderer, points.data(), points.size());

} // }}}

void DrawUtil::drawObject(const Object &obj) {
  for (int i = 0; i < obj.model.vertices.size(); i++) {
    // obj.model.triangles[i];
  }
}
