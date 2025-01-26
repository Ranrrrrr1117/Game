#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <limits>
#include "game1_boom.h"
#include "game2_navigation.h"
#include "game3_rsp.h"
#include "game4_hangman.h"
#include "game5_surprise.h"

using namespace std;


const int BOARD_SIZE = 8;
const int TOTAL_STEPS = (BOARD_SIZE * 4) - 4;


// Initialize board：initializes the game board with '.' on the edges and ' ' in the middle
void initBoard(vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) {
                board[i][j] = '.';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}


// Continue_event: prompts the user to input 'c' to complete the current event
void continue_event()
{
	char bottom;
	cout << "Please input the 'c' to complete current event" <<endl;
	while(cin >> bottom)
	{
		if(bottom == 'c')
		{
			break;
		}
		else{
			cout << "Please input the 'c' to complete current event" <<endl;
		}
	}
}


// Function to calculate the index of the board based on the player's position
// Input: position (integer representing the player's position)
// Output: pair<int, int> representing the row and column indices of the board
pair<int, int> getBoardIndex(int position) {
    if (position < BOARD_SIZE) { 
        return make_pair(0, position); // Top row
    } else if (position < BOARD_SIZE * 2 - 1) { 
        return make_pair(position - BOARD_SIZE + 1, BOARD_SIZE - 1); // Right column
    } else if (position < BOARD_SIZE * 3 - 3) { 
        return make_pair(BOARD_SIZE - 1, BOARD_SIZE * 3 - 3 - position); // Bottom row
    } else { 
        return make_pair(BOARD_SIZE * 4 - 4 - position, 0); // Left column
    }
}


// DisplayBoard：displays the game board with player positions
// Input: board (const reference to a 2D vector of characters) 
//        player1Pos (integer representing player 1's position),player2Pos (integer representing player 2's position)
void displayBoard(const vector<vector<char>>& board, int player1Pos, int player2Pos) {
    cout <<"\x1B[2J\x1B[H"; //clear screen
	auto [p1Row, p1Col] = getBoardIndex(player1Pos);
    auto [p2Row, p2Col] = getBoardIndex(player2Pos);
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == p1Row && j == p1Col && i == p2Row && j == p2Col) {
                cout << "B "; // Both players are on the same position
            } else if (i == p1Row && j == p1Col) {
                cout << "1 "; // Only player 1 is on this position
            } else if (i == p2Row && j == p2Col) {
                cout << "2 "; // Only player 2 is on this position
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


// Roll dice：simulates rolling a dice and returns the result
// Output: Integer representing the dice roll result (1-6)
int rollDice() {
    return rand() % 6 + 1;
}


// Move players:moves the player's position based on the number of steps
// Input: playerPos (reference to an integer representing the player's position), 
//        steps (integer representing the number of steps to move)
void movePlayer(int& playerPos, int steps) {
    playerPos += steps;
    if (playerPos >= TOTAL_STEPS) {
        // playerPos -= TOTAL_STEPS; // This effectively sets the player back to the start.
        playerPos = 0;
    }
}


// AI random event function:performs a random event for the AI player
// Input: playerPos (reference to an integer representing the AI player's position)
void aiRandomEvent(int& playerPos) {
    int event = rand() % 6; // Generate a random number between 0 and 5
    
    switch (event) {
        case 0:
            playerPos += 2;
            cout << "Luckily win! Robot player moves forward 2 steps." << endl;
            break;
        case 1:
            playerPos += 1;
            cout << "Luckily win! Robot player moves forward 1 step." << endl;
            break;
        case 2:
            playerPos += 3;
            cout << "Luckily win! Robot player moves forward 3 steps." << endl;
            break;
        case 3:
            playerPos -= 2;
            cout << "Unluckily lose. Robot player moves backward 2 steps." << endl;
            break;
        case 4:
            playerPos -= 1;
            cout << "Unluckily lose. Robot player moves backward 1 step." << endl;
            break;
        case 5:
            playerPos -= 3;
            cout << "Unluckily lose. Robot player moves backward 3 steps." << endl;
            break;
    }
}


//EventPlay:performs a specific event based on the player's position
// Input: playersPos (reference to an integer representing the player's position), 
//        steps (integer representing the number of steps moved)
void eventPlay(int & playersPos, int steps){
    // random event 1 - boom
    if (playersPos == 5 || playersPos == 6){
        cout <<"\x1B[2J\x1B[H"; // clear screen
		printRule();
        playersPos += Guess();
        cout << "Steps updated " << playersPos << endl;
        continue_event();
    }

    // random event 2 - navigation
    if (playersPos == 10 || playersPos == 11){
        cout <<"\x1B[2J\x1B[H"; // clear screen
		printRule2();
        playersPos += guess2();
        cout<< "Steps updated " << playersPos << endl;
        continue_event();
    }

    // random event 3 - rsp
    if (playersPos == 15 || playersPos == 16){
        cout <<"\x1B[2J\x1B[H"; // clear screen
		
		int playerWins = 0;
        int wizardWins = 0;

        printRule3();

        while (true) {
            int playerChoice = getPlayerChoice();
            int wizardChoice = getWizardChoice();

            int result = displayResult(playerChoice, wizardChoice);

            if (result == 2) {
                playerWins++;
            } else if (result == -1) {
                wizardWins++;
            }
            cout << "Player v.s. Wizard " << playerWins << " : " << wizardWins << endl;
            if (wizardWins == 2 || playerWins == 2) {
                break;
            }
        }

        if (playerWins >= 2) {
            playersPos += 2;
            cout << "You win the game!" << endl;
            cout << "Foward 2 steps." << endl;
        } else if (wizardWins >= 2) {
            playersPos -= 1;
            cout << "You lose the game!" << endl;
            cout << "Retreat 1 step." << endl;
        }
            cout << "Steps updated: " << playersPos << endl;
            continue_event();
    }

    // random event 4 - hangman
    if (playersPos == 20 || playersPos == 21){
        cout <<  "\x1B[2J\x1B[H"; // clear screen
		printRule4();
        srand(time(0));///
        vector<string> words = load_words_from_file("wordlist.txt");
        playersPos += play4(words);
        cout << "Steps updated: " << playersPos << endl;
        continue_event();
    }

    // random event 5 - surprise
    if (playersPos == 25 || playersPos == 26){
        cout <<  "\x1B[2J\x1B[H"; //clear screen
		playersPos += play5();
        cout << "Steps updated: " << playersPos << endl;
		continue_event();
    }
}


int main() {
    srand((unsigned)time(NULL));  // random seed

    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE));
    initBoard(board);// Initialize the game board

    int player1Pos = 0;// Initialize player 1's position to 0
    int player2Pos = 0;// Initialize player 2's position to 0
    bool player1Finished = false; // Flag to indicate if player 1 has finished
    bool player2Finished = false; // Flag to indicate if player 2 has finished
    
    // Let user choose mode
    int gameMode;
    cout << "Select game mode:" << endl;
    cout << "1. Single Player" << endl;
    cout << "2. Two Players" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> gameMode;
    displayBoard(board, player1Pos, player2Pos);// Display the initial game board


    while (true) {
        // Player 1's turn
        cout << "Player 1, enter 'r' to roll the dice..." << endl;
        char input;
        cin >> input;
        while (input != 'r') {
            cout << "Invalid input. Please enter 'r' to roll the dice: ";
            cin >> input;
        }

        int steps = rollDice();// Roll the dice and get the number of steps
        cout << "Player 1 rolled a " << steps << endl;
        movePlayer(player1Pos, steps);// Move player 1 based on the dice roll
        cout << "The position of Player 1 is " << player1Pos << endl;
	sleep(2);// Pause for 2 seconds
        if (player1Pos == 0) {
            player1Finished = true; // Player 1 has finished the round
        }
	eventPlay(player1Pos,steps);
        if (gameMode == 1) {
            // AI (Player 2) turn, automatically rolls and moves
            steps = rollDice();
            cout << "Robot player rolled a " << steps << endl;
            movePlayer(player2Pos, steps);
            cout << "The position of Robot player is " << player2Pos << endl;
	    sleep(2);
            if (player2Pos == 0) {
                player2Finished = true; // Player 2 has finished the round
            }

            // Check if AI lands on specific positions
            if (player2Pos == 5 || player2Pos == 6 || player2Pos == 10 || player2Pos == 11 || player2Pos == 15 || player2Pos == 16 || player2Pos == 20 || player2Pos == 21 || player2Pos == 25 || player2Pos == 26) {
                aiRandomEvent(player2Pos);// Trigger a random event for the AI player
                cout << "The updated position of Robot player is " << player2Pos << endl;
            }
	    sleep(2);	
	    displayBoard(board, player1Pos, player2Pos);

        } else {
            // Player 2's turn
	    sleep(2);
            displayBoard(board, player1Pos, player2Pos);
            
            cout << "Player 2, enter 'r' to roll the dice..." << endl;
            cin >> input;
            while (input != 'r') {
                cout << "Invalid input. Please enter 'r' to roll the dice: ";
                cin >> input;
            }
       
            steps = rollDice();
            cout << "Player 2 rolled a " << steps << endl;
            movePlayer(player2Pos, steps);
            cout << "The position of Player 2 is " << player2Pos << endl;
            // cout << player2Pos << endl;
	    sleep(2);
            if (player2Pos == 0) {
                player2Finished = true; // Player 2 has finished the round
            }
	    eventPlay(player2Pos, steps); // Check Player 2 random events
            displayBoard(board, player1Pos, player2Pos);
        }
        // Check for game ending conditions
        if (player1Finished && player2Finished) {
            displayBoard(board, player1Pos, player2Pos);// Display the final game board
            cout << "It's a tie!" << endl;
            break;// End the game if both players have finished
        } else if (player1Finished) {
            displayBoard(board, player1Pos, player2Pos);
            cout << "Player 1 wins!" << endl;
            break; // End the game if player 1 has finished
        } else if (player2Finished) {
            displayBoard(board, player1Pos, player2Pos);
            if (gameMode == 1) {
                cout << "Robot player wins!" << endl;
            } else {
                cout << "Player 2 wins!" << endl;
            }
            break;// End the game if player 2 or the AI player has finished
        }
        }

    return 0;    
}


