#include <iostream>

#include "SDL_Plotter.h"
#include "Color.h"

using namespace std;

const int GROUND_SCALE = 10;
const int SCALE = 10;



int main(int argc, char ** argv){
    
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
    //drawArray( g, SCALE, 100, 100, 5, int w, Color **array)
    
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
