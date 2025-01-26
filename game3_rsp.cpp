#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game3_rsp.h"

using namespace std; 

// Function: printRule3
// What it does: Prints the game rules to the console
// Inputs: None
// Outputs: None (but prints to the console)
void printRule3() {
    cout << "----------------------------------------------------------" << endl;
    cout << "****    Your aircraft encounters a powerful storm.    ****" << endl;
    cout << "*** A wizard appears and presents you with a challenge ***" << endl;
    cout << "You must play game of Rock-Paper-Scissors with the wizard." << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-* Rule *-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|      Win, and you'll receive the wizard's blessing,    |" << endl;
    cout << "|           advancing your aircraft 2 spaces.            |" << endl;
    cout << "|                Lose, and you'll be cursed,             |" << endl;
    cout << "|        causing your aircraft to retreat 1 space.       |" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "|      Are you ready for the challenge? Let's begin!     |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

// Function: getPlayerChoice
// What it does: Gets the player's choice for the game of Rock-Paper-Scissors
// Inputs: None (but takes user input from the console)
// Outputs: An integer representing the player's choice (1 for Rock, 2 for Scissors, 3 for Paper)
int getPlayerChoice() {
    string input;
    int choice;
    cout << "Input 1 or 2 or 3 only. Choose your action（1.Rock 2.Scissors 3.Paper）：";
    cin >> input;
    // Loop until the user enters a valid choice
    while (true) {
        try {
            choice = stoi(input);
            // If the user's choice is valid, break out of the loop
            if (choice >= 1 && choice <= 3) {
                break;
            } else {
                // If the user's choice is not valid, throw an exception
                throw invalid_argument("Invalid input");
            }
        } catch (invalid_argument& e) {
            // If the user's input cannot be converted to an integer, prompt the user to enter a valid choice
            cout << "Invalid, please input 1/2/3 again." << endl;
            cout << "Choose your action 1/2/3（1.Rock 2.Scissors 3.Paper）：";
            cin >> input;
        }
    }
    return choice;
}

// Function: getWizardChoice
// What it does: Randomly generates the wizard's choice for the game of Rock-Paper-Scissors
// Inputs: None
// Outputs: An integer representing the wizard's choice (1 for Rock, 2 for Scissors, 3 for Paper)
int getWizardChoice() {
    srand(time(0));
    // Generate a random number between 1 and 3 and return it as the wizard's choice
    return rand() % 3 + 1;
}

// Function: displayResult
// What it does: Displays the result of the game of Rock-Paper-Scissors
// Inputs: Two integers representing the player's choice and the wizard's choice
// Outputs: An integer representing the result of the game (2 if the player wins, -1 if the wizard wins, 0 if it's a tie)
int displayResult(int playerChoice, int wizardChoice) {
    // Display the player's choice
    cout << "You choose：";
    if (playerChoice == 1) {
        cout << "Rock";
    } else if (playerChoice == 2) {
        cout << "Scissors";
    } else if (playerChoice == 3) {
        cout << "Paper";
    }
    cout << endl;

    // Display the wizard's choice
    cout << "The wizard chooses：";
    switch (wizardChoice) {
        case 1: cout << "Rock"; break;
        case 2: cout << "Scissors"; break;
        case 3: cout << "Paper"; break;
    }
    cout << endl;

    // Determine and display the result of the game
    if (playerChoice == wizardChoice) {
        cout << "It is a tie！" << endl;
        return 0;
    } else if ((playerChoice == 1 && wizardChoice == 2) ||
               (playerChoice == 2 && wizardChoice == 3) ||
               (playerChoice == 3 && wizardChoice == 1)) {
        cout << "Player wins！" << endl;
        return 2;
    } else {
        cout << "Wizard wins！" << endl;
        return -1;
    }
}