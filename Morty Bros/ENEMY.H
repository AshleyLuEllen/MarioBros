/*
Author:
Title:
Description: specification of the class Enemy
Date Created: 11-29-2018
Date Last Modified: 11-29-2018
*/

#ifndef Enemy_h
#define Enemy_h

#include <SDL.h>
#include "SDL_Plotter.h"
#include "platform.h"
#include <string>

using namespace std;

 class Enemy {
private:
    bool isStanding;
    SDL_Surface* enemyImg, *upsideDownImg;
    int speed;
    Point position;
    int height, width;
    Point origin[2];
    int index;



public:
     
    Enemy(string type, int s, int i, SDL_Plotter& plot, platform& plat);

    bool getStanding();

    void flipStanding();

    void hit(SDL_Plotter& plot, int x, int y, int h);

    void addSpeed(int increment);

    int getSpeed();

    void changeStand();

    Point getPos();

    int getWidth();

    int getHeight();

    void moveEnemy(SDL_Plotter& plot,  platform& plat);

    void die(SDL_Plotter& plot,  platform& plat);

    bool touchEnemy(platform& plat, int x, int y, int w, int h);

 };


#endif // Enemy_h



