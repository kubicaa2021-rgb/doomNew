#ifndef PLAYER_H
#define PLAYER_H

#include "quaternion.hpp"
#include "vector3.hpp"
#include <SDL3/SDL_camera.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_pixels.h>

class Camera {
public:
  Vector3 position{0, 0, 0};
  Quaternion rotation{Quaternion::FromAxisAngle({1, 0, 0}, 0)};
  Matrix4 viewM;
  Matrix4 projectionM;
};

/**
 * @class Player
 * @brief Player object
 *
 * @field `Vector2 position`
 * @field `float radius`
 * @field `SDL_Color color`
 * @field `float direction` in radians
 */
class Player {
public:
  Player();
  Vector3 position;
  Camera camera;
  /**
   * @brief In radians
   */
  float direction{0};
  float radius;
  SDL_Color color;

  void handleInput();
  void move(int mv);
  void rotate(float b);

private:
  float speed{1};
};
#endif // !PLAYER_H
