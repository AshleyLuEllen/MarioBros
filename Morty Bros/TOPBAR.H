/*
Author: Ashley
Title: Player
Description: implementation of the class Player
Date Created: 11-20-2018
Date Last Modified: 11-20-2018
*/

#ifndef TOPBAR_H
#define TOPBAR_H

#include <SDL.h>
#include "SDL_Plotter.h"
#include <string>
#include "platform.h"

using namespace std;

class TopBar{
private:
  int scores[6];
  SDL_Surface* numbers[10];

public:
TopBar(SDL_Plotter& plot);

 void convertScore(int score, SDL_Plotter& plot, platform& plat);




};

#endif // TOPBAR_H
