/*
Author: Alejandro Navarro
Title: Player
Description: header of the Player class
Date Created: 11-20-2018
Date Last Modified: 11-20-2018
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SDL.h>
#include <ctime>
#include "SDL_Plotter.h"
#include "platform.h"

using namespace std;

class Player
{
  private:
  Point position;
  int height, width;
  SDL_Surface* imageSurf;
  bool alive, jump;
  int lives, score, speed;

  /*
  */
  void movePlayer(SDL_Plotter& plot, int x, int y);

  public:
  /*
  description: default constructor for Player object.
  return: none
  precondition: The two arguements passed should contain the address of
                SDL_Plotter and platform.
                platform has to be initialized using SDL_Plotter first before
                initializing a Player object.
  postcondition: A Player object is created.
  */
  Player(SDL_Plotter& plot, platform& plat);

  /*
  */
  int getHeight();

  /*
  */
  int getWidth();




};

#endif //PLAYER_H
