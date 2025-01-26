#ifndef GAME4_HANGMAN_H
#define GAME4_HANGMAN_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <set>

using namespace std;

void printRule4();

vector<string> load_words_from_file(string filename);

string get_random_word(vector<string>& words);

int play4(vector<string>& words);

#endif