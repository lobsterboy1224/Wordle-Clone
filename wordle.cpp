#include <iostream> 
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include "WordleBoard.h"
using namespace std;
#define PI 3.14
int main(){ 
	bool check = true;
	string guess = "hello";
	ifstream iffer("sgb-words.txt");
	string words[5757];
	//initializes the words to be picked from
	for(int i = 0; i < 5758; i++)
		iffer >> words[i];
	srand(time(NULL));
	int number = rand() % 5757 + 1;
	WordleBoard wordy(words[number]);

	cout << "Welcome to EOU Wordle!" << endl;

	//6 guesses
	for(int j = 0; j<6; j++){	
		while(check){
			cout << "Enter a word: ";
			getline (cin, guess);
			//checks to see if word is 5 letters, which it should be
			if (guess.length() == 5){
				//checks to see if word exists according to given file
				for (int k = 0; k<5758; k++){
					if (words[k] == guess){
						check = false;
					}
				}
				if (check == true)
					cout<<"Word must be real." << endl;
			}
			else
				cout<<"Word must be of length five."<<endl;
		}
		wordy.checkGuess(guess);
		if (guess != words[number])	
			check = true;
		else{
			cout << "you win! correct solution!" << endl;
			return 0;
		}
	}
	cout << "you lose!" << endl << "solution was: " << words[number] << endl;
}
