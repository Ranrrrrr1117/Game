#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <set>
#include "game4_hangman.h"
using namespace std;

// printRule4: print out the rules of game4: hangman to the screen
void printRule4(){
    cout << "    ----------------------------------------------------------------—------------------" << endl;
    cout << "    ****                         A hijacking is unfolding!                         ****" << endl;
    cout << "    ****     You are forced to participate in a life-or-death game of Hangman.     ****" << endl;
    cout << "    -----------------------------------------------------------------------------------" << endl;
    cout << "    *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* Rule *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "    | The screen will show a series of dashes that present the length of guessed word |" << endl;
    cout << "    |                      You need to enter a alphabet to guess.                     |" << endl;
    cout << "    |                      All the words are the names of Animal.                     |" << endl;
    cout << "    | However, for each incorrect letter guessed, an element will be added on hangman |" << endl;
    cout << "    |   If you correctly guessed all the letters before the hangman diagram, you win  |" << endl;
    cout << "    |                               otherwise, you lose.                              |" << endl;
    cout << "    |                      If you win you can move forward 2 steps!                   |" << endl;
    cout << "    |                       Lose? Oops! Retreat 1 step instead!                       |" << endl;
    cout << "    -----------------------------------------------------------------------------------" << endl;
    cout << "    |                              Welcome to the game.                               |" << endl;
    cout << "    *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- " << endl;
}

// play4: playing the game:hangman
// Input: guesses - guessing alphabets (one alphabet per time)
// Output: Return an integer number of steps that player win or being punished
int play4(vector<string>& words)
{
    string secret_word = get_random_word(words);
    string guess_word(secret_word.length(), '_');
    int try_no = 0;
    string guesses;
    set<char> guessed_letters;

    string* hangman_art = new string[7]{
        " +---+\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/    |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/ \\  |\n"
        "     |\n"
        "=========="
    };

    while (true)
    {
        cout << "Word: ";
        for (char c : guess_word)
        {
            cout << c << " ";
        }
        cout << "\nGuessed letters: ";
        for (char c : guessed_letters)
        {
            cout << c << " ";
        }
        cout << "\nEnter your guess: ";
        cin >> guesses;
        char guess;
        while(guesses.length() != 1 || !isalpha(guesses[0]))
        {
            cout << "Invalid input, please enter one alphabet."<<endl;
            cin >> guesses;
        }
        guess = guesses[0];

        if (guessed_letters.find(guess) != guessed_letters.end())
        {
            cout << "You already guessed that letter. Try again.\n";
            continue;
        }

        guessed_letters.insert(guess);

        bool found = false;
        for (int i = 0; i < secret_word.length(); ++i)
        {
            if (secret_word[i] == guess)
            {
                guess_word[i] = guess;
                found = true;
            }
        }

        if (!found)
        {
            ++try_no;
        }

        cout << hangman_art[try_no] << "\n";

        if (secret_word == guess_word)
        {
            cout << "You win! The word was " << secret_word << "." << "\n" << "Forward 2 steps!" << endl;
            return 2;
            break;
        }

        if (try_no >= 6)
        {
            cout << "You lost! The word was " << secret_word << "." << "\n" << "Retreat 1 step!" << endl;
            return -1;
            break;
        }
    }

    delete[] hangman_art;
}

// load_words_from_file: append all the words to the vector "words"
// Input: filename - files that have a wordlist
// Output: words - the vector that includes all the words from the wordlist.
vector<string> load_words_from_file(string filename)
{
    vector<string> words;
    ifstream file(filename);
    if (file.is_open())
    {
        string word;
        while (getline(file, word))
        {
            words.push_back(word);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << filename << "\n";
    }
    return words;
}

// get_random_word: get random word from the vector "words"
// Input: words - the vector that includes all the words from the wordlist.
// Output: a randomly selected word from the vector "words"
string get_random_word(vector<string>& words)
{
    return words[rand() % words.size()];
}
