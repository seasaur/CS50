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

    for(int i=0;i<7;i++) { //each round
        for (int j=0;j<7;j+2) {
            competitors[j]->Referee();
            competitors[j+1]->Referee();
        }
    }

}

