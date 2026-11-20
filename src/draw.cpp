#include "draw.h"
#include "face.hpp"
#include "globals.h"
#include "object.h"
#include "player.h"
#include "vector2.hpp"
#include "vector3.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <cmath>
#include <vector>

DrawUtil::DrawUtil() {}

// Only for 2D top down prototype
void DrawUtil::drawPlayer(const Player &pl) {
  // {{{
  // Draws player

  SDL_FRect dstRect{pl.position.x - pl.radius / 2.0f,
                    pl.position.y - pl.radius / 2.0f, pl.radius, pl.radius};

  SDL_SetRenderDrawColor(gRenderer, pl.color.r, pl.color.g, pl.color.b,
                         pl.color.a);
  SDL_RenderRect(gRenderer, &dstRect);
  // Draws direction
  float lineLength = 50;
  Vector3 lineEnd = pl.camera.rotation.rotate({0, lineLength, 0});

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);

  SDL_RenderLine(gRenderer, pl.position.x, pl.position.y, lineEnd.x, lineEnd.y);
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

void DrawUtil::drawTrinagleOutlineVertexNDC(const std::vector<Vertex> face) {
  // {{{
  SDL_FPoint points[4];

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);

  points[3] = {face[0].position.x, face[0].position.y};
  points[0] = {face[0].position.x, face[0].position.y};
  points[1] = {face[1].position.x, face[1].position.y};
  points[2] = {face[2].position.x, face[2].position.y};

  SDL_RenderLines(gRenderer, points, 4);

} // }}}

void DrawUtil::drawObject(const Object &obj) {
  for (int i = 0; i < obj.model.vertices.size(); i++) {
    // obj.model.triangles[i];
  }
}
