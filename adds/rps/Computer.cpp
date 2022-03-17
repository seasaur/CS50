#include <iostream>
#include "Player.h"
#include "Computer.h"

//constructor
Computer::Computer() {
}

char Computer::makeMove() {
    move='R';
    // std::cout << "computer: " << move << std::endl;
    return move;
}

// char Computer::getMove() {
//     return move;
// }


