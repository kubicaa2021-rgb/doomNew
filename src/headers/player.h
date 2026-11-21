#ifndef PLAYER_H
#define PLAYER_H

#include "quaternion.hpp"
#include "vector3.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_pixels.h>

class Camera {
public:
  Vector3 position{0, 0, 0};
  Quaternion rotation;
  Matrix4 viewM;
  Matrix4 projectionM;
};

/**
 * @class Player
 * @brief Player object
 *
 * @field `Vector3 position`
 * @field `float radius`
 * @field `SDL_Color color`
 * @field `Quaternion direction` in radians
 */
class Player {
public:
  Player();
  Vector3 position;
  Camera camera;
  Quaternion rotation;
  float radius;
  SDL_Color color;

  void handleInput();

private:
  void move(const Vector3 &move);
  void rotate(float b);
  void rotateCamera(float b);

  float speed{1};
};
#endif // !PLAYER_H
