#ifndef PLAYER_H
#define PLAYER_H

#include "vector2.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_pixels.h>

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
  Vector2 position;
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
