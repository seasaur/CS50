#include <iostream>
#include "Computer.h"
#include "FistfullODollars.h"
//constructor
FistfullODollars::FistfullODollars() {
    prevMove=0;
}

char FistfullODollars::makeMove() {
    char fMove[3]={'R','P','P'};
     if(prevMove==3) {
        prevMove=0;
    }
    move=fMove[prevMove];
    prevMove++;
    //std::cout << prevMove << std::endl;


    return move;
    return move;
}

