/*
*/

#ifndef TOOL_H
#define TOOL_H

#include <ctime>

/*
desription: waits in the form of miliseconds
return: void
precondition: ms has to be a valid integer.
postcondition: the argument pass determines the time elapse in miliseconds
               since the function was called.
*/
void waitMS(int ms);

class Timer
{
  private:
  int timeMS;
  int ticks;
  bool complete;

  public:
  Timer(int ms);

  void reset();

  bool isComplete();

  void setTimer(int ms);

};

#endif //TOOL_H
