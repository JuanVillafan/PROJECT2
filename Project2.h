#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Three difficulties, each have a seperate score keeper
struct numGuess {

	string name;

	int bestEasyScore=0;

	int bestMediumScore=0;

	int bestHardScore=0;

};
//Print Score
ostream& operator<<(ostream& stream, numGuess guess) {
	stream << "User: " << guess.name << endl;
	stream << "Best Easy Score : " << guess.bestEasyScore << endl;
	stream << "Best Medium Score : " << guess.bestMediumScore << endl;
	stream << "Best Hard Score : " << guess.bestHardScore << endl;
	return stream;
}
//Choice of difficulty
//a lot of variable use the & symbol to keep the data as it moves between each function back and forth with pointer address.
// struct&, int&, string&
void difficultyChoice(string& difficulty) {

	cout << "DIFFICULTY CHOICE \n Disclaimer : Use numbers given, if an invalid difficulty is chosen, Medium will be chosen" << endl;

	cout << "Choose Difficulty : \n 1 : Easy(1-20) \n 2 : Medium(1-50) \n 3 : Hard(1-100)" << endl;
	getline(cin, difficulty);
	if (difficulty != "1" and difficulty != "2" and difficulty != "3")
		difficulty = "2";
}
//if statements are used for keeping track of your HIGHEST score for each difficulty
//if you get a worse score, it wont replace it.
//  We use a second if statement to replace 0 because that is the starting score. if you get 0, you are cheating
void scoreSet(int score, string difficulty, numGuess& highscore) {
	if (difficulty == "1") {
		if (score < highscore.bestEasyScore)
			highscore.bestEasyScore = score;

		else if (highscore.bestEasyScore==0)
			highscore.bestEasyScore = score;
	}
	else if (difficulty == "2"){
		if (score < highscore.bestMediumScore)
			highscore.bestMediumScore = score;

		else if (highscore.bestMediumScore == 0)
			highscore.bestMediumScore = score;
	}
	else if(difficulty == "3" ){
		if (score < highscore.bestHardScore)
			highscore.bestHardScore = score;

		else if (highscore.bestHardScore == 0)
			highscore.bestHardScore = score;
	}
}

//The work for the game, chooses difficulty.

void startGame(string& difficulty, int& score) {

//If an invalid choice is made, the game is auto set to MEDIUM
	difficultyChoice(difficulty);

//The guess and random starting number have set values to get the while loop going
	int range, guess=1, randNum=0;
	if (difficulty == "1")
		range = 20;
	else if (difficulty == "2")
		range = 50;
	else
		range = 100;
	//srand to allow different sets of random numbers,not predetermined, like our previous class activities
	srand(time(0));
	while (guess != randNum) {
		score++;
		randNum = rand() % ((range - 1 + 1) + 1);
		cout << "Attempt Number " << score << " : \nGuess a number between 1 and " << range << " : ";
		cin >> guess;
	}
	cout << "Correct! The number was : " << randNum << endl;
	cout << "Score : " << score << endl;
}

//runs the game itself with a while function to play as many times as you want
void game(string&difficulty,string&Continue,int& score,numGuess& highscore) {
	while (Continue == "y") {

		startGame(difficulty, score);
		scoreSet(score, difficulty, highscore);
		cout << "To continue, input \"y\", any other option will end game : ";
		cin >> Continue;

		if (Continue != "y") {
			break;
		}
		cout << "View Current HighScores? (Please use \"y\",anything else wont run score) : ";
		cin >> Continue;
		if (Continue == "y") {
			cout << "_________________________" << endl;
			cout << highscore;
		}
		//Incase User inputs anything other than "y", that way the while loop will run again
		else
			Continue == "y";
		cout << endl << "_____________________Next Game______________________________" << endl;
		score = 0;
//cin.ignore with the help of google assistance "Recursion cin/getline() problems"
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}
