#include <iostream>
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
    char move;
    public:
    Player();
    char makeMove();
};

#endif