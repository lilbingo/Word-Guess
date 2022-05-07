// simple word guessing game
// created around april/may of '22

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

void fillVec(vector<string>& words, char mode);

int main() {

	// get hard/easy choice then fill vector based on decision
	char mode = ' ';
	vector<string> words;
	cout << "Would you like to play on hard or easy mode (e/h)>";
	cin >> mode;
	fillVec(words, mode);

	srand ( time(NULL) ); // initialize the random seed
	int randNum = rand() % words.size(); // random num between 0 and vector size
	string answer = words[randNum];
	const unsigned short int ANS_LEN = answer.length();
	string guesses (ANS_LEN, '_'); // initialize guesses with _ for the number of characters in answer
	char guess = ' '; 
	unsigned short int wrongGuess = 0;

	while (true) {
		cout << "Enter a letter: ";
		cin >> guess;
		
		if (answer.find(guess) == string::npos) {
			cout << "\nThere is no " << guess << " in the word!\n";
			++wrongGuess;
			cout << "Your current number of incorrect answers is: " << wrongGuess << "\n\n";
		}
		else {
			for (int i = 0; i < ANS_LEN; i++) {
				if (guess == answer[i]) {
					guesses[i] = guess;
				}
			}
		}

		// if the answer is found, user wins. if wrongGuess >= 6, user loses.
		if(answer == guesses) {
			cout << "You win! The answer was: " << answer << "\n";
			return 0;
		}
		else if (wrongGuess >= 6) {
			cout << "\nYou lose! The word was: " << answer << "\n";
			return 0;
		}

		cout << guesses << "\n\n";
		cin.ignore();
	}
}

void fillVec(vector<string>& words, char mode) {	
	ifstream allWordsFile;
	string text;
	switch(mode) {
		case 'h':
			allWordsFile.open("hardwords.txt");
			break;
		case 'e':
			allWordsFile.open("easywords.txt");
			break;
		default:
			cout << "\nInvalid selection.\n";
			exit(1);	
	}
        while (getline(allWordsFile, text)) {
		words.push_back(text);
	}
}
