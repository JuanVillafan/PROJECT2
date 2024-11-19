#include <iostream>
#include <string>
#include <iomanip>
#include "Project2.h"
//I will stay simple and create a random number guesser, gthat changes the number after each guess
//ex: num=2, guess != num, then num = 5
using namespace std;

int main(){

	//Keep track of highest score(lowest # of guesses) by difficulty
	int score=0;
	//structure to keep track
	numGuess highscore;
	//Intro to game
	cout << "Welcome to the Random Number guesser, made for boredom :" << endl
		<< right << setw(10) << "A random number will be generated based on difficulty chosen." << endl <<
		"For Each incorrect guess, a new number will be generated, making this game tougher" << endl
		<<"_____________________________________________________________" << endl;
	cout << "Choose your Username : ";
	getline(cin, highscore.name);
	string difficulty;
	string Continue="y";
	game(difficulty, Continue, score, highscore);
	//once "game" function is ended, the final code will run
	cout << "______________________________" << endl;
	cout << "Ending Game\n FINAL SCORE : " << endl;
	cout << highscore;
	return 0;
}