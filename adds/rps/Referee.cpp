#include <iostream>

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

Referee::Referee() {
}

char Referee::refGame(Player *player1, Player *player2) {
    char iMove = player1->makeMove();
    char iiMove = player2->makeMove();
    // std::cout << "human: " << iiMove << std::endl;
    // std::cout << "computer: " << iMove << std::endl;

    if(iiMove=='R') {
        switch(iMove) {
            case 'R':
                return 'T';

            case 'P':
                return 'W';

            case 'S':
                return 'L';

            default:
                return 'E';

        }
    }

    if(iiMove=='P') {
        switch(iMove) {
            case 'R':
                return 'L';

            case 'P':
                return 'T';

            case 'S':
                return 'W';

            default:
                return 'E';

        }
    }

    if(iiMove=='S') {
        switch(iMove) {
            case 'R':
                return 'W';

            case 'P':
                return 'L';
            case 'S':
                return 'T';

            default:
                return 'E';

        }
    }
    return 'b'; //if everything breaks
}
