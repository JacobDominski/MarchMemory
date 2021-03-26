#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
#include <stdio.h>

void Board(int* miss);
int CheckGuess(char input, std::vector<char>* UserWord, std::string word);
bool CheckWin(std::vector<char>* word);
void Sleep(int milliseconds);

int main() {
	srand(time(0));
	int misses;
	bool loop = true;
	char user_input;
	char playAgain = ' ';
	std::string word;

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
			user_input = getchar();

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

int CheckGuess(char input, std::vector<char>* UserWord, std::string word) {

	/*
	The find function is not working (well technically it is). When I check if a letter
	is inside the string, it returns the position of that letter and the number
	4294967295. Additionally, if it could not find the letter inside the string
	it just returns the number 4294967295. So basically, I need to find a way 
	to check if a letter is not inside the word.
	
	
	*/

	if (!(word.find(input) <= word.length()) && word.find(input) != 4294967295) {
		
		std::cout << "\nLetter not found!\n" << word.find(input);
		Sleep(1000);
		return 1;
	}

	for (std::string::size_type i = 0; i < word.size(); ++i) {
		if (word[i] == input) {
			UserWord->at(i) = input;
		}
	}
	return 0;
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