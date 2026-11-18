#pragma once

#include "map.h"
#include "player.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
extern double gDeltaTime;

inline constexpr int kScreenWidth{900};
inline constexpr int kScreenHeight{600};

// Global variables
extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;

extern Player *gPlayer;
extern Map *gMap;

inline constexpr int kMaxFPS = 60;

// 2.5D Rendering settings
inline int kResolutionFOV = 90;
inline int kFOV = (M_PI / 3);
inline int kDrawDistance = 200;

extern float gFrameTimeNS;
