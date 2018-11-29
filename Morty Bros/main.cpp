/*
Author: Alejandro Navarro
Title: Platform
Description: header file of the class platform
Date Created: 11-2-2018
Date Last Modified: 11-18-2018
*/

#include <iostream>
#include <SDL.h>
#include "SDL_Plotter.h"
#include "platform.h"
#include "player.h"
#include "Tool.h"
#include "Enemy.h"
#include "topBar.h"

using namespace std;

int main(int argc, char ** argv)
{

    int rows = 800; //multiple of 10
    int cols = 1120; //multiple of 14

    SDL_Plotter plot(rows, cols, true);
    platform plat(plot, rows, cols);
    Player player(plot, plat);
    Enemy pickle("picklerick", 1, 0, plot, plat);
    Enemy mrmeeseek("mrmeeseek", 2, 1, plot, plat);
    TopBar topBar(plot);

    //Initial sound
    plot.initSound("GameMusic.wav");

    Timer pTime(2), enemyTime(6), flipTime(4000), enemyTime2(8), flipTime2(4000);

    int airTime = 0, speed = 8;

    while(player.isAlive())
    {
      //Play sound
      plot.playSound("GameMusic.wav");

      //PLAYER CONTROL ********************************************************
      //jumping
      if(player.isJumping())
      {
        //Jumping
        if(!plat.touchPlatform(player.getX(), player.getY() - 1, player.getHeight(), player.getWidth()) && airTime < 200)
        {
          if(pTime.isComplete())
          {
            player.movePlayer(plot, player.getX(), player.getY() - 1);
            airTime++;
            pTime.reset();
          }
        }
        else
        {
         player.setJump(false);
         airTime = 0;
         speed = 5;
        }
      }
      //gravity
      else if(!plat.touchPlatform(player.getX(), player.getY() + 1, player.getHeight(), player.getWidth()))
      {
        if(pTime.isComplete())
        {
          player.movePlayer(plot, player.getX(), player.getY() + 1);
          pTime.reset();
        }
      }

      if(plot.kbhit() || (player.isJumping() && airTime % 10 == 0))
      {
        //Jump
        if(plot.getKey() == UP_ARROW)
        {
          player.setJump(true);
          speed = 3;
        }
        //Move Right
        else if(plot.getKey() == RIGHT_ARROW)
        {
          if(!plat.touchPlatform(player.getX() + speed, player.getY(), player.getHeight(), player.getWidth()))
          {
            player.movePlayer(plot, player.getX() + speed, player.getY());
          }
        }
        //Move Left
        else if(plot.getKey() == LEFT_ARROW)
        {
          if(!plat.touchPlatform(player.getX() - speed, player.getY(), player.getHeight(), player.getWidth()))
          {
            player.movePlayer(plot, player.getX() - speed, player.getY());
          }
        }
        if(plot.getKey() == 'Q')
          player.setAlive(false);
      }

      if(player.touchEnemy(plat, pickle.getPos().x, pickle.getPos().y, pickle.getWidth(), pickle.getWidth()) && pickle.getStanding())
      {
        player.die(plot);
      }
      else if(player.touchEnemy(plat, pickle.getPos().x, pickle.getPos().y, pickle.getWidth(), pickle.getWidth()) && !pickle.getStanding())
      {
        pickle.die(plot, plat);
        player.addScore(100);
      }

      if(player.touchEnemy(plat, mrmeeseek.getPos().x, mrmeeseek.getPos().y, mrmeeseek.getWidth(), mrmeeseek.getWidth()) && mrmeeseek.getStanding())
      {
        player.die(plot);
      }
      else if(player.touchEnemy(plat, mrmeeseek.getPos().x, mrmeeseek.getPos().y, mrmeeseek.getWidth(), mrmeeseek.getWidth()) && !mrmeeseek.getStanding())
      {
        mrmeeseek.die(plot, plat);
        player.addScore(200);
      }


    //END OF PLAYER ***********************************************************


    //Enemy: Pickle************************************************************
    if(enemyTime.isComplete() && pickle.getStanding())
    {
      pickle.moveEnemy(plot, plat);
      pickle.hit(plot, player.getX(), player.getY(), player.getHeight());
      enemyTime.reset();
      flipTime.reset();
    }else if(flipTime.isComplete())
    {
      pickle.flipStanding();
    }

    //Enemy: Mrmeseek**********************************************************
    if(enemyTime2.isComplete() && mrmeeseek.getStanding())
    {
      mrmeeseek.moveEnemy(plot, plat);
      mrmeeseek.hit(plot, player.getX(), player.getY(), player.getHeight());
      enemyTime2.reset();
      flipTime2.reset();
    }else if(flipTime2.isComplete())
    {
      mrmeeseek.flipStanding();
    }

    topBar.convertScore(player.getScore(), plot, plat);

  }

  plot.quitSound("GameMusic.wav");

  return 0;

}
