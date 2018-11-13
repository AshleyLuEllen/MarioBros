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


using namespace std;

const int GROUND_SCALE = 10;
const int SCALE = 5;


int main(int argc, char ** argv){
    
    Color c0(51, 92, 24),
    c1(63, 114, 28),
    c2(101, 144, 69),
    c3(40, 75, 15),
    c4(168, 229, 255),
    c5(BLACK),
    c6(141, 184, 212);
    
    Color pickleArray[18][6] = {
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
    
    
    
    SDL_Plotter g(800,1120);
    int x,y, xd, yd;
    
    //makes the background black
    for(x = 0; x < g.getCol(); x++ ){
        for(y = 0; y < g.getRow(); y++ ){
            g.plotPixel( x, y, BLACK);
        }
    }
    
    //Makes a gray bar at the bottom of the screen
    for(x = 0; x < g.getCol(); x++ ){
        for(y = 750; y < g.getRow(); y++ ){
            g.plotPixel( x, y, GRAY);
        }
    }
    
    //Makes an pixilated gray bar at the bottom on the screen
    for (x = 0; x < g.getCol(); x+=GROUND_SCALE){
        for (y = 750; y < g.getCol(); y+=GROUND_SCALE){
            int num = rand()%30+170;
            for(xd = 0; xd < GROUND_SCALE && x + xd < g.getCol(); xd++ ){
                for(yd = 0; yd < GROUND_SCALE && y + yd < g.getRow(); yd++ ){
                    g.plotPixel( x + xd, y + yd, num, num, num);
                }
            }
        }
    }
    
    //SDL_Plotter g, int scale, int xPosition, int yPosition, int array height, int array width, and the array
    
    //drawArray( g, SCALE, 100, 100, pickle.getHeight, pickle.getWidth, pickleArray);
    
    int height = 18;
    int width = 6;
    
    x = 100;
    y = 100;
    

    
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            for(int xd = 0; xd < SCALE && x + col * SCALE + xd < g.getCol(); xd++){
                for(int yd = 0; yd < SCALE && y + row * SCALE + yd < g.getRow(); yd++){
                    g.plotPixel( x + col * SCALE + xd, y + row * SCALE + yd, pickleArray[row][col]);
                }
            }
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
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
