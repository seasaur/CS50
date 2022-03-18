#include <iostream>
#include "Computer.h"
#include "PaperDoll.h"
//constructor
PaperDoll::PaperDoll() {
    prevMove=0;
}

char PaperDoll::makeMove() {
    char fMove[3]={'P','S','S'};
    if(prevMove==3) {
        prevMove=0;
    }
    move=fMove[prevMove];
    prevMove++;
    count++;

    if(count==5) {
        prevMove=0;
        count=0;
    }
    return move;
}

