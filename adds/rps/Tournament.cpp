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

Tournament::Tournament() {

}

Player Tournament::* run(std::array<Player *, 8> competitors){
    for(int i=0;i<5;i++) { //each round
        for int(j=0;j<8;j++) {
            competitors[i]->makeMove();
            // competitors[1]->makeMove();

            // competitors[3]->makeMove();
            // competitors[4]->makeMove();

            // competitors[5]->makeMove();
            // competitors[6]->makeMove();

            // competitors[7]->makeMove();
            // competitors[8]->makeMove();
        }
    }

}

