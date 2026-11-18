#include "globals.h"

double gDeltaTime = 0;

// Global variables
SDL_Window *gWindow{nullptr};
SDL_Renderer *gRenderer{nullptr};

Player *gPlayer{nullptr};
Map *gMap{nullptr};

float gFrameTimeNS = 1'000'000'000.0 / kMaxFPS;
