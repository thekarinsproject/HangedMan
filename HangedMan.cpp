#include "pch.h"
#include <iostream>
#include "Game.h"
using namespace tkp;

int main()
{
	Game game;
	// Variables
	char c;
	// Initialize word
	string word = game.getWordFromList(game.selectWord());
	vector<char> guessWord(word.length(), '-');
	vector<char> wordsUsed;

	// First print
	game.printScene(game.getAttempts());

	// Game loop
	while (!game.getGameOver()) {
	
		// Display current word status
		game.displayWord(guessWord, wordsUsed);
		// Player input
		c = game.inputCharacter();
		// Clears the screen
		system("cls");
		// Check if character is in word
		game.updateWord(guessWord, word, c, wordsUsed);
		// Display current game status
		game.printScene(game.getAttempts());
		// Check if word is complete
		game.isWordComplete(word, guessWord);
		// Check if player has lost
		game.checkAttempts();
	}
	cout << "Answer: " << word << endl;

	// freeing memory
	vector<char>().swap(guessWord); // swaps information to temporal vector, which will be deleted
	vector<char>().swap(wordsUsed);

	system("pause");

	return 0;
}


