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
        : start_x(pos_x),
          start_y(pos_y)
    {
        Reset();
        
    }

    void Update(int const &target_x, int const &target_y);

    float life_time{2}; // 2s life time of the bullet

    float speed{0.50f};
    float theta{kPHI / 4};
    bool targetdead{false};

    std::vector<SDL_Point> body;

    float pos_x;
    float pos_y;
    float a{0};
    float b{0};

private:
    float BangBangControl(float deltatheta);
    void Reset();
    void UpadatePath(int const &target_x, const int &target_y);
    void UpdatePosition();
    float EvaluateY(float x);
    float start_x;
    float start_y;


  

};

#endif
