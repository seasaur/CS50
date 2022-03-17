#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H


class Bureaucrat: public Computer {
    public:
    Bureaucrat();
    char makeMove();
};

#endif