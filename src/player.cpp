#include "globals.h"
#include "vector2.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <cmath>
#include <player.h>

Player::Player() {

  position = Vector2{50, 50};
  color = SDL_Color{155, 0, 0, 255};
  radius = 20;
}

void Player::handleInput() {
  const bool *state = SDL_GetKeyboardState(nullptr);

  int mv{0};

  if (state[SDL_SCANCODE_W]) {
    mv = 1;
  }
  if (state[SDL_SCANCODE_S]) {
    mv = -1;
  }
  if (state[SDL_SCANCODE_A]) {
    rotate(-1);
  }
  if (state[SDL_SCANCODE_D]) {
    rotate(1);
  }
  move(mv);
}

// Basicaly does nothing... yet maybe checks colliision??
void Player::move(int mv) {
  Vector2 newPos = {
      static_cast<float>(this->position.x +
                         std::cos(this->direction) * mv * speed * gDeltaTime),
      static_cast<float>(this->position.y +
                         std::sin(this->direction) * mv * speed * gDeltaTime)};
  position = newPos;
}

void Player::rotate(float b) { direction += b * gDeltaTime / 10; }
