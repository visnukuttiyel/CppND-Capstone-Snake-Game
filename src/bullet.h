#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "SDL.h"
#include <cmath>


constexpr float kPHI{3.14};

class Bullet
{
public:
    enum class Direction
    {
        kUp,
        kDown,
        kLeft,
        kRight
    };

    Bullet(int pos_x, int pos_y)
        : pos_x(pos_x),
          pos_y(pos_y)
    {
        body.emplace_back(SDL_Point{static_cast<int>(pos_x), static_cast<int>(pos_y)});
        theta = atan((50-pos_y)/(50-pos_x));
    }

    void Update(int const &target_x, int const &target_y);

    float life_time{2}; // 2s life time of the bullet

    float speed{0.0001f};
    float theta{kPHI / 4};
    float theta_dot{0.0f};
    bool targetdead{false};

    std::vector<SDL_Point> body;

private:
    float BangBangControl(float deltatheta);

    int pos_x;
    int pos_y;
};

#endif
