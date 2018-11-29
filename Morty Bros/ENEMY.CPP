/*
Author:
Title: Enemy
Description: implementation of the class Enemy
Date Created: 11-29-2018
Date Last Modified: 11-29-2018
*/
 #include "Enemy.h"

 Enemy::Enemy(string type, int s, int i, SDL_Plotter& plot, platform& plat) {
  type = type;
  speed = s;
  isStanding = true;
  enemyImg = plot.loadImage(type + ".bmp");
  upsideDownImg = plot.loadImage(type + "Upside.bmp");
  height = enemyImg->h;
  width = enemyImg->w;
  position.x = 200;

  index = i;

  plat.enemySpawn(origin, width);
  position.x = origin[index].x;
  position.y = origin[index].y;
  }

bool Enemy::getStanding() {
  return isStanding;
}

void Enemy::addSpeed(int increment){
  speed += increment;
}

int Enemy::getSpeed(){
  return speed;
}

void Enemy::hit(SDL_Plotter& plot, int x, int y, int h){
  bool isHit = false;

  for(int dx = -(width / 2); dx <= (width / 2); dx++)
  {
    if(position.y + 13 >= y - h && position.y < y - h && position.x + dx == x)
      isHit = true;
  }

  if(isHit)
  {
    flipStanding();
    displayUpsideDown(plot);
  }
}

void Enemy:: flipStanding(){
 isStanding = !isStanding;
}

Point Enemy::getPos()
{
  return position;
}

int Enemy::getWidth()
{
  return width;
}

int Enemy::getHeight()
{
  return height;
}


void Enemy::moveEnemy(SDL_Plotter& plot,  platform& plat){

  if(getStanding())
  {
    for(int r = 0; r < height; r ++)
    {
      for(int c = 0; c < width; c++)
      {
        plot.plotPixel((position.x - (width / 2)) + c, position.y - r, 0, 0, 0);
      }
    }

    if(!plat.touchPlatform(position.x, position.y + 1, height, width))
      position.y += 2;

    if(plat.touchPortal(speed + position.x - (width / 2) , position.y - 40, 0, 2)
       || plat.touchPortal(speed + position.x + (width / 2) , position.y - 40, 0, 2))
       {
         die(plot, plat);
         flipStanding();
       }
    if(plat.touchWall(position.x + speed, position.y, height, width) ||
       plat.touchPortal(speed + position.x - (width / 2) , position.y - 40, 2, 4)
       || plat.touchPortal(speed + position.x + (width / 2) , position.y - 40, 2, 4))
        speed *= -1;

    for(int r = 0; r < height; r ++)
    {
      for(int c = 0; c < width; c++)
      {
        plot.plotPixel((position.x - (width / 2)) + c, position.y - r, 0, 0, 0);
      }
    }

    position.x += speed;

    plot.displayImage(enemyImg, position.x, position.y);
    plot.update();
  }
}

void Enemy::die(SDL_Plotter& plot,  platform& plat){
  for(int r = 0; r < height; r ++)
    {
      for(int c = 0; c < width; c++)
      {
        plot.plotPixel((position.x - (width / 2)) + c, position.y - r, 0, 0, 0);
      }
    }

  if(index == 0)
    index = 1;
  else
    index = 0;

  position.x = origin[index].x;
  position.y = origin[index].y;

  plot.displayImage(enemyImg, position.x, position.y);
  plot.update();
  flipStanding();
}

bool Enemy::touchEnemy(platform& plat, int x, int y, int w, int h)
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

void Enemy::displayUpsideDown(SDL_Plotter& plot)
{
  plot.displayImage(upsideDownImg, position.x, position.y);
}

