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
    results[]
    for(int i=0;i<7;i+2) { //each round
        for (int j=0;j<5;j++) {
            competitors[i]->Referee();
            competitors[i+1]->Referee();
        }
    }

}

