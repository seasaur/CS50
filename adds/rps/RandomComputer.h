#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H


class RandomComputer: public Computer {
    public:
    RandomComputer();
    char makeMove();
};

#endif