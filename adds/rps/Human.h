#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

#ifndef HUMAN_H
#define HUMAN_H

class Human: public Player {
    // private:
    // char move;
    public:
    Human();
    char makeMove();
    //char getMove();

};

#endif