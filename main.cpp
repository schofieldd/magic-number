/**
 * Author:	Carlos R. Arias
 * Class:	CSC 2330 Data Structures and Programming
 * Date:	September 23 / 2020
 * Purpose:	A simple number guessing game
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main() {
	srand(time(0));

	int numberToGuess;
	int userGuess;
	int maximumGuesses, maximumToGuess;
	bool won = false;
	int keepGoing = 0;

	do{
		cout << "What is the maximum number to guess: ";
		cin >> maximumToGuess;
		cout << "How many opportunities you want: ";
		cin >> maximumGuesses;

		numberToGuess = rand() % maximumToGuess + 1;
		cout << "- - - - " << numberToGuess << " - - - -" << endl << endl;
		for (int i = 0; i < maximumGuesses; ++i) {
			cout << "Give me your guess #" << i + 1 << ": ";
			cin >> userGuess;
			if (userGuess == numberToGuess){
				won = true;
				break;
			}else{
				cout << "Guess Again..." << endl;
			}
		}
		/**
		 * if (won == true) {} --> How you should write
		 * if (won) {} --> you need to be able to read it
		 */
		if (won){
			cout << "You are a Winner!!!" << endl;
		}else{
			cout << "Loser :(" << endl;
		}
		cout << "Would you like to play another game? [1 for yes]: ";
		cin >> keepGoing;
	}while (keepGoing == 1);

	cout << "Thanks for playing my game" << endl;

	return 0;
}
