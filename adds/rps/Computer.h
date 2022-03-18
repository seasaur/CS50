#include "Player.h"
using namespace std;

#ifndef COMPUTER_H
#define COMPUTER_H

class Computer: public Player {
    // protected:
    // char move;
    public:
    Computer();
    virtual char makeMove();
};

#endif
