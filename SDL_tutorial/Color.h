//
//  Color.h
//  SDL_tutorial
//
/*
 *
 *
 *
 *
 */

#ifndef Color_h
#define Color_h

struct Color{
    int R, G, B;
    
    Color ( int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }
    
    Color (){
        R = 0; //rand()%256;
        G = 0; //rand()%256;
        B = 0; //rand()%256;
    }
    
};

const Color BLACK = {0, 0, 0},
        WHITE = {255, 255, 255},
        GRAY = {175, 175, 175},
        RED = {255, 0, 0},
        ORANGE = {255, 165, 0},
        YELLOW = {255, 255, 0},
        GREEN = {0, 255, 0},
        BLUE = {0, 0, 255},
        PURPLE = {128, 0, 128};

#endif /* Color_h */
