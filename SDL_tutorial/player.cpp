/*
Author: Alejandro Navarro
Title: Player
Description: implementation of the class Player
Date Created: 11-20-2018
Date Last Modified: 11-20-2018
*/

#include "player.h"

Player::Player(SDL_Plotter& plot, platform& plat)
{
  //Date Abstraction
  imageSurf = plot.loadImage("rick.bmp");
  height = imageSurf->h;
  width = imageSurf->w;
  alive = true;
  jump = false;

  //Set players initial position
  plat.getPlayerOrgin(position);

  //display image of player
  plot.displayImage(imageSurf,position.x, position.y);
  plot.update();

  while(alive)
  {
    if(plot.kbhit())
    {
      if(plot.getKey() == 'W' || jump)
      {
        jump = true;
        movePlayer(plot, position.x, position.y - 1);
      }
      if(plot.getKey() == 'D')
      {
        movePlayer(plot, position.x + 3, position.y);
      }
      if(plot.getKey() == 'A')
      {
        movePlayer(plot, position.x - 3, position.y);
      }
      if(plot.getKey() == 'Q')
        alive = false;
    }
  }

}

int Player::getHeight()
{
  return height;
}

int Player::getWidth()
{
  return width;
}

void Player::movePlayer(SDL_Plotter& plot, int x, int y)
{
  for(int r = 0; r < height; r ++)
  {
    for(int c = 0; c < width; c++)
    {
      plot.plotPixel((position.x - (width / 2)) + c, position.y - r, 0, 0, 0);
    }
  }

  position.x = x;
  position.y = y;

  plot.displayImage(imageSurf, x, y);
  plot.update();
}
