#include "globals.h"
#include <SDL3/SDL_render.h>

double gDeltaTime = 0;

// Global variables
SDL_Window *gWindow{nullptr};
SDL_Renderer *gRenderer{nullptr};
SDL_Texture *gWhiteTexture{nullptr};

Player *gPlayer{nullptr};

float gFrameTimeNS = 1'000'000'000.0 / kMaxFPS;
