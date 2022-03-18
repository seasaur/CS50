#include <iostream>
#include <array>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include "Player.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "RandomComputer.h"
#include "Tournament.h"

int main() {
    Avalanche *player1 = new Avalanche();
    Bureaucrat *player2 = new Bureaucrat();
    Toolbox *player3 = new Toolbox();
    Crescendo *player4 = new Crescendo();
    PaperDoll *player5 = new PaperDoll();
    FistfullODollars *player6 = new FistfullODollars();
    RandomComputer *player7 =  new RandomComputer();
    RandomComputer *player8 = new RandomComputer();

    std::array<Player*, 8> competitors = {player1,player2,player3,player4,player5,player6,player7,player8};
    Tournament *Tournament;
    Tournament->run(competitors);

}