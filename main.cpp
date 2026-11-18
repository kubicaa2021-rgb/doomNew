#include "draw.h"
#include "funcHelp.h"
#include "globals.h"
#include "map.h"
#include "player.h"
#include "vector2.hpp"
#include <SDL3/SDL.h>
#include <algorithm>

// window and functions handler
App app;
DrawUtil draw; // Drawing utils

Player player; // Player object

Map testMap; // Test map

int main(int argc, char *argv[]) {
  gPlayer = &player;
  gMap = &testMap;

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

      player.handleInput();

      // Set the background color
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
      //  Clear the screen with the set color
      SDL_RenderClear(gRenderer);

      draw.drawMap3D(testMap, player);

      // Debug Only
      // draw.drawMap(testMap);
      // draw.drawPlayer(player);

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
