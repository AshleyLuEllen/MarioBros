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
  for(int xd = x1; xd < x2; xd++) {
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

  makeLine(p, xLevel[0][0], xLevel[0][1], yLevel[0]);

  //Second Level
  xLevel[1][0] = (cols /14) * 0;
  xLevel[1][1] = (cols / 14) * 5;
  yLevel[1] = (rows / 10) * 7;


  makeLine(p, xLevel[1][0], xLevel[1][1], yLevel[1]);

  xLevel[2][0] = (cols / 14) * 9;
  xLevel[2][1] = cols;

  makeLine(p, xLevel[2][0], xLevel[2][1], yLevel[1]);

  //Third Level
    //right edge
  xLevel[3][0] = 0;
  xLevel[3][1] = (cols / 14) * 2;
  yLevel[2] = (rows / 10) * 5;

  makeLine(p, xLevel[3][0], xLevel[3][1], yLevel[2]);

    //left edge
  xLevel[5][0] = (cols / 14) * 12;
  xLevel[5][1] = (cols / 14) * 14;

  makeLine(p, xLevel[5][0], xLevel[5][1], yLevel[2]);
    
    //middle
  xLevel[4][0] = (cols / 14) * 4;
  xLevel[4][1] = (cols / 14) * 10;
    yLevel[2] = (rows / 10) * 4.5;
  
  makeLine(p, xLevel[4][0], xLevel[4][1], yLevel[2]);

  //Fourth Level
  xLevel[6][0] = 0;
  xLevel[6][1] = (cols / 14) * 5.5;
  yLevel[3] = (rows / 10) * 2.5;

  makeLine(p, xLevel[6][0], xLevel[6][1] , yLevel[3]);

  xLevel[7][0] = (cols / 14) * 8.5;
  xLevel[7][1] = cols;

  makeLine(p, xLevel[7][0], xLevel[7][1], yLevel[3]);

  //Ceiling
  yLevel[4] = 0;
}

bool platform::touchEdge(int x, int y)
{
  bool isTouch = false;

  if(y <= yLevel[0] && y >= yLevel[0] - 1)//Check if coordinates touches the floor acounting thickness of platform
    isTouch = true;
  else if(y <= yLevel[1] && y >= yLevel[1] - 1)
  {
    if(x <= xLevel[1][1] || x >= xLevel[2][0])
      isTouch = true;
  }
  else if(y <= yLevel[2] && y >= yLevel[2] - 1)
  {
    if(x <= xLevel[3][1] || (x >= xLevel[4][0] && x < xLevel[4][1]) || x > xLevel[5][0])
      isTouch = true;
  }
  else if(y <= yLevel[3] && y >= yLevel[3] - 1)
  {
    if( x <= xLevel[6][1] || x >= xLevel[7][0])
      isTouch = true;
  }
  else if(y == yLevel[4])
    isTouch = true;

  return isTouch;
}
