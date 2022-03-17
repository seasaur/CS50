#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Computer.h"
#include "RandomComputer.h"

//constructor
RandomComputer::RandomComputer() {
}

char RandomComputer::makeMove() {
    srand ( time(NULL) );
    char array[3]={'R','P','S'};
    move = array[rand()%3-1];
    return move;
}

