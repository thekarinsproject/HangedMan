#include "pch.h"
#include "Game.h"
#include <time.h>
namespace tkp {
	Game::Game(): gameOver(false), MAX_WORDS(sizeof(wordList) / sizeof(string))
	{
	}


	Game::~Game()
	{
	}

	void Game::printScene(int attempts) {
		// each attempt will act as a state, updating the hanger
		switch (attempts)
		{
		case 0:
			cout << endl;
			cout << "   |---¬ " << endl;
			cout << "   |   | " << endl;
			cout << "   |     " << endl;
			cout << "   |     " << endl;
			cout << "   |     " << endl;
			cout << "   |     " << endl;
			cout << "---------" << endl;
			cout << endl;
			break;
		case 1:
			cout << endl;
			cout << "   |---¬ " << endl;
			cout << "   |   | " << endl;
			cout << "   |   O " << endl;
			cout << "   |     " << endl;
			cout << "   |     " << endl;
			cout << "   |     " << endl;
			cout << "---------" << endl;
			cout << endl;
			break;
		case 2:
			cout << endl;
			cout << "   |---¬  " << endl;
			cout << "   |   |  " << endl;
			cout << "   |   O  " << endl;
			cout << "   |   |  " << endl;
			cout << "   |      " << endl;
			cout << "   |      " << endl;
			cout << "----------" << endl;
			cout << endl;
			break;
		case 3:
			cout << endl;
			cout << "   |---¬  " << endl;
			cout << "   |   |  " << endl;
			cout << "   |   O  " << endl;
			cout << "   |   |  " << endl;
			cout << "   |  / \\ " << endl;
			cout << "   |      " << endl;
			cout << "----------" << endl;
			cout << endl;
			cout << "Be careful!!!" << endl;
			cout << endl;
			break;
		case 4:
			cout << endl;
			cout << "   |---¬  " << endl;
			cout << "   |   |  " << endl;
			cout << "   |   O  " << endl;
			cout << "   |   |\\ " << endl;
			cout << "   |  / \\ " << endl;
			cout << "   |      " << endl;
			cout << "----------" << endl;
			cout << endl;
			cout << "Oh no! This might be your last chance..." << endl;
			cout << endl;
			break;
		case 5:
			cout << endl;
			cout << "   |---¬  " << endl;
			cout << "   |   |  " << endl;
			cout << "   |   O  " << endl;
			cout << "   |  /|\\ " << endl;
			cout << "   |  / \\ " << endl;
			cout << "   |      " << endl;
			cout << "----------" << endl;
			cout << endl;
			cout << "GAME OVER!" << endl;
			gameOver = true;
			break;
		}
	}
	const int Game::selectWord() {
		srand(time(NULL));
		return (rand() % MAX_WORDS);
	}
	// Prints the actual completion of the word and the words that has been used.
	void Game::displayWord(vector<char> &v, vector<char> &w) {
		cout << "Word:     " << flush;
		for (unsigned int i = 0; i < v.size(); i++) {
			cout << v[i] << flush;
		}
		cout << "   Words used: " << flush;
		for (unsigned int j = 0; j < w.size(); j++)
			cout << w[j] << flush;
		cout << endl;
	}
	// checks if the character input match with any letter in the word.
	void Game::updateWord(vector<char> &v, string word, char c, vector<char>&w) {

		bool exists = false;

		for (unsigned int i = 0; i < word.length(); i++) {
			if (word.at(i) == c) {
				v[i] = c;
				exists = true;
			}
		}
		cout << endl;

		if (!exists) {
			cout << "Yikes! try again!" << endl;
			w.push_back(c);
			setAttempts(getAttempts() + 1);
		}
	}
	void Game::checkAttempts() {
		if (getAttempts() >= 5) {
			setGameOver(true);
		}
	}
	void Game::isWordComplete(string word, vector<char> &v) {
		string vWord(v.begin(), v.end()); // copies all chars in vector to the string

		if (word.compare(vWord) == 0) {
			cout << "Nice, you win!!" << endl;
			setGameOver(true);
		}
	}
	char Game::inputCharacter() {
		char c;
		cout << "Enter a letter!" << endl;
		cin >> c;
		return c;
	}

}
