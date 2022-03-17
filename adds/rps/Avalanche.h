#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef AVALANCHE_H
#define AVALANCHE_H


class Avalanche: public Computer {
    public:
    Avalanche();
    char makeMove();
};

#endif