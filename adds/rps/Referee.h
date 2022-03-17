#include <iostream>
#include <string>
#include "Human.h"
#include "Computer.h"

using namespace std;

#ifndef REFEREE_H
#define REFEREE_H


class Referee {
    private:
    char checkMove;
    public:
    Referee() ;                      
    char refGame(Human player1, Computer player2);
};

#endif