#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "SDL.h"
#include <cmath>


constexpr float kPHI{3.14};
struct Point
{
    float x;
    float y;
};

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
    {
        start_position_.x = pos_x;
        start_position_.y = pos_y;
        Reset();
        
    }

    void SetTarget(int const &target_x, int const &target_y);

    std::vector<SDL_Point> GetBulletBody();
    bool GetTargetDead();

    void Update();



    float life_time{2}; // 2s life time of the bullet
    float speed{0.10f};
    float theta{kPHI / 4};
    float const trail_length{10};
    float const pos_error{0.1};

    Point current_position;
    float a{0};
    float b{0};
    int counter{0};

private:
    float BangBangControl(float deltatheta);
    void Reset();
    void UpadatePosition();
    float EvaluateY(float x);

    bool target_dead_{false};
    Point start_position_;
    Point target_position_;
    std::vector<SDL_Point> body;

};

#endif
