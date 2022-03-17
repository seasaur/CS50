#include <iostream>
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

using namespace std;

int main() {
    // Human player1 = Human();
    // Computer player2 = Computer();
    // Referee referee = Referee();
    // RandomComputer random = RandomComputer();
    // Crescendo crescendo;
    // // // player1.makeMove();
    // // // player2.makeMove();
    // // // std::cout << referee.refGame(player1,player2) << std::endl;
    // std::cout << crescendo.makeMove() << std::endl;
    // crescendo.makeMove();

    Avalanche *player1 = new Avalanche();
    Bureaucrat *player2 = new Bureaucrat();
    Toolbox *player3 = new Toolbox();
    Crescendo *player4 = new Crescendo();
    PaperDoll *player5 = new PaperDoll();
    FistfullODollars *player6 = new FistfullODollars();
    RandomComputer *player7 =  new RandomComputer();
    Human *player8 = new Human();

    

}