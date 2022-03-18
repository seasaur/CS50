#include <iostream>
#include <array>
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "RandomComputer.h"
#include "Tournament.h"
#include "Referee.h"

Tournament::Tournament() {

}

Player Tournament::* run(std::array<Player *, 8> competitors){
    Referee referee;
    char results[5];
    Player * winner[4];
    for(int i=0;i<7;i+2) { //matches players 1-2, 3-4, 5-6, 7-8
        for (int j=0;j<5;j++) { //each bracket plays 5 rounds
            results[j] = referee.refGame(competitors[i],competitors[i+1]);
        }
        
    }



}

