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
  lives = 3;
  score = 0;

  //Set players initial position
  plat.getPlayerOrgin(orgin);
  plat.getPlayerOrgin(position);

  //display image of player
  plot.displayImage(imageSurf,position.x, position.y);
  plot.update();
}

int Player::getHeight() const
{
  return height;
}

int Player::getWidth() const
{
  return width;
}

bool Player::isAlive()
{
  if(lives == 0)
    alive = false;
  return alive;
}

void Player::setAlive(bool a)
{
  alive = a;
}

bool Player::isJumping() const
{
  return jump;
}

void Player::setJump(bool j)
{
  jump = j;
}

int Player::getX() const
{
  return position.x;
}

int Player::getY() const
{
  return position.y;
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

bool Player::touchEnemy(platform& plat, int x, int y, int w, int h)
{
  bool touch = false;

  for(int dx = -(width / 2); dx <= (width / 2); dx++)
  {
    for(int dy = 0; dy <= height; dy++)
    {
      if(position.y - dy == y - (h / 2))
      {
        dy = height;
        if(position.x + dx == x + (w / 2) || position.x + dx == x - (w / 2))
          touch = true;
      }
    }
  }

  return touch;
}

void Player::die(SDL_Plotter& plot)
{
  lives -= 1;
  movePlayer(plot, orgin.x, orgin.y);
}

int Player::getScore()
{
  return score;
}

void Player::addScore(int s)
{
  score += s;
}

int Player::getLives() const
{
  return lives;
}
