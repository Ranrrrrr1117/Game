#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game2_navigation.h"
using namespace std;

// Function: printRule2
// What it does: Prints the game rules to the console
// Inputs: None
// Outputs: None (but prints to the console)
void printRule2() {
    cout << "----------------------------------------------------------" << endl;
    cout << "****       Now you faces the navigation failure.      ****" << endl;
    cout << "****      Lost your way? Time to crack the code!      ****" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-* Rule *-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|          You need to input a two-digit number.         |" << endl;
    cout << "|        If your guess is larger than the answer,        |" << endl;
    cout << "|      then it will show that your guess is too large.   |" << endl;
    cout << "|  Otherwise, it will show that your guess is too small. |" << endl;
    cout << "|               You will have five chances.              |" << endl;
    cout << "|        Guess the digits right, zoom ahead 3 steps.     |" << endl;
    cout << "|           Wrong? Oops! Retreat 1 step instead!         |" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "|                  Welcome to the game.                  |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

// Function: guess2
// What it does: Implements the guessing part of the game
// Inputs: None (but takes user input from the console)
// Outputs: An integer representing the number of steps the player should move (3 if correct guess, -2 if incorrect)
int guess2() {
    srand(time(0));
    // Generate a random two-digit number
    int randomNumber = rand() % 90 + 10;

    int playerGuess;
    int attempts = 1;
    int lowerBound = 10;
    int upperBound = 99;

    // Main game loop
    while (true) {
        cout << "Guess the two-digit number: ";
        cin >> playerGuess;

        // Check if the player's guess is within the valid range
        if (playerGuess < lowerBound || playerGuess > upperBound) {
            cout << "Invalid input. Please enter a number between " << lowerBound << " and " << upperBound << "." << endl;
            continue;
        }

        cout << "Your attempts: " << attempts << endl;

         // Loop until the player has made 5 attempts
        while (attempts < 5) {
            // Check if the player's guess is correct
            if (playerGuess == randomNumber) {
                cout << "Correct! The answer is " << randomNumber << ". You tried " << attempts << " times." << endl;
                cout << "Forward 3 steps." << endl;
                break;
            } else if (playerGuess < randomNumber) {    // The player's guess is too low
                attempts++;
                lowerBound = playerGuess;
                cout << "Your guess is too small. The number is between " << lowerBound << " and " << upperBound << ". Please try again：";
                cin >> playerGuess;
                cout << "Your attempts: " << attempts << endl;
            } else {                                    // The player's guess is too high
                attempts++;
                upperBound = playerGuess;
                cout << "Your guess is too large. The number is between " << lowerBound << " and " << upperBound << ". Please try again：";
                cin >> playerGuess;
                cout << "Your attempts: " << attempts << endl;
            }
        }
        // Check if the player has used up all their attempts
        if (attempts == 5) {
            if (playerGuess == randomNumber) {          // The player's guess is correct
                cout << "Correct! The answer is " << randomNumber << "." << endl;
                cout << "Forward 3 steps." << endl;
                return 3;
            } else {                                   // The player's guess is incorrect
                cout << "Oops! You lose. The answer is " << randomNumber << "." << endl;
                cout << "Retreat 1 step." << endl;
                return -1;
            }
        } else {
            return 3;
        }
    }
}