#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
/*
@brief Handles all helper functions
*
@field `*Window`
@field `*Renderer`
*/
class App {
public:
  App();
  /*
  @brief Inits SDL3 and windows
  */
  int init();
  /*
  @brief Cleans up resources and shutdown
  */
  void close();

  double deltaTime;

private:
};

#endif // !WINDOW_H
