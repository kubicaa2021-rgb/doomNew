#pragma once

#include "object.h"
#include "player.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
extern double gDeltaTime;

inline constexpr int kScreenWidth{900};
inline constexpr int kScreenHeight{600};

inline constexpr int kFOV = 90;
inline constexpr float kNearClipping = 0.1f;
inline constexpr float kFarClipping = 100;

// Global variables
extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern Player *gPlayer;
extern Object *gRoot;

inline constexpr int kMaxFPS = 60;

extern float gFrameTimeNS;
