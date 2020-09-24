/**
 * Author:	Carlos R. Arias
 * Class:	CSC 2330 Data Structures and Programming
 * Date:	September 23 / 2020
 * Purpose:	A simple number guessing game
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
	int hot, warm, cold;
	double logVal;

	do{
		cout << "What is the maximum number to guess: ";
		cin >> maximumToGuess;
		//Now determine the values to assign hot...cold
		//Going to do this with logs which might be weird
		logVal = log10(static_cast<double>(maximumToGuess));
		hot = maximumToGuess / (static_cast<int>(logVal * 10));
		warm = hot * 3;
		cold = hot * 5;
		cout << "---" << "Hot is within: " << hot << endl;
        cout << "---" << "warm is within: " << warm << endl;
        cout << "---" << "cold is within: " << cold << endl;


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
			    if (abs(numberToGuess - userGuess) < hot){
                    cout << "Oooo you're hot" << endl;
                }
                else if (abs(numberToGuess - userGuess) < warm) {
                    cout << "You're warm-ish" << endl;
                }
                else if (abs(numberToGuess - userGuess) < cold) {
                    cout << "You're cold" << endl;
                }
                else {
                    cout << "Brrrr you're freezing" << endl;
                }// Have to give a bit more of a hint here - DPS

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
