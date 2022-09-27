#ifndef TANK_H
#define TANK_H

#include <vector>
#include "SDL.h"

class Tank {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Tank(int pos_x, int pos_y)
      : pos_x(pos_x),
        pos_y(pos_y) 
        {
           body.emplace_back(SDL_Point{static_cast<int>(pos_x), static_cast<int>(pos_y)});
        }

  void Update();
  int count{0};

  float speed{0.1f};
  const int frequency{40};
  
  std::vector<SDL_Point> body;

 private:
  int pos_x;
  int pos_y;
};

#endif