#include <iostream>
#include <string>
#include <array>
#include "Player.h"
using namespace std;

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

class Tournament {
    private:
    string array;
    public:
    Tournament();
    void setPlayer();
    Player * run(std::array<Player *, 8>  competitors;


};

#endif