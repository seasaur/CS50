#include <iostream>
#include "Computer.h"
#include "Crescendo.h"
//constructor
Crescendo::Crescendo() {
    prevMove=0;
}

char Crescendo::makeMove() {
    char fMove[3] = {'P','S','R'};

    if(prevMove==3) {
        prevMove=0;
    }
    move=fMove[prevMove];
    prevMove++;
    //std::cout << prevMove << std::endl;


    return move;
}

    // for(int index=0;index<4;index++) {
    //     if(index==0) {
    //         i==0;
    //     }
    //     if(index==3) {
    //         i==0;
    //     }
    //     i++;