/*
 *
 *
 *
 *
 */

#ifndef UNTITLED1_POW_H
#define UNTITLED1_POW_H

#include "Characters.h"


class Pow {
private:
    
    int state = 3;
public:

    //returns the state
    int getState() {
        return state;
    }
    //subtracts one from state
    void subState() {
        --state;
    }


};

#endif //UNTITLED1_POW_H
