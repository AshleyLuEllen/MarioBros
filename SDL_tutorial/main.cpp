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
    platform( g, 800, 1120);
    
    
    
    Color c0(51, 92, 24),
    c1(63, 114, 28),
    c2(101, 144, 69),
    c3(40, 75, 15),
    c4(168, 229, 255),
    c5(BLACK),
    c6(141, 184, 212);
    
    Color pickleArray[18][20] = {
        {Color(c5), Color(c2), Color(c1), Color(c0), Color(c3), Color(c5)},
        {Color(c2), Color(c0), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c4), Color(c4), Color(c4), Color(c6), Color(c0)},
        {Color(c2), Color(c5), Color(c0), Color(c0), Color(c5), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c1), Color(c3)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c1), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c1), Color(c0)},
        {Color(c2), Color(c0), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c3)},
        {Color(c0), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0)},
        {Color(c2), Color(c1), Color(c0), Color(c1), Color(c0), Color(c3)},
        {Color(c2), Color(c1), Color(c0), Color(c1), Color(c0), Color(c3)},
        {Color(c2), Color(c1), Color(c1), Color(c3), Color(c3), Color(c3)},
        {Color(c5), Color(c2), Color(c3), Color(c0), Color(c3), Color(c5)} };
    
    Objects pickle( 18, 6);
    
    
    
    //SDL_Plotter g, int scale, int xPosition, int yPosition, int array height,
    //int array width, and the array
    
    drawArray( g, SCALE, 100, 100, 18, 6, pickleArray);
    
    
    while (!g.getQuit()){
        
        
        
        g.update();
        if(g.kbhit()){
            g.getKey();
        }
    }
}


/*
 x = rand()%g.getCol();
 y = rand()%(g.getRow()/16)+750;
 
 
 
 Color object;
 x = rand()%g.getCol();
 y = rand()%g.getRow();
 
 for(xd = 0; xd < 10 && x + xd < g.getCol(); xd++ ){
    for(yd = 0; yd < 10 && y + yd < g.getRow(); yd++ ){
        //g.plotPixel( x + xd, y + yd, 255, 255, 255);
        g.plotPixel( x + xd, y + yd, WHITE);
    }
 }
 */
