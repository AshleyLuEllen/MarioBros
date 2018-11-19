
/*
Author: Alejandro Navarro & Ashley Lu Couch
Title: Main
Description: header file of the class platform
Date Created: 11-2-2018
Date Last Modified: 11-18-2018
*/

#include <iostream>
//#include <SDL.h>

#include "SDL_Plotter.h"
#include "Characters.h"
#include "Pow.h"
#include "Color.h"
#include "Draw.h"
#include "Objects.h"
#include "platform.h"

using namespace std;

int main(int argc, char ** argv)
{

    const int SCALE = 5;
    
    const int ROWS = 800; //multiple of 10
    const int COLS = 1120; //multiple of 14
    
    //create the window
    SDL_Plotter g(ROWS, COLS);
    
    //draw background and platform
    drawBackground(g);
    platform plat( g, ROWS, COLS);
    
    //SDL_Plotter g, int scale, int xPosition, int yPosition, int array height,
    //int array width, and the array
    
    //int count = 0;
    int x = 100, y = 100;
    


    SDL_Surface* image = g.loadImage("Rick.bmp");
    cout << image->w << "x" << image->h << endl;
    
    g.displayImage(image, x, y);

    while(g.getKey() != 'Q')
    {

      if(g.kbhit()){
        if(g.getKey() == 'W'){
          if(!plat.touchEdge(x, y - 82)){
            y -= 2;
          }
        }
        else if(g.getKey() == 'S'){
          if(!plat.touchEdge(x, y + 82)){
            y += 2;
          }
        }
        else if(g.getKey() == 'D'){
          if(!plat.touchEdge(x + 29, y)){
            x += 2;
          }
        }
        else if(g.getKey() == 'A'){
          if(!plat.touchEdge(x - 29, y)){
            x -= 2;
          }
        }

        g.displayImage(image, x, y);

      }

    	g.update();

    }


  return 0;

}
