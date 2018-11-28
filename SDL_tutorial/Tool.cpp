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
