/*
Author: Ashley Lu Couch
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
     /*
      description:   This is the Constructor for the enemy class. speed is set
                     to s and i is an index and initalizes scores to 0
      return:        none
      precondition:  plot is defined
      postcondition: the number images are loaded, and scores initalized
      */
    Enemy(string type, int s, int i, SDL_Plotter& plot, platform& plat);

     /*
      description:   This function returns weather or not the enemy is standing
      return:        bool
      precondition:  standing is defined
      postcondition: if the enemy is standing, true is returned, if it is not,
                     false is returned
      */
    bool getStanding();

     /*
      description:   This function flips the enemy sprite
      return:        void
      precondition:  standing is defined
      postcondition: standing is opposite of what it was before the enemy was
                     hit
      */
    void flipStanding();

     /*
      description:   This function checks wheather or not the enemy has been hit
      return:        void
      precondition:  called when the player hits the enemy
      postcondition: position and plotter are defined and calls flipStanding()
      */
    void hit(SDL_Plotter& plot, int x, int y, int h);

     /*
      description:   This function defines the movement speed of the enemy
      return:        void
      precondition:  the enemy's movement speed is defined
      postcondition: the enemy's movement speed is incresed
      */
    void addSpeed(int increment);
    
     /*
      description:   This function returns the enemy's movement speed
      return:        int
      precondition:  speed is defined
      postcondition: the movement speed is returned
      */
    int getSpeed();

     /*
      description:   This function returns the enemy's position
      return:        Point
      precondition:  position is defined
      postcondition: the enemy's position is returned
      */
    Point getPos();

     /*
      description:   This function returns the enemy's width
      return:        int
      precondition:  width is defined
      postcondition: the enemy's width is returned
      */
    int getWidth();

     /*
      description:   This function returns the enemy's height
      return:        int
      precondition:  height is defined
      postcondition: the enemy's height is returned
      */
    int getHeight();

     /*
      description:   This function moves the enemy forward
      return:        void
      precondition:  Plotter and platform are defined
      postcondition: the enemy will be moved based on movement speed
      */
    void moveEnemy(SDL_Plotter& plot,  platform& plat);

     /*
      description:   This function resets the enemy to original start
      return:        void
      precondition:  Plotter and platform are defined
      postcondition: the enemy is reset and to original conditions
      */
    void die(SDL_Plotter& plot,  platform& plat);

     /*
      description:   This function checks if the enemy is douching the player
      return:        void
      precondition:  plat, positions of palyer and width and height are defined
      postcondition: return true if the enemy is touching the player passed in
      */
    bool touchEnemy(platform& plat, int x, int y, int w, int h);

    void displayUpsideDown(SDL_Plotter& plot);

 };


#endif // Enemy_h



