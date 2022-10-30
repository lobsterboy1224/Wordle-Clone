#ifndef WORDLEBOARD_H
#define	WORDLEBOARD_H
#include <string>
using namespace std;
class WordleBoard {
	public:
		WordleBoard(string sol);
		~WordleBoard();
		void checkGuess(string guess);
		void printGuess();
		int letterColor(char guess, int k);
	private:
		string solution;
		int counter = 0;
		string letters[5][6];
		
};
#endif
