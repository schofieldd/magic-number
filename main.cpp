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
	bool won = false;
	int keepGoing = 0;

	do{
		numberToGuess = rand() % 10 + 1;
		// cout << "- - - - " << numberToGuess << " - - - -" << endl << endl;
		for (int i = 0; i < 3; ++i) {
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
