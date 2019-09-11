#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace tkp {
class Game
		{
		public:
			const int MAX_WORDS;
		public:
			Game();
			virtual ~Game();
			void printScene(int attemps);
			const int selectWord();
			void displayWord(vector<char> &v, vector<char> &w);
			void updateWord(vector<char> &v, string word, char c, vector<char>&w);
			void checkAttempts();
			void isWordComplete(string word, vector<char> &v);
			char inputCharacter();
			int getAttempts() { return attempts;  };
			void setAttempts(int a) { attempts = a; };
			bool getGameOver() { return gameOver; };
			void setGameOver(bool g) { gameOver = g; };
			string getWordFromList(int n) { return wordList[n]; }
		private:
			int attempts = 0;
			bool gameOver;
			string wordList[11] = { "chocolate", "pineapple", "underscore", "bedroom", "comando", "jelly", "wakanda", "fries", "fireworks", "water", "defnotblitz" };
		};
}

