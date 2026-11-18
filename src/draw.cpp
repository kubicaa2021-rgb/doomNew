#include "draw.h"
#include "globals.h"
#include "player.h"
#include "rect.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <algorithm>
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

  return whiteTex != 0;
} // }}}

void DrawUtil::drawRectangle(const Rect &rec) {
  // {{{
  SDL_SetTextureColorMod(whiteTex, rec.color.r, rec.color.g, rec.color.b);
  SDL_SetTextureAlphaMod(whiteTex, rec.color.a);

  SDL_FRect dstRect{rec.x, rec.y, rec.width, rec.height};

  SDL_RenderTexture(gRenderer, whiteTex, nullptr, &dstRect);
} // }}}

void DrawUtil::drawMap(const Map &map) {
  for (int i = 0; i < map.tiles.size(); i++) { // {{{
    for (int j = 0; j < map.tiles[i].size(); j++) {
      if (map.tiles[i][j] == 1) {
        Rect r(j * Map::kTileSize, i * Map::kTileSize, Map::kTileSize,
               Map::kTileSize, SDL_Color{255, 255, 255, 255});
        drawRectangle(r);
      }
    }
  }
} // }}}

// Only for 2D top down prototype
void DrawUtil::drawPlayer(const Player &pl) {
  // {{{
  // Draws player
  SDL_SetTextureColorMod(whiteTex, pl.color.r, pl.color.g, pl.color.b);
  SDL_SetTextureAlphaMod(whiteTex, pl.color.a);

  SDL_FRect dstRect{pl.position.x - pl.radius / 2.0f,
                    pl.position.y - pl.radius / 2.0f, pl.radius, pl.radius};

  SDL_RenderTexture(gRenderer, whiteTex, nullptr, &dstRect);

  // Draws direction
  //  int lineLength = 50;
  //  Vector2 lineEnd = {pl.position.x + std::cos(pl.direction) * lineLength,
  //                     pl.position.y + std::sin(pl.direction) * lineLength};
  //
  //  SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);
  //
  //  SDL_RenderLine(gRenderer, pl.position.x, pl.position.y, lineEnd.x,
  //  lineEnd.y);
  rayCastDebug(pl);
} // }}}

void DrawUtil::drawMap3D(const Map &map, const Player &pl) {
  //{{{

  for (int i = 0; i < kResolutionFOV; i++) {
    float rayDirection = (pl.direction - (kFOV / 2.0f)) +
                         ((kFOV / static_cast<float>(kResolutionFOV)) * i);
    // Get distance to wall
    float dist = rayCast(rayDirection, pl);

    // Set the color (brightness) of texture
    float color = 255 - ((dist / 10) * 5);
    SDL_SetTextureColorMod(whiteTex, color, color, color);
    SDL_SetTextureAlphaMod(whiteTex, 255);

    // Create the rectangle
    float xTile = static_cast<float>(kScreenWidth) / kResolutionFOV;
    float yMiddle = (kScreenHeight / 2.0f);
    float yOffset =
        (kScreenHeight -
         (static_cast<float>(kScreenHeight) / kDrawDistance) * dist) /
        2;

    SDL_FRect mapRect{xTile * i, yMiddle - yOffset, xTile, yOffset * 2};

    SDL_RenderTexture(gRenderer, whiteTex, nullptr, &mapRect);
  }
} // }}}

void DrawUtil::rayCastDebug(const Player &pl) {
  for (int i = 0; i < kResolutionFOV; i++) { // {{{
    float rayDirection = (pl.direction - (kFOV / 2.0f)) +
                         ((kFOV / static_cast<float>(kResolutionFOV)) * i);
    // Draws direction
    Vector2 lineEnd = {pl.position.x + std::cos(rayDirection) * kDrawDistance,
                       pl.position.y + std::sin(rayDirection) * kDrawDistance};
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);

    SDL_RenderLine(gRenderer, pl.position.x, pl.position.y, lineEnd.x,
                   lineEnd.y);
    rayCastCollisionDebug(rayDirection, pl);
  }
  return;
} // }}}

void DrawUtil::rayCastCollisionDebug(const float &rayDirection,
                                     const Player &pl) { // {{{

  for (int i = 0; i < kDrawDistance; i++) {
    Vector2 linePoint = {pl.position.x + std::cos(rayDirection) * i,
                         pl.position.y + std::sin(rayDirection) * i};

    Vector2 tiles = {linePoint.x / Map::kTileSize,
                     linePoint.y / Map::kTileSize};

    if (tiles.y > gMap->tiles.size() || tiles.x > gMap->tiles[0].size() ||
        tiles.x < 0 || tiles.y < 0) {
      continue;
    }

    if (gMap->tiles[tiles.y][tiles.x] == 1) {

      SDL_SetTextureColorMod(whiteTex, pl.color.r, pl.color.g, pl.color.b);
      SDL_SetTextureAlphaMod(whiteTex, pl.color.a);

      SDL_FRect dstRect{linePoint.x - 5, linePoint.y - 5, 10, 10};

      SDL_RenderTexture(gRenderer, whiteTex, nullptr, &dstRect);
      return;
    }
  }
  return;
} // }}}

float DrawUtil::rayCast(const float &rayDirection, const Player &pl) {
  // {{{
  for (int i = 0; i < kDrawDistance; i++) {
    Vector2 linePoint = {pl.position.x + std::cos(rayDirection) * i,
                         pl.position.y + std::sin(rayDirection) * i};
    Vector2 tiles = {linePoint.x / Map::kTileSize,
                     linePoint.y / Map::kTileSize};

    if (tiles.y > gMap->tiles.size() || tiles.x > gMap->tiles[0].size() ||
        tiles.x < 0 || tiles.y < 0) {
      continue;
    }

    if (gMap->tiles[tiles.y][tiles.x] == 1) {
      return i;
    }
  }
  return kDrawDistance;
} // }}}
