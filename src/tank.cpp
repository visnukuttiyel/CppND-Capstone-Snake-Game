#include "tank.h"
#include <cmath>
#include <iostream>



void Tank::Update() {
  
  if (count > 100)
  {
    std::cout<<"Rocket launched";
    count = 0;
  }
  count++;

}