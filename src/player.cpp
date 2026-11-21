#include "quaternion.hpp"
#include "vector3.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_scancode.h>
#include <player.h>

Player::Player() {

  position = Vector3{0, 0, 0};
  color = SDL_Color{155, 0, 0, 255};
  radius = 20;
}

void Player::handleInput() {
  const bool *state = SDL_GetKeyboardState(nullptr);
  Vector3 moveVector;
  float x, y = 0;

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
  if (state[SDL_SCANCODE_LEFT]) {
    x = -0.05f;
  }
  if (state[SDL_SCANCODE_RIGHT]) {
    x = 0.05f;
  }
  if (state[SDL_SCANCODE_UP]) {
    y = -0.01f;
  }
  if (state[SDL_SCANCODE_DOWN]) {
    y = 0.01f;
  }
  rotate(x);
  move(moveVector);
  // rotateCamera(y);
}

// Basicaly does nothing... yet maybe checks colliision??
void Player::move(const Vector3 &move) {
  Vector3 newPos = rotation.rotate(move);
  position += newPos;
  camera.position = position;
  camera.rotation = rotation;
}

void Player::rotate(float b) {
  rotation = rotation * Quaternion::FromAxisAngle({0, 1, 0}, b);
};

void Player::rotateCamera(float b) {}
