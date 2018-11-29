#include "Tool.h"

void waitMS(int ms)
{
  int ticks = clock() + ((ms * CLOCKS_PER_SEC) / 1000);
  int c = clock();

  while(c <= ticks)
  {
    c = clock();
  }
}

Timer::Timer(int ms)
{
  timeMS = ms;
  reset();
}

void Timer::reset()
{
  ticks = clock() + ((timeMS * CLOCKS_PER_SEC) / 1000);
  complete = false;
}

bool Timer::isComplete()
{
  if(clock() >= ticks)
    complete = true;

  return complete;
}

void Timer::setTimer(int ms)
{
  timeMS = ms;
  reset();
}
