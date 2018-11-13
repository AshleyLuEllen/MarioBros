//
// Created by Ashley Lu Couch on 10/26/18.
//

#include <iostream>
#include "Characters.h"

using namespace std;

Enemy::Enemy(std::string & type_, int hit) {
  type = type_;
  hits = hit;
}

std::string Enemy::getType() {
  return type;
}

bool Enemy::getStanding() {
  return isStanding;
}

void Enemy::setStanding(bool stand) {
  isStanding = stand;
}


int Enemy::getHits() {
  return hits;
}

void Enemy::addHits() {
  ++hits;
}

void Enemy::hit() {
  isStanding = !isStanding;
  addHits();
}

void Enemy::draw(){
    const int ROW = 18, COLUMN = 6;
    Color c0(51, 92, 24),
    c1(63, 114, 28),
    c2(101, 144, 69),
    c3(40, 75, 15),
    c4(168, 229, 255),
    c5(BLACK),
    c6(141, 184, 212);
    Color Pickle[ROW][COLUMN] =
    {Color(c5), Color(c2), Color(c1), Color(c0), Color(c3), Color(c5),
                    Color(c2), Color(c0), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c4), Color(c4), Color(c4), Color(c6), Color(c0),
                    Color(c2), Color(c5), Color(c0), Color(c0), Color(c5), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c1), Color(c3),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c1), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c1), Color(c0),
                    Color(c2), Color(c0), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c3),
                    Color(c0), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c0), Color(c0), Color(c0),
                    Color(c2), Color(c1), Color(c0), Color(c1), Color(c0), Color(c3),
                    Color(c2), Color(c1), Color(c0), Color(c1), Color(c0), Color(c3),
                    Color(c2), Color(c1), Color(c1), Color(c3), Color(c3), Color(c3),
                    Color(c5), Color(c2), Color(c3), Color(c0), Color(c3), Color(c5)};
    
}
























void Enemy::walking() {
  int count = 0;
  int count2 = 0;
  while (isWalking){
    if (count == 0){
      cout << "WalkingSprite 0\n";
      count++;
    }
    else if (count == 1){
      cout << "WalkingSprite 1\n";
      count++;
    }
    else if (count == 2){
      cout << "WalkingSprite 2\n";
      count++;
    }
    else if (count == 3){
      cout << "WalkingSprite 3\n";
      count++;
    }else if (count == 4) {
      cout << "WalkingSprite 4\n";
      count = 0;
    }
  }

}
