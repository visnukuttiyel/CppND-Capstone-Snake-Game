#include "bullet.h"
#include <iostream>
#include <math.h>

void Bullet::Update() {

UpadatePosition();

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

void Bullet::UpadatePosition()
{
        
        

        theta = atan((target_position_.y-current_position.y)/(target_position_.x-current_position.x));
        b = (theta);
        a = current_position.y - b*current_position.x;
        current_position.x = current_position.x + speed*cos(theta)*BangBangControl(target_position_.x-current_position.x);
        current_position.y = EvaluateY(current_position.x);

        body.emplace_back(SDL_Point{static_cast<int>(current_position.x), static_cast<int>(current_position.y)});
        counter++;
        if (counter > trail_length)
        {
            counter--;
            body.erase(body.begin());
        } 
    
}
   
float Bullet::EvaluateY(float x)
{
    return (a + b*x);
 }

void Bullet::Reset()
{
    body.clear();
    counter = 0;
    current_position = start_position_;
    theta = atan((50-current_position.y)/(50-current_position.x));
    body.emplace_back(SDL_Point{static_cast<int>(current_position.x), static_cast<int>(current_position.y)});

}

void Bullet::SetTarget(int const &target_x, int const &target_y)
{
        target_position_.x = target_x;
        target_position_.y = target_y;
}

 std::vector<SDL_Point> Bullet::GetBulletBody()
 {
    return body;
 }
