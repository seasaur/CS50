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
    Player * winners[4];
    int winCount=0; //count for results array
    int loseCount=0;
    int winnerCount = 0; //winner array

    for(int i=0;i<7;i+2) { //ROUND 1 matches players 1-2, 3-4, 5-6, 7-8
        for (int j=0;j<5;j++) { //each bracket plays 5 rounds
            results[j] = referee.refGame(competitors[i],competitors[i+1]);
        }
        for(int k=0;k<5;k++) { //check number of wins & losses in terms of player with lower index
            if(results[k] == 'W') {
                winCount++;
            }
            if(results[k] == 'L') {
                loseCount++;
            }
        }
        if((winCount>loseCount) || (winCount==loseCount)) { //lower index player win or lose
            winners[winnerCount] = competitors[i];
        }
        }
        else {
            winners[winnerCount] == competitors[i+1];
        }
        winnerCount++;
        results[5] = {0};
    }

    for(int i=0;i<3;i+2) { //ROUND 2 matches winners 1-2 3-4
        for(int j=0;j<5;j++) {
            results[j] = referee.refGame(winners[i],competitors[i+1]);
        }
        for(int k=0;k<5;k++) { //check number of wins & losses in terms of player with lower index
            if(results[k] == 'W') {
                winCount++;
            }
            if(results[k] == 'L') {
                loseCount++;
            }
    }




}

