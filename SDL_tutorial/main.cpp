/*
 * main.cpp
 * This file is the one that
 *
 *
 */

#include <iostream>

#include "SDL_Plotter.h"
#include "Characters.h"
#include "Pow.h"
#include "Color.h"
#include "Draw.h"
#include "Objects.h"
#include "platform.h"

using namespace std;

int main(int argc, char ** argv){
    
    const int SCALE = 5;
    
    //create the window
    SDL_Plotter g(800,1120);
    
    //draw background and platform
    drawBackground(g);
    platform plat( g, 800, 1120);
    
    //SDL_Plotter g, int scale, int xPosition, int yPosition, int array height,
    //int array width, and the array
    
    int count = 0;
    int x = 100, y = 100;
    while (!g.getQuit()){
        ++ count;
        
        if (count % 100 > 0 && count % 100 < 70){
            
        }else {
            
        }
        
        
        drawPickleFlip( g, SCALE, x, y, 18, 6);
        drawPickle( g, SCALE, x, y, 18, 6);
        x+= SCALE;
        
        if (x > 1000){
            x=100;
            y += 150;
        }
        
        int x = 50, y = 50;
        g.displayImage(image, x, y);
        
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
}

