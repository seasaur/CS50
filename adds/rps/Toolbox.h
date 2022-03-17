#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef TOOLBOX_H
#define TOOLBOX_H

class Toolbox: public Computer {
    public:
    Toolbox();
    char makeMove();
};

#endif