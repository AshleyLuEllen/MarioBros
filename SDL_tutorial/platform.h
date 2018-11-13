/*
Author: Alejandro Navarro
Title: Platform
Description: header of the platform class
Date Created: 11-2-2018
Date Last Modified: 11-12-2018
*/

#ifndef PLATFORM_H
#define PLATFORM_H

#include "SDL_Plotter.h"

//No use
struct Point
{
  int x, y;

  Point(int a, int b)
  {
    x = a;
    y = b;
  }
};
//Delete later^

class platform
{
  private:
  int rows,
      cols,
      yLevel[5], //Location of floor on the y axis
      xLevel[8][2];// Location of floor on the x axis

  /*
  description: plots a flat line on the y-axis.
  return: none
  precondition: SDL_Plotter exist and is initialized.
                x- and y-coordinates exist in the table/screen.
  postcondition: pixels with a cetain color will be plotted.
  */
  void makeLine(SDL_Plotter& p, int x1, int x2, int y);



  public:
  /*
  description: creates or resets the platform for the game.
  return: none
  precondition: SDL_Plotter exist and is initialized.
  postcondition: a platform will appear on the screen.
  */
  void makePlatform(SDL_Plotter& p);

  /*
  description: default platform constructor.
  return: none
  precondition: SDL_Plotter exist and is initialized.
                r and c are existing integers.
  postcondition: a platform object is initialized.
  */
  platform(SDL_Plotter& p, int r, int c);

  /*
  description: determines if a certain
  return: bool
  precondition: x and y are existing integers.
  postcondition: integers x and y remain the same.
  */
  bool touchEdge(int x, int y);


};


#endif
