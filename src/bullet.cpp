#include "bullet.h"
#include <iostream>

void Bullet::Update(int const &target_x, const int &target_y) {

    if (targetdead){return;}

float target_theta = atan((50-pos_y)/(50-pos_x));
float theta_dotdot = BangBangControl(target_theta - theta);

theta_dot = theta_dot + theta_dotdot;
theta = theta + theta_dot     + theta_dotdot/2;
pos_x = pos_x + speed*cos(target_theta);
pos_y = pos_y + speed*sin(target_theta);
body.emplace_back(SDL_Point{static_cast<int>(pos_x), static_cast<int>(pos_y)});
if ((pos_x == target_x) && (pos_y == target_y) ) { targetdead = true;}


}

float Bullet::BangBangControl(float const deltatheta)
{
    float corrective_angular_acceleration {0.0F};

    if (deltatheta > 0)
    {
        corrective_angular_acceleration = -1.0f;
    } else
    {
        corrective_angular_acceleration = -1.0f;    
    }

    return corrective_angular_acceleration;

}