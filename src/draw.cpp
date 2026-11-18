#include "draw.h"
#include "globals.h"
#include "player.h"
#include "vector2.hpp"
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
  int lineLength = 50;
  Vector2 lineEnd = {pl.position.x + std::cos(pl.direction) * lineLength,
                     pl.position.y + std::sin(pl.direction) * lineLength};

  SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);

  SDL_RenderLine(gRenderer, pl.position.x, pl.position.y, lineEnd.x, lineEnd.y);
} // }}}
