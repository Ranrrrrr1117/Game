#include "game1_boom.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Function: generateRandomColor
// What it does: Generates a random color from the set {Red, Green, Blue, Yellow}
// Inputs: None
// Outputs: A string representing the randomly generated color
string generateRandomColor() {
    int randomNumber = rand() % 4;
    string color;
    switch (randomNumber) {
        case 0: color = "Red"; break;
        case 1: color = "Green"; break;
        case 2: color = "Blue"; break;
        case 3: color = "Yellow"; break;
    }
    return color;
}

// Function: printRule
// What it does: Prints the game rules to the console
// Inputs: None
// Outputs: None (but prints to the console)
void printRule() {
    cout << "----------------------------------------------------------" << endl;
    cout << "****             Warning! A bomb on board!            ****" << endl;
    cout << "**** Guess the correct color to defuse the explosive. ****" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-* Rule *-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|               There are four color options.            |" << endl;
    cout << "|     Guess the colors right to move forward 3 steps,    |" << endl;
    cout << "|               otherwise move back 2 spaces.            |" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "|                       Let's play!                      |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

// Function: toLowerCase
// What it does: Converts a string to lowercase
// Inputs: A string (str)
// Outputs: The input string converted to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function: Guess
// What it does: Implements the guessing part of the game
// Inputs: None (but takes user input from the console)
// Outputs: An integer representing the number of steps the player should move (3 if correct guess, -2 if incorrect)
int Guess() {
    cout << "Guess which color is correct（Red, Green, Blue, Yellow）：";
    string randomColor = generateRandomColor();
    string playerGuess;
    cin >> playerGuess;
    playerGuess = toLowerCase(playerGuess);
    // Validate the player's guess
    while (playerGuess != "red" && playerGuess != "green" && playerGuess != "blue" && playerGuess != "yellow"){
        cout << "Invalid. Options are Red, Green, Blue and Yellow. Please be careful of your spelling." << endl;
        cout << "Guess which color is correct（Red, Green, Blue, Yellow）：";
        cin >> playerGuess;
        playerGuess = toLowerCase(playerGuess);
    }
    // Check if the player's guess matches the random color
    if (playerGuess == toLowerCase(randomColor)) {
        cout << "Correct! The answer is " << randomColor << ". The bomb is successfully defused." << endl;
        cout << "Forward 3 steps." << endl;
        return 3;
    } else {
        cout << "Wrong! The answer is " << randomColor << ". Boooooom! The bomb explodes." << endl;
        cout << "Retreat 2 steps." << endl;
        return -2;
    }
}