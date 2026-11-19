#include "draw.h"
#include "face.hpp"
#include "funcHelp.h"
#include "globals.h"
#include "matrix4.hpp"
#include "player.h"
#include "vector2.hpp"
#include <SDL3/SDL.h>
#include <algorithm>

// window and functions handler
App app;
DrawUtil draw; // Drawing utils

Player player; // Player object
Face2D face;

int main(int argc, char *argv[]) {
  gPlayer = &player;

  Matrix4 m = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

  face.vertices[0] = {100, 200};
  face.vertices[1] = {200, 200};
  face.vertices[2] = {150, 300};

  if (app.init() == false) {
    SDL_Log("Unable to initialize program!\n");
    return 1;
  } else {
    // The quit flag
    bool quit{false};

    // The event data
    SDL_Event e;
    SDL_zero(e);

    // Delta time
    Uint64 lastFrameTime = SDL_GetTicksNS();

    // The main loop
    while (quit == false) {
      Uint64 frameStart = SDL_GetTicksNS();
      // Get event data
      while (SDL_PollEvent(&e) == true) {
        // If event is quit type
        if (e.type == SDL_EVENT_QUIT) {
          // End the main loop
          quit = true;
        }
      }

      // Delta time calculation
      gDeltaTime = (frameStart - lastFrameTime) / 1000.0;
      gDeltaTime = std::min(gDeltaTime, 0.05) + 1;
      lastFrameTime = frameStart;

      // player.handleInput();

      // Set the background color
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
      //  Clear the screen with the set color
      SDL_RenderClear(gRenderer);

      // Debug Only
      draw.drawPlayer(player);
      draw.drawTrinagleOutline(face);

      SDL_RenderPresent(gRenderer);
      // Update the surface
      SDL_UpdateWindowSurface(gWindow);

      // Clamping the FPS to kMaxFPS set in globals.h
      Uint64 elapsed = SDL_GetTicksNS() - frameStart;
      if (elapsed < gFrameTimeNS) {
        SDL_DelayNS(gFrameTimeNS - elapsed);
      }
    }
  }

  // Clean up
  app.close();
  return 0;
}
