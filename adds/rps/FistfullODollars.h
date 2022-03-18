#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef FISTFULLODOLLARS_H
#define FISTFULLODOLLARS_H

class FistfullODollars: public Computer {
    private:
    int prevMove;
    int count;
    public:
    FistfullODollars();
    char makeMove();
};

#endif