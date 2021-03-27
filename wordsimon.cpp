#define NOMINMAX
#include <ctime>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstddef>

void disp_intro();
void pause();

int main()
{
	srand(time(NULL));

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

	return 0;
}


void disp_intro()
{
	std::cout << "\n\n\tWelcome to the Word Simon, MARCH EDITION. \n\n\tEach round you will be given a new word sequence.\n\
	You will have 3 seconds to memorize this sequence before being asked to recite it correctly.\n\
	Sometimes a new sequence will include multiple words such as 'four leaf clover'.\n\
	This will still count as one sequence.\n\n\tExample:\n\n\tif the sequence is: march | pot of gold\n\n\tyou would enter 'march' as your first sequence, then you would enter 'pot of gold' for the second one.\n\n" << std::endl;
	std::cout << "\n\nPress Enter to Begin." << std::endl;
}

void pause()
{
	std::cin.clear(); // clear failed/error states of the stream if they are set
	if (std::cin.rdbuf()->in_avail()) // if there are any characters in the input buffer
	{ 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw them away
	}
} // JACOB DOMINSKI SPECIAL

