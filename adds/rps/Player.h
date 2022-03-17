#include <iostream>
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    protected:
    char move;
    public:
    Player();
    char makeMove();
};

#endif