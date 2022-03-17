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

Tournament::Tournament() {

}

Player Tournament::* run(std::array<Player *, 8> competitors){
    Avalanche *player1 = new Avalanche();
    Bureaucrat *player2 = new Bureaucrat();
    Toolbox *player3 = new Toolbox();
    Crescendo *player4 = new Crescendo();
    PaperDoll *player5 = new PaperDoll();
    FistfullODollars *player6 = new FistfullODollars();
    RandomComputer *player7 =  new RandomComputer();
    Human *player8 = new Human();

    competitors[8] = {player1,player2,player3,player4,player5,player6,player7,player8};
    for(int i=0;i<5;i++) { //each round
        for (int j=0;j<8;j++) {
            competitors[i]->makeMove();
        }
    }

}

