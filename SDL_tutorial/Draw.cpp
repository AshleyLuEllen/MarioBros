/*
 *
 *
 *
 *
 */

#include <stdio.h>
#include "Draw.h"
#include "Color.h"
#include "Objects.h"


void drawArray(SDL_Plotter & g, int s, int x_, int y_, int h, int w, Color array[][20]){
    int height = h;
    int width = w;
    
    int x = x_;
    int y = y_;
    
    const int SCALE = s;
    
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            for(int xd = 0; xd < SCALE && x + col * SCALE + xd < g.getCol(); xd++){
                for(int yd = 0; yd < SCALE && y + row * SCALE + yd < g.getRow(); yd++){
                    g.plotPixel( x + col * SCALE + xd, y + row * SCALE + yd, array[row][col]);
                }
            }
        }
    }
}

void drawArrayFlip(SDL_Plotter & g, int s, int x_, int y_, int h, int w, Color array[][20]){
    int height = h;
    int width = w;
    
    int x = x_;
    int y = y_;
    
    const int SCALE = s;
    
    for(int row = height-1; row >= 0; row--){
        for(int col = width-1; col >= 0; col--){
            for(int xd = 0; xd < SCALE && x + col * SCALE + xd < g.getCol(); xd++){
                for(int yd = 0; yd < SCALE && y + row * SCALE + yd < g.getRow(); yd++){
                    g.plotPixel( x + col * SCALE + xd, y + row * SCALE + yd, array[height - row -1][col]);
                }
            }
        }
    }
}

void drawBackground(SDL_Plotter & g){
    
    int x,y, xd, yd;
    //makes the background black
    for(x = 0; x < g.getCol(); x++ ){
        for(y = 0; y < g.getRow(); y++ ){
            g.plotPixel( x, y, BLACK);
        }
    }
    g.update();
    
    const int GROUND_SCALE = 10;
    //Makes an pixilated gray bar at the bottom on the screen
    for (x = 0; x < g.getCol(); x+=GROUND_SCALE){
        for (y = 720; y < g.getRow(); y+=GROUND_SCALE){
            int num = rand()%30+170;
            for(xd = 0; xd < GROUND_SCALE && x + xd < g.getCol(); xd++ ){
                for(yd = 0; yd < GROUND_SCALE && y + yd < g.getRow(); yd++ ){
                    g.plotPixel( x + xd, y + yd, num, num, num);
                }
            }
        }
    }
    g.update();
}

void drawPickle(SDL_Plotter & g, int s, int x_, int y_, int h, int w){
    drawArray(g, s, x_, y_, 18 , 6, pickleArray);
}

void drawPickleFlip(SDL_Plotter & g, int s, int x_, int y_, int h, int w){
    drawArrayFlip(g, s, x_, y_, 18 , 6, pickleArray);
}









