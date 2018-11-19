/*
 *
 *
 *
 *
 */

#ifndef Draw_h
#define Draw_h

#include "SDL_Plotter.h"
#include "Color.h"


void drawArray(SDL_Plotter & g, int s, int x_, int y_, int h, int w, Color array[][20]);

void drawArrayFlip(SDL_Plotter & g, int s, int x_, int y_, int h, int w, Color array[][20]);

void drawBackground(SDL_Plotter & g);

void drawPickle(SDL_Plotter & g, int s, int x_, int y_, int h, int w);
void drawPickleFlip(SDL_Plotter & g, int s, int x_, int y_, int h, int w);


#endif /* Draw_h */
