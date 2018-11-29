/*
Author: Ashley
Title: TopBar
Description: implementation of the class TopBar wich includes score
Date Created: 11-27-2018
Date Last Modified: 11-28-2018
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
  SDL_Surface* rickhead;
  SDL_Surface* black;

public:
    /*
     description:   Creates a TopBar, loads the images for numbers 0-9,
                    and initalizes scores to 0
     return:        none
     precondition:  plot is defined
     postcondition: the number images are loaded, and scores initalized
     */
    TopBar(SDL_Plotter& plot);
    
    /*
     description:   Convers int score to a char and displays the image to the window
     return:        none
     precondition:  score, plot, and play are all defined
     postcondition: the score is converted and the associated images are displayed
                    score is not altered
     */
    void convertScore(int score, SDL_Plotter& plot, platform& plat);

    /*
     description:   lives are displayed and set
     return:        none
     precondition:  lives, plot, and plat defined
     postcondition: lives are displayed and set
     */
void lives(int lives, SDL_Plotter& plot, platform& plat);



};

#endif // TOPBAR_H
