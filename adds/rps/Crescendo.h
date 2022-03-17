#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef CRESCENDO_H
#define CRESCENDO_H

class Crescendo: public Computer {
    private:
    int prevMove;
    public:
    Crescendo();
    char makeMove();
};

#endif