#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
#include <stdio.h>

void Board(int* miss);
int CheckGuess(std::string input, std::vector<char>* UserWord, std::string word);
bool CheckWin(std::vector<char>* word);
void Sleep(int milliseconds);

int main() {
	srand(time(0));
	int misses;
	bool loop = true;
	char playAgain = ' ';
	std::string word;
	std::string user_input;

	std::vector<char> userWord;
	std::vector<std::string> WordBank = { 
		"March", "Madness", "Basketball", 
		"Pi Day", "Pie", "Circumference", 
		"Diameter", "Ireland", "Four leaf clover", 
		"3.14", "St.Patrick’s Day", "Green", 
		"Clover", "Rainbow", "Pot of Gold", 
		"Horse Shoe", "Spring", "Waffle Day", 
		"Leprechaun", "Shamrock", "Luck", 
		"Mars", "Calendar", "Parade" 
	};

	while (loop) {
		misses = 0;
		word = WordBank.at(rand() % (WordBank.size()));
		userWord.clear();
		for (int i = 0; i < word.length(); i++) {
			userWord.push_back('_');
		}

		while (misses < 6) {

			system("cls");

			Board(&misses);

			for (int i = 0; i < word.length(); i++) {
				std::cout << userWord[i] << " ";
			}

			std::cout << "\nEnter your guess (" << word << "): ";
			std::getline(std::cin, user_input);

			misses += CheckGuess(user_input, &userWord, word);

			if (CheckWin(&userWord)) {
				break;
			}
			

		}

		system("cls");
		Board(&misses);
		
		if (misses >= 6) {
			//you lost
			std::cout << "\nOh no! It looks like you lost!\n";
		}
		else {
			//you win
			std::cout << "\nCongratulations! You won!\n";
		}
		std::cout << "Would you like to play again?\nYour choice (Y/N): ";
		//play again?
		do {
			std::cin >> playAgain;
		} while (!(playAgain == 'Y' || playAgain == 'N'));

		if (playAgain == 'N') {
			loop = false;
		}

	}

	return 0;
}

bool CheckWin(std::vector<char>* word) {

	for (int i = 0; i < word->size(); i++) {
		if (word->at(i) == '_') {
			return false;
		}
	}

	return true;

}

int CheckGuess(std::string input, std::vector<char>* UserWord, std::string word) {

	if (word.find(input[0]) != std::string::npos) {
		for (std::string::size_type i = 0; i < word.size(); ++i) {
			if (word[i] == input[0]) {
				UserWord->at(i) = input[0];
			}
		}
		return 0;
	}

	std::cout << "\nLetter not found!\n";
	return 1;
}

void Board(int* miss) {

	char head = (*miss > 0) ? 'O' : ' ';
	char torso = (*miss > 1) ? '|' : ' ';
	char LeftArm = (*miss > 2) ? '/' : ' ';
	char RightArm = (*miss > 3) ? '\\' : ' ';
	char LeftLeg = (*miss > 4) ? '/' : ' ';
	char RightLeg = (*miss > 5) ? '\\' : ' ';

	std::cout << "\n\n\t\tHangman\n\n";
	std::cout << "___________________ \n";
	std::cout << "|          }        \n";
	std::cout << "|          " << head << std::endl;
	std::cout << "|          " << torso << std::endl;
	std::cout << "|        " << LeftArm << " " << torso << " " << RightArm << std::endl;
	std::cout << "|       " << LeftArm << "  " << torso << "  " << RightArm << std::endl;
	std::cout << "|         " << LeftLeg << " " << RightLeg << std::endl;
	std::cout << "|        " << LeftLeg << "   " << RightLeg << std::endl;
	std::cout << "|\n";
	std::cout << "|__________________\n";

}

void Sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}