#include <iostream>
#include <random>
#include "game5_surprise.h"
using namespace std;

// play5: playing the game: suprise (smash or not smash the egg)
// Input: input - players choice of smashing (y) or not smashing (n) the egg
// Output: Return an integer number of steps that player win or being punished
int play5() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);
    cout << "----------------------------------------------------------------------" << endl;
    cout << "**** Mid-flight, you stumble upon a mysterious airborne surprise! ****" << endl;
    cout << "****     A choice lies before you: smash the egg or leave it be   ****" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*  Rule -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|    Smashing it could bring rewards to make you forward 2 steps,    |" << endl;
    cout << "|            or bring punishments and slide back 2 steps.            |" << endl;
    cout << "|          Otherwise, you will stay at your current position         |" << endl;
    cout << "|   What will you do? (Input y for smashing and n for not smashing)  |" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "|                        Welcome to the game.                        |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    string input;
    bool validInput = false;
    cin >> input;
    while (!validInput) {
        if (input == "y") {
            int number = dis(gen);
            if (number == 1) {
                cout << "Congratulations, you've been rewarded!" << endl;
                cout << "Forward 2 steps." << endl;
                return 2;
            } else {
                cout << "Oh, no, you've been punished!" << endl;
                cout << "Retreat 2 steps." << endl;
                return -2;
            }
        } else if (input == "n") {
            cout << "Ah, you chose not to smash the egg." << endl;
            cout << "You stay at your current position." << endl;
            return 0;
        } else {
            cout << "Invalid input. Please input 'y' or 'n' for your choice" << endl;
            cin >> input;
        }
    }
    return 0;
}
