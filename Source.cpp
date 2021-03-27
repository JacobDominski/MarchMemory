#define NOMINMAX
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <random>
#include <thread>
#include <chrono>
#include <stdio.h>


void Board(int* miss);
int CheckGuess(std::string input, std::vector<char>* UserWord, std::string word);
bool CheckWin(std::vector<char>* word);
void Sleep(int milliseconds);
void introScramble();
void youWinScramble();
void disp_intro();
void pause();

void scrambleGame();
void hangman();
void wordSimon();



int main() {

	srand(time(NULL));

	bool gameStatus = true;
	int choice;
	std::cout << "Welcome to the game loader, March edition." << std::endl;
	Sleep(2000);
	while(gameStatus){

		std::cout << "Which game would you like to play? " << std::endl;
		Sleep(2000);
		std::cout << "1. Word Scramble\n2. Hangman\n3. Memory Game\n4. Quit" << std::endl;
		std::cin >> choice;


		switch (choice) {
			case 1:
				system("CLS");
				std::cout << "Booting Game..." << std::endl;
				Sleep(2000);
				system("CLS");
				//Word Scramble 
				scrambleGame();
				break;
			case 2:
				system("CLS");
				std::cout << "Booting Game..." << std::endl;
				Sleep(2000);
				system("CLS");
				//Hangman
				hangman();
				break;
			case 3:
				system("CLS");
				std::cout << "Booting Game..." << std::endl;
				Sleep(2000);
				system("CLS");
				//Memory Game
				wordSimon();
				break;
			case 4:
				system("CLS");
				std::cout << "Bye!" << std::endl;
				Sleep(2000);
				gameStatus = false;
				break;
			default:
				std::cout << "That's not an option..." << std::endl;
				Sleep(1000);
			}
		system("CLS");
	}
	
	


	return 0;
}





void hangman() {
	
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
		misses = -1;
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

			std::cout << "\nEnter your guess: ";
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
			std::cout << "The word was " << word << std::endl;
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



void scrambleGame() {

	std::string terms[25] = { "March", "Madness", "Basketball", "Pie", "3.14", "Circumference", "Diameter", "Ireland", "Four leaf clover", "Pi Day", "St.Patrick’s Day", "Green", "Clover", "Rainbow", "Pot of Gold", "Horse Shoe", "Spring", "Waffle Day", "Leprechaun", "Shamrock", "Luck", "Mars", "Calendar", "Parade" };
	std::random_shuffle(std::begin(terms), std::end(terms));
	std::string sTerms[25];
	for (int i = 0; i < sizeof(terms) / sizeof(terms[0]); i++) {
		std::string word = terms[i];
		std::random_shuffle(word.begin(), word.end());
		if (i < 25) {
			sTerms->append(word + ",");
		}
		if (i == 25) {
			sTerms->append(word);
		}
	}
	std::string scrambledTerms[6];  
	std::stringstream string_stream(*sTerms);
	for (int i = 0; i < 6; i++) {
		std::string a;
		getline(string_stream, a, ',');
		scrambledTerms[i] = a;
	}
	//std::cout << scrambledTerms[0];
	//std::cout << terms[0];
	introScramble();
	system("CLS");
	int wins = 0;
	int i = 0;
	std::string input;
	while (wins <= 2) {
		
		system("CLS");
		
		int nextWord = i;
		std::cout << scrambledTerms[nextWord] << std::endl;
		//std::cin.clear();
		std::cout << ">> ";
		std::getline(std::cin,input);
		//std::cout << terms[nextWord] << std::endl;
		if (input == terms[nextWord]) {
			std::cout << "You did it!!" << std::endl;
			Sleep(2000);
			for (int j = nextWord; j < i; ++j){
				scrambledTerms[j] = scrambledTerms[j + 1];
				terms[j] = terms[j + 1];
			}	
			wins++;
		}
		else {
			std::cout << "Whoops! Maybe next time." << std::endl;
			Sleep(2000);
			wins = 0;
		}
		i++;
	}
	youWinScramble();

	
}
void introScramble() {
	std::cout << "Welcome to the scramble guess game!" << std::endl;
	Sleep(3000);
	std::cout << "Words will be scrambled and you will need to de-scramble the words. " << std::endl;
	Sleep(4000);
	std::cout << "De-scramble 3 words consecutively to win." << std::endl;
	Sleep(4000);
}
void youWinScramble() {
	std::cout << "Congrats on winning the game!" << std::endl;
	Sleep(3000);
}




void wordSimon()
{
	

	std::string terms[] = { "march", "madness", "basketball", "pi day", "pie", "circumference", "diameter", "ireland",\
						"four leaf clover", "3.14", "st. patrick's day", "green", "clover", "rainbow", "pot of gold",\
						"horseshoe", "spring", "waffle day", "leprechaun", "shamrock", "luck", "mars", "calendar", "parade" };

	std::vector <std::string> user_vec;
	std::vector <std::string> match;
	std::string user_input;
	bool loop = true;
	int total_score = 0;
	int turn = 0;
	char cont;

	disp_intro();
	Sleep(1000);
	std::cin.get();

	while (loop)
	{
		system("CLS");

		for (int i = 0; i < 10; i++)
		{
			user_vec.clear();
			int score = 0;
			turn++;

			match.push_back(terms[rand() % 24]);

			std::cout << "\n\nThe new sequence is: ";

			for (int i = 0; i < match.size(); i++)
			{
				std::cout << match.at(i) << " | ";
			}

			std::cout << "\n\nclearing in...";
			std::cout << '\a'; // windows beep
			std::cout << "3...";
			Sleep(1000); // one sec
			std::cout << "2...";
			Sleep(1000);
			std::cout << "1...";
			Sleep(1000);
			system("CLS"); // clear screen

			std::cout << "* please enter your guess one sequence at a time *\n\n";

			for (int i = 1; i < match.size() + 1; i++)
			{
				std::cout << "Enter sequence number " << i << ": ";
				getline(std::cin, user_input);
				user_vec.push_back(user_input);
			}

			for (int i = 0; i < match.size(); i++)
			{
				if (user_vec[i] == match[i])
				{
					score++;
				}
			}

			if (score == turn)
			{
				total_score++;
				std::cout << "\n** CORRECT **";
				std::cout << "\nTotal Score: " << total_score << "\n\n" << std::endl;
			}
			else if (score == 10)
			{
				std::cout << "YOU WIN! YOU GOT ALL 10 OUT OF 10!\n\n" << std::endl;
			}
			else if (score != turn)
			{
				std::cout << "\n** INCORRECT **" << std::endl;
				std::cout << "The correct sequence was: ";
				for (int i = 0; i < match.size(); i++)
				{
					std::cout << match.at(i) << ' ';
				}
				std::cout << "\n\nYour Final Score: " << total_score << "\n\n" << std::endl;

				break;
			}
		}

		std::cout << "Would you like to play again? [Y/N] ";
		std::cin >> cont;
		if (cont == 'y')
		{
			match.clear();
			user_vec.clear();
			turn = 0;
			pause();
			loop = true;
		}
		else if (cont == 'Y')
		{
			match.clear();
			user_vec.clear();
			turn = 0;
			pause();
			loop = true;
		}
		else
		{
			pause();
			loop = false;
		}
	}

}
void disp_intro()
{
	std::cout << "\n\n\tWelcome to the Word Simon, MARCH EDITION. \n\n\tEach round you will be given a new word sequence.\n\
	You will have 3 seconds to memorize this sequence before being asked to recite it correctly.\n\
	Sometimes a new sequence will include multiple words such as 'four leaf clover'.\n\
	This will still count as one sequence.\n\n\tExample:\n\n\tif the sequence is: march | pot of gold\n\n\tyou would enter 'march' as your first sequence, then you would enter 'pot of gold' for the second one.\n\n" << std::endl;
	std::cout << "\n\nPress Enter to Begin." << std::endl;
	Sleep(12000);
}

void pause()
{
	std::cin.clear(); // clear failed/error states of the stream if they are set
	if (std::cin.rdbuf()->in_avail()) // if there are any characters in the input buffer
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw them away
	}
} // JACOB DOMINSKI SPECIAL
