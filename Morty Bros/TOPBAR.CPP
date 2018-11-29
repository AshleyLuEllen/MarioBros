
#include "topBar.h"

TopBar::TopBar(SDL_Plotter& plot)
{

  numbers[0] = plot.loadImage("0.bmp");
  numbers[1] = plot.loadImage("1.bmp");
  numbers[2] = plot.loadImage("2.bmp");
  numbers[3] = plot.loadImage("3.bmp");
  numbers[4] = plot.loadImage("4.bmp");
  numbers[5] = plot.loadImage("5.bmp");
  numbers[6] = plot.loadImage("6.bmp");
  numbers[7] = plot.loadImage("7.bmp");
  numbers[8] = plot.loadImage("8.bmp");
  numbers[9] = plot.loadImage("9.bmp");

  for(int i = 0; i < 6; i++)
    scores[i] = 0;

}

void TopBar::convertScore(int score, SDL_Plotter& plot, platform& plat){
  int num;
  Point p;
  p = plat.topBar(1);
  for (int x = 0; x < 6; x++){
    num = score % 10;
    score = score / 10;
    scores[x] = num;
  }

   for (int x = 0; x < 6 ; x++){
    plot.displayImage(numbers[scores[5 - x]], p.x + ((x + 1) *numbers[num]->w), p.y);
    p.x += 5;
  }
}

