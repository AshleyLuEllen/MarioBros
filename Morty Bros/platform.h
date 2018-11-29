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

struct Point
{
  int x, y;

  Point()
  {
    x = 0;
    y = 0;
  }

  Point(int a, int b)
  {
    x = a;
    y = b;
  }

};


class platform
{
  private:
  int rows,
      cols,
      yLevel[5], //Location of floor on the y axis
      xLevel[8][2],// Location of floor on the x axis
      portal[4][2];
  SDL_Surface* portalImg;

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
  description: default platform constructor.
  return: none
  precondition: SDL_Plotter exist and is initialized.
                r and c are existing integers.
  postcondition: a platform object is initialized.
  */
  platform(SDL_Plotter& p, int rows, int cols);

  /*
  description: creates or resets the platform for the game.
  return: none
  precondition: SDL_Plotter exist and is initialized.
  postcondition: a platform will appear on the screen.
  */
  void makePlatform(SDL_Plotter& p);

  /*
  description: determines if a certain
  return: bool
  precondition: x and y are existing integers.
  postcondition: integers x and y remain the same.
  */
  bool touchEdge(int x, int y);

  /*
  description: determines if a certain
  return: bool
  precondition: x, y, h, w are existing integers.
  postcondition: integers x, y, h, and w remain the same.
  */
  bool touchPlatform(int x, int y, int h, int w);

  /*
  description: set the player origin using the Point passed.
  return: void
  precondition: A Point has to exist.
  postcondition: Point origin will be set to contain the Player origin
  */
  void getPlayerOrgin(Point& orgin);

  /*
  description: returns true if an object makes contact with portal.
  return: bool
  precondition:
  postcondition:
  */
  bool touchPortal(int x, int y, int f, int l);

  /*
  description: returns true if the wall is touch
  return: bool
  precondition: the argument passed exist
  postcondition: the platform object remains the same.
  */
  bool touchWall(int x, int y, int h, int w);

  /*
  description: returns the points of the enemy spawn
  return: void
  precondition: point exist and the enemy width is included.
  postcondition: the platform object remains the same. 
  */
  void enemySpawn(Point p[], int enemyWidth);

  /*
  description: returns the points in the top bar.
  return: Point
  precondition: platform exist and is valid.
  postcondition: everything in the platform object remains the same.
  */
  Point topBar(int index);


};


#endif
