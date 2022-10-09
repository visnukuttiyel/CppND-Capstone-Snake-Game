#include "bullet.h"
#include <iostream>
#include <math.h>

bool Bullet::Update(int const &target_x, const int &target_y) {

if (targetdead){return targetdead;}
UpadatePath(target_x, target_y);
UpdatePosition();
if ((pos_y <0) || (pos_y > 100)||(pos_x <0) || (pos_x > 100))
{
    Reset();
}
body.emplace_back(SDL_Point{static_cast<int>(pos_x), static_cast<int>(pos_y)});
if ((std::abs(pos_x - target_x) < pos_error) && (std::abs(pos_y - target_y) < pos_error) ) { targetdead = true;}
counter++;
if (counter > 3)
{
    counter--;
    body.erase(body.begin());
} 
return targetdead;
}

float Bullet::BangBangControl(float const error)
{
    float corrective_action {0.0F};

    if (error > 0)
    {
        corrective_action = 1.0f;
    } else
    {
        corrective_action = -1.0f;    
    }

    return corrective_action;

}

void Bullet::UpadatePath(int const &target_x, const int &target_y)
{
    float a_current{a};
    float b_current{b};
    
      
    theta = atan((target_y-pos_y)/(target_x-pos_x));
    b = (theta);
    a = pos_y - b*pos_x;

    pos_x = pos_x + speed*cos(theta)*BangBangControl(target_x-pos_x);
    
    }

 void Bullet::UpdatePosition()
    {

    pos_y = EvaluateY(pos_x);
   

    }
    
float Bullet::EvaluateY(float x)
{
    return (a + b*x);
 }

void Bullet::Reset()
{
    body.clear();
    targetdead =false;
    counter = 0;
    pos_x = start_x;
    pos_y = start_y;
    theta = atan((50-pos_y)/(50-pos_x));
    body.emplace_back(SDL_Point{static_cast<int>(pos_x), static_cast<int>(pos_y)});

}
