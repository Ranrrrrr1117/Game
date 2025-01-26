#ifndef GAME3_RSP_H
#define GAME3_RSP_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

void printRule3();

int getPlayerChoice();

int getWizardChoice();

int displayResult(int playerChoice, int wizardChoice);
#endif