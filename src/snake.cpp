#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.
  
   UpdateBody(current_cell, prev_cell);

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  // if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
  //   UpdateBody(current_cell, prev_cell);
  // }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  theta = theta + delta_theta;
  if ((theta > THETA_MAX) || (theta < 0))
  {
    delta_theta = -delta_theta;
    theta = theta+delta_theta;

  } 


  
  body.clear();
  for(int i{-1};i<5;i++)
  {
      float delta_x = i*sin(theta);
      float delta_y = i*cos(theta);
      
      SDL_Point leg1{
      static_cast<int>(head_x+delta_x),
      static_cast<int>(head_y+delta_y)};

      SDL_Point leg2{
      static_cast<int>(head_x-delta_x),
      static_cast<int>(head_y+delta_y)};

      body.push_back(leg1);
      body.push_back(leg2);    
  }  
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}