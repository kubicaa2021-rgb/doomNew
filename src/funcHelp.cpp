#include "funcHelp.h"
#include "globals.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

App::App() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "wayland");
  gWindow = SDL_CreateWindow("Particle Life", kScreenWidth, kScreenHeight, 0);
  gRenderer = SDL_CreateRenderer(gWindow, nullptr);
}

int App::init() {
  // {{{
  if (!gWindow) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s",
                 SDL_GetError());
    return false;
  }

  if (!gRenderer) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s",
                 SDL_GetError());
    return false;
  }

  return true;
} // }}}

void App::close() {
  // Destroy window{{{
  SDL_DestroyWindow(gWindow);
  SDL_DestroyRenderer(gRenderer);
  gWindow = nullptr;
  gRenderer = nullptr;

  // Quit SDL subsystems
  SDL_Quit();
} // }}}
