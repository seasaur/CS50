#include <iostream>

#include "Human.h"
#include <ctype.h>

Human::Human() {
}

char Human::makeMove() {
    char humanMove;
    std::cout << "Enter move: ";
    std::cin >> humanMove;
    move=toupper(humanMove);
    // std::cout << "human: " << move << std::endl;
    return move;

} 

// char Human::getMove() {
//     return move;
// }
