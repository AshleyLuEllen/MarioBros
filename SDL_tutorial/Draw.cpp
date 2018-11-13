//
//  Draw.cpp
//  SDL_tutorial
//
//  Created by Ashley Lu Couch on 11/12/18.
//  Copyright © 2018 Ashley Lu Couch. All rights reserved.
//

#include <stdio.h>
#include "Draw.h"


void drawArray(SDL_Plotter & g, int s, int x_, int y_, int h, int w, Color **array){
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
