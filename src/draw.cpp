#include "draw.h"
#include "face.hpp"
#include "globals.h"
#include "player.h"
#include "vector2.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <cmath>

DrawUtil::DrawUtil() { createWhiteTex(); }

bool DrawUtil::createWhiteTex() {
  SDL_Surface *surface = // {{{
      SDL_CreateSurface(1, 1, SDL_PIXELFORMAT_RGBA32);
  if (!surface)
    return false;

  SDL_FillSurfaceRect(surface, nullptr,
                      SDL_MapRGB(SDL_GetPixelFormatDetails(surface->format),
                                 nullptr, 255, 255, 255));

  whiteTex = SDL_CreateTextureFromSurface(gRenderer, surface);

  SDL_DestroySurface(surface);
  gWhiteTexture = whiteTex;

  return whiteTex != 0;
} // }}}

// Only for 2D top down prototype
void DrawUtil::drawPlayer(const Player &pl) {
  // {{{
  // Draws player
  SDL_SetTextureColorMod(gWhiteTexture, pl.color.r, pl.color.g, pl.color.b);
  SDL_SetTextureAlphaMod(gWhiteTexture, pl.color.a);

  SDL_FRect dstRect{pl.position.x - pl.radius / 2.0f,
                    pl.position.y - pl.radius / 2.0f, pl.radius, pl.radius};

  SDL_RenderTexture(gRenderer, gWhiteTexture, nullptr, &dstRect);

  // Draws direction
  int lineLength = 50;
  Vector2 lineEnd = {pl.position.x + std::cos(pl.direction) * lineLength,
                     pl.position.y + std::sin(pl.direction) * lineLength};

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);

  SDL_RenderLine(gRenderer, pl.position.x, pl.position.y, lineEnd.x, lineEnd.y);
} // }}}

void DrawUtil::drawTrinagle(const Face2D &face) {
  SDL_Vertex ver[3]; // {{{
  ver[0] = {face.vertices[0].x, face.vertices[0].y, 1, 0, 0, 1};
  ver[1] = {face.vertices[1].x, face.vertices[1].y, 0, 1, 0, 1};
  ver[2] = {face.vertices[2].x, face.vertices[2].y, 0, 0, 1, 1};

  SDL_RenderGeometry(gRenderer, gWhiteTexture, ver, 3, nullptr, 0);
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
