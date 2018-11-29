/*
Author: Alejandro Navarro
Title: Platform
Description: implementation of the class platform
Date Created: 11-2-2018
Date Last Modified: 11-12-2018
*/


#include "platform.h"
#include "SDL_Plotter.h"


platform::platform(SDL_Plotter& p, int r, int c)
{
  rows = r;
  cols = c;
  portalImg = p.loadImage("portal.bmp");

  //Create black background
  for(int y = 0; y < rows; y++)
  {
    for(int x = 0; x < cols; x++)
    {
      p.plotPixel(x, y, 0, 0, 0);
    }
  }

  makePlatform(p);

}

void platform::makeLine(SDL_Plotter& p, int x1, int x2, int y)
{
  const int widthOfLine = 10;

  //Makes the line of a width of constant
  for(int xd = x1; xd <= x2; xd++) {
      for(int yd = 0; yd < widthOfLine; yd++ ){
          p.plotPixel( xd, y - yd, 100, 100, 255);
      }
  }

  p.update();
}

void platform::makePlatform(SDL_Plotter& p)
{

  //First Level
  xLevel[0][0] = 0;
  xLevel[0][1] = cols;
  yLevel[0] = (rows / 10) * 9;

  //Bottom left Portals
  portal[0][0] = (cols / 14);
  portal[0][1] = (rows / 10) * 9 - 20;

  p.displayImage(portalImg, portal[0][0], portal[0][1]);

  //Bottom Right Portals
  portal[1][0] = (cols / 14) * 13;
  portal[1][1] = ((rows / 10) * 9) - 20;

  p.displayImage(portalImg, portal[1][0], portal[1][1]);

  makeLine(p, xLevel[0][0], xLevel[0][1], yLevel[0]);

  //Second Level
  xLevel[1][0] = 0;
  xLevel[1][1] = (cols / 14) * 5;
  yLevel[1] = (rows / 10) * 7;


  makeLine(p, xLevel[1][0], xLevel[1][1], yLevel[1]);

  xLevel[2][0] = (cols / 14) * 9;
  xLevel[2][1] = cols;

  makeLine(p, xLevel[2][0], xLevel[2][1], yLevel[1]);

  //Third Level
  xLevel[3][0] = 0;
  xLevel[3][1] = (cols / 14) * 2;
  yLevel[2] = (rows / 10) * 5;

  makeLine(p, xLevel[3][0], xLevel[3][1], yLevel[2]);

  xLevel[4][0] = (cols / 14) * 4;
  xLevel[4][1] = (cols / 14) * 10;

  makeLine(p, xLevel[4][0], xLevel[4][1], yLevel[2]);

  xLevel[5][0] = (cols / 14) * 12;
  xLevel[5][1] = (cols / 14) * 14;

  makeLine(p, xLevel[5][0], xLevel[5][1], yLevel[2]);

  //Fourth Level
  xLevel[6][0] = 0;
  xLevel[6][1] = (cols / 14) * 6;
  yLevel[3] = (rows / 10) * 3;

  makeLine(p, xLevel[6][0], xLevel[6][1] , yLevel[3]);

  xLevel[7][0] = (cols / 14) * 8;
  xLevel[7][1] = cols;

  makeLine(p, xLevel[7][0], xLevel[7][1], yLevel[3]);

  //Top Left Portals
  portal[2][0] = (cols / 14);
  portal[2][1] = (rows / 10) * 3 - 20;

  p.displayImage(portalImg, portal[2][0], portal[2][1]);

  //Top right Portals
  portal[3][0] = (cols / 14) * 13;
  portal[3][1] = (rows / 10) * 3 - 20;

  p.displayImage(portalImg, portal[3][0], portal[3][1]);

  p.plotPixel(portal[2][0], portal[2][1], 255, 255, 255);

  //Ceiling
  yLevel[4] = (rows / 10);
}

bool platform::touchEdge(int x, int y)
{
  bool isTouch = false;

  if(y <= yLevel[0] && y >= yLevel[0] - 10)//Check is coordinates touches the floor acounting thickness of platform
    isTouch = true;
  else if(y <= yLevel[1] && y >= yLevel[1] - 10)
  {
    if(x <= xLevel[1][1] || x >= xLevel[2][0])
      isTouch = true;
  }
  else if(y <= yLevel[2] && y >= yLevel[2] - 10)
  {
    if(x <= xLevel[3][1] || (x >= xLevel[4][0] && x <= xLevel[4][1]) || x >= xLevel[5][0])
      isTouch = true;
  }
  else if(y <= yLevel[3] && y >= yLevel[3] - 10)
  {
    if( x <= xLevel[6][1] || x >= xLevel[7][0])
      isTouch = true;
  }
  else if(y == yLevel[4])
    isTouch = true;

  return isTouch;
}

bool platform::touchPlatform(int x, int y, int h, int w)
{
  bool isTouch = false;

  for(int dy = 0; dy <= h; dy++)
  {
    for(int dx = -(w/2); dx <= (w/2); dx++)
    {
      if(touchEdge(x + dx, y - dy) || touchPortal(x + dx, y - dy, 0, 4))
        isTouch = true;
    }
  }
  return isTouch;
}

bool platform::touchPortal(int x, int y, int f, int l)
{
  bool touch = false;
  for(int r = f; r < l; r++)
  {
   if(portal[r][0] - 3 - (portalImg->w / 2) <= x && x <= portal[r][0] + 3 + (portalImg->w / 2))
   {
    if(portal[r][1] >= y && y >= portal[r][1] - portalImg->h)
      touch = true;
   }
  }
  return touch;
}

void platform::getPlayerOrgin(Point& orgin)
{
   orgin.y = (rows / 10) * 8;
   orgin.x = (cols / 14) * 7;
}

bool platform::touchWall(int x, int y, int h, int w)
{
  bool inBound = false;

  if(0 > x - (w / 2) || x + (w / 2) > cols)
    inBound = true;

  return inBound;
}

void platform::enemySpawn(Point p[], int enemyWidth)
{
  int width = portalImg->w / 2;

  p[0].x = portal[2][0] + width + (enemyWidth / 2) + 4;
  p[0].y = portal[2][1] - 5;

  p[1].x = portal[3][0] - width - (enemyWidth / 2) - 4;
  p[1].y = portal[3][1] - 5;
}

Point platform::topBar(int index)
{
  Point p;
  if(index > 13 || index < 0)
      index = 1;

  p.x = (cols / 14) * index;
  p.y = yLevel[4] - 10;

  return p;
}
