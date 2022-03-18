#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef PAPERDOLL_H
#define PAPERDOLL_H

class PaperDoll: public Computer {
    private:
    int prevMove;
    int count;
    public:
    PaperDoll();
    char makeMove();
};

#endif