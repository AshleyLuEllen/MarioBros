/*
Author: Alejandro Navarro
Title: Platform
Description: header file of the class platform
Date Created: 11-2-2018
Date Last Modified: 11-18-2018
*/

#include <iostream>
#include <SDL.h>
#include "SDL_Plotter.h"
#include "platform.h"

using namespace std;

int main(int argc, char ** argv)
{

    int rows = 800; //multiple of 10
    int cols = 1120; //multiple of 14

    SDL_Plotter g(rows, cols);
    platform plat(g, rows, cols);

    SDL_Surface* image = g.loadImage("Rick.bmp");
    cout << image->w << "x" << image->h << endl;





    int x = 50, y = 50;
    g.displayImage(image, x, y);

    while(g.getKey() != 'Q')
    {

      if(g.kbhit())
      {
        if(g.getKey() == 'W')
        {
          if(!plat.touchEdge(x, y - 82))
          {
            y -= 2;
          }
        }
        else if(g.getKey() == 'S')
        {
          if(!plat.touchEdge(x, y + 82))
          {
            y += 2;
          }
        }
        else if(g.getKey() == 'D')
        {
          if(!plat.touchEdge(x + 29, y))
          {
            x += 2;
          }
        }
        else if(g.getKey() == 'A')
        {
          if(!plat.touchEdge(x - 29, y))
          {
            x -= 2;
          }
        }

        g.displayImage(image, x, y);

      }

    	g.update();

    }


  return 0;

}
