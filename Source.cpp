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



void introScramble();
void youWinScramble();


void scrambleGame();




int main() {

	

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
				
				break;
			case 3:
				system("CLS");
				std::cout << "Booting Game..." << std::endl;
				Sleep(2000);
				system("CLS");
				//Memory Game

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






void scrambleGame() {

	std::string terms[25] = { "March", "Madness", "Basketball", "Pi Day", "Pie", "Circumference", "Diameter", "Ireland", "Four leaf clover", "3.14", "St.Patrick’s Day", "Green", "Clover", "Rainbow", "Pot of Gold", "Horse Shoe", "Spring", "Waffle Day", "Leprechaun", "Shamrock", "Luck", "Mars", "Calendar", "Parade" };
	std::string sTerms[25];
	for (int i = 0; i < sizeof(terms) / sizeof(terms[0]); i++) {
		std::string word = terms[i];
		std::random_shuffle(word.begin(), word.end());
		if (i < 5) {
			sTerms->append(word + ",");
		}
		if (i == 5) {
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
	while (wins <= 2) {
		system("CLS");
		std::string input;
		int nextWord = i;
		std::cout << scrambledTerms[nextWord] << std::endl;
		std::cout << ">> ";
		std::getline(std::cin,input);
		std::cout << terms[nextWord] << std::endl;
		if (input == terms[nextWord]) {
			std::cout << "You did it!!" << std::endl;
			for (int j = nextWord; j < i; ++j){
				scrambledTerms[j] = scrambledTerms[j + 1];
				terms[j] = terms[j + 1];
			}	
			wins++;
		}
		else {
			std::cout << "Whoops! Maybe next time." << std::endl;
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


