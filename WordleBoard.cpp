
#include "WordleBoard.h"
#include <iostream>
#include <sstream> 
#include <string>
using namespace std;
//class constructor
WordleBoard::WordleBoard(string sol) {
	solution = sol;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j<5; j++){
			//fills array so that it prints "_" in board spaces where there have been no guesses yet
			letters[j][i] = '_';
		}
	}
}
//checks guess by calling to letterColor class then formats the letter based on returned color.
//then prints wordle board with given guess
void WordleBoard::checkGuess(string guess){
	int color;	
	for (int k = 0; k<5; k++){
		color = letterColor(guess.at(k), k);
		//allows proper formatting of color
		string guesser(1,guess.at(k));
		//format letter to be green
		if (color == 1)
			letters[k][counter] = "\033[1;32m" + guesser + "\033[0m";
		//format color to be yellow
		else if(color == 2)
			letters[k][counter] = "\033[1;33m" + guesser + "\033[0m";
		//letter has no color
		else
			letters[k][counter] = guess.at(k);
	}
	counter++;
	printGuess();
}
//prints an wordle board. as game progresses, letters[x][y] gets filled with guesses, so by the end,
//if the word isn't guessed, the board should be filled. intitially letters[x][y] is full of "_"'s
void WordleBoard::printGuess(){
	for (int m = 0; m<6; m++)
		cout << m+1 << " " << letters[0][m] << " " << letters[1][m] << " " << letters[2][m] << " " << letters[3][m] << " " << letters[4][m] << endl;
}
//checks guess, if correct letter in wrong spot returns int representation of yellow letter.
//if correct letter in correct spot, returns int representation of green letter. else returns 0.
int WordleBoard::letterColor(char guess, int k){
	//right letter right spot
	if(guess == solution.at(k))
			return 1;	
	for(int x = 0; x<5; x++){
		//right letter wrong spot
		if(guess == solution.at(x))
			return 2;
	}
	//no matching letter
	return 0;
}
//class destructor
WordleBoard::~WordleBoard() {
}

