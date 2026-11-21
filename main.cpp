#include "draw.h"
#include "funcHelp.h"
#include "globals.h"
#include "object.h"
#include "player.h"
#include "quaternion.hpp"
#include "renderer.h"
#include "vertex.hpp"
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

// window and functions handler
App app;

Player player; // Player object

Object obj;
Object root;

int main(int argc, char *argv[]) {
  gPlayer = &player;
  gRoot = &root;

  obj.position = {0, 0, 1};

  float angle = 0;
  obj.rotation = Quaternion::FromAxisAngle({1, 0, 0}, 0);
  obj.scale = {1, 1, 1};

  Vertex v1 = {{0, -1, 0, 0}};
  Vertex v2 = {{1, 1, 0, 0}};
  Vertex v3 = {{-1, 1, 0, 0}};

  obj.model.vertices.emplace_back(v1);
  obj.model.vertices.emplace_back(v2);
  obj.model.vertices.emplace_back(v3);

  obj.updateModelMatrix();

  root.childs.emplace_back(&obj);

  Renderer::createProjectionM();

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
      angle += 0.1f;

      obj.rotation = Quaternion::FromAxisAngle({1, 0, 0}, angle);

      obj.updateModelMatrix();

      // Update Frame
      Renderer::update();

      DrawUtil::drawPlayer(player);

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
