#include "tank.h"
#include <cmath>
#include <iostream>



bool Tank::Update(int const &target_x, int const &target_y) {

 if (count > 1 ){
  bullet.Update(target_x,target_y);
  count =0;
 } 
count++;

return bullet.Update(target_x,target_y);

}

std::vector<SDL_Point> Tank::GetBulletBody()
{
  return bullet.body;
}