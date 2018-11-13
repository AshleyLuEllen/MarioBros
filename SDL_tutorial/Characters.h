/*
 *
 *
 *
 *
 */
#ifndef UNTITLED1_CHARACTERS_H
#define UNTITLED1_CHARACTERS_H

#include <string>
#include "Color.h"


class MarioBro {
private:
    std::string name;


public:


};

class Enemy {
private:
    std::string type;
    bool isStanding = true;
    bool isWalking = true;
    int hits = 0;
    
    
    
    
    
    

public:
    Enemy(std::string & type_, int hit = 0);

    std::string getType();

    bool getStanding();
    void setStanding(bool stand);

    int getHits();
    void addHits();

    void hit();

    //
    void changeStand();

    void walking();

    void draw();



};



#endif //UNTITLED1_CHARACTERS_H
