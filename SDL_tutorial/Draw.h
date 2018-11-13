//
//  Draw.h
//  SDL_tutorial
//
//  Created by Ashley Lu Couch on 11/12/18.
//  Copyright © 2018 Ashley Lu Couch. All rights reserved.
//

#ifndef Draw_h
#define Draw_h

#include "SDL_Plotter.h"
#include "Color.h"

void drawArray(SDL_Plotter & g, int s, int x_, int y_, int h, int w, Color **array);

#endif /* Draw_h */
