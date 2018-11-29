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
    /*
     description:   This function resets the enemy to original start
     return:        void
     precondition:  Plotter and platform are defined
     postcondition: creates a timer
     */
  Timer(int ms);

    /*
     description:   restes the timer complete is false
     return:        void
     precondition:  Plotter and platform are defined
     postcondition: restes the timer complete is false
     */
  void reset();

    /*
     description:   returns the value of complete
     return:        bool
     precondition:  complete is defined
     postcondition: complete is returned
     */
  bool isComplete();

    /*
     description:   This function resets the enemy to original start
     return:        void
     precondition:  ms is defined
     postcondition: the enemy is reset and to original conditions
     */
  void setTimer(int ms);

};

#endif //TOOL_H
