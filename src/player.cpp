#include "vector3.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <player.h>

Player::Player() {

  position = Vector3{0, 0, 0};
  color = SDL_Color{155, 0, 0, 255};
  radius = 20;
}

void Player::handleInput() {
  const bool *state = SDL_GetKeyboardState(nullptr);
  Vector3 moveVector;
  if (state[SDL_SCANCODE_W]) {
    moveVector.z = 1;
  }
  if (state[SDL_SCANCODE_S]) {
    moveVector.z = -1;
  }
  if (state[SDL_SCANCODE_A]) {
    moveVector.x = -1;
  }
  if (state[SDL_SCANCODE_D]) {
    moveVector.x = 1;
  }
  move(moveVector);
}

// Basicaly does nothing... yet maybe checks colliision??
void Player::move(const Vector3 &move) {
  Vector3 newPos = rotation.rotate(move);
  position += newPos;
  camera.position = position;
  camera.rotation = camera.rotation * rotation;
}

void Player::rotate(float b) {};
