#include "beginner_funcs.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // for system("cls")
#include <ctime>
#include <cctype>
#include <unordered_map>

// MACROS: 
#define VALIDATE_BOUNDS(lower, num, upper) ((num) >= (lower) && (num) <= (upper) ? (num) : 0)

void is_working() {
	std::cout << "yep its working." << std::endl;
}

const int MAX_COURSES = 5;
using std::cout, std::cin, std::endl, std::string;

// 5/21/2025: CGPA CALCULATOR

// Define course methods
		course::course		() {
	name			= "Untitled course";
	credit_hours	= 0;
	grade			= 0;
}
void	course::input		() {
	cout << "Name of the course: ";
	std::getline(cin, name);
	cout << "Credit hours: ";
	cin >> credit_hours;
	cout << "GPA (out of 4.0): ";
	cin >> grade;

	while (grade > 4 || grade < 0) {
		system("cls");
		cout << "Name of the course: " << name << endl;
		cout << "Credit hours: " << credit_hours << endl;
		cout << "ERROR: GPA OUT OF BOUNDS. Try again. GPA (out of 4.0): ";
		cin >> grade;
	}
}
string	course::get_name	() { return name; }
int		course::get_hours	() { return credit_hours; }
double	course::get_grade	() { return grade; }
// Now the project function that uses course
namespace CGPA_calculator {
	void run() {
		std::vector<course> box;
		int it = 0;
		cout << "How many courses have you taken?" << endl;
		cin >> it;
		while (it <= 0 || it > MAX_COURSES) {
			system("cls");
			cout << "Please input an amount between 0 and " << MAX_COURSES << "." << endl;
			cout << "How many courses have you taken?" << endl;
			cin >> it;
		}

		for (int i = 0; i < it; i++) {
			cout << "course " << i + 1 << ": " << endl;
			cin.ignore(1, '\n');
			course obj;
			obj.input();
			box.push_back(obj);
			cout << endl;
		}

		cout << "courses: " << endl;

		double cgpa_numerator = 0;
		double cgpa_denominator = 0;

		for (course obj : box) {
			cgpa_numerator += (double)obj.get_hours() * obj.get_grade();
			cgpa_denominator += (double)obj.get_hours();
		}

		double cgpa = cgpa_numerator / cgpa_denominator;

		cout << "CGPA: " << cgpa << endl;
	}
}

// 5/22/2025: ROCK PAPER SCISSORS

namespace rock_paper_scissors {
	int player_move, computer_move;
	int wins = 0, losses = 0;

	void core	() {
		// random seed
		srand((unsigned int)time(NULL));

		// picking computer move
		computer_move = rand() % 3;

		// string for future input
		string str;

		// map for iterating over elements and a vector of strings 
		std::unordered_map <string, int> us = { {"rock",0},{"paper",1},{"scissors",2} };
		std::vector <string> choices = { "rock", "paper", "scissors" };

		// this is where i will srote  the results
		int result;

		// player input
		do {
			cout << "rock paper scissors! pick one." << endl;
			cin >> str;
			for (char& c : str)	c = tolower(c); // turning the given string to lowercase

			/*find() returns an iterator of the element if found,
			if the element is not found then it returns end()*/


			if (us.find(str) != us.end()) {
				break;
			}
		} while (1);


		// asign the input to the this variable
		player_move = us.at(str);

		// calculate
		result = (player_move - computer_move + 3) % 3;

		// show what computer picked
		cout << endl;
		cout << "the computer picked " << choices[computer_move] << endl;
		cout << endl;

		if (result == 0) {
			cout << choices[computer_move] << " ties " << choices[player_move] << endl;
		}
		else if (result == 1) {
			cout << "YOU WIN! ";
			cout << choices[player_move] << " beats " << choices[computer_move] << endl;
			
			wins++;
		}
		else if (result == 2) {
			cout << "YOU LOSE! ";

			cout << choices[computer_move] << " beats " << choices[player_move] << endl;
			
			losses++;
		}
		system("pause");
	}
	void run	() {
		bool choice;
		
		do {
			core();
			system("cls");
			if ((wins + losses > 0)) {
				cout << "wins: " << wins << "   losses: " << losses << endl;
				cout << "Play again? (0/1)" << endl;
				cin >> choice;
				if (choice == 0) break;
			}
		} while (true);
	}
}



// 5/23/2025: WEIRD CASINO GAME THING

namespace guessing_game {
	// i will talk to myself here like a maniac
	// ok there will be 3 difficulties
	// the more difficult the more rewards
	
	
	/*i ran into stupid unecessary problems trying
	to make this static in the source file
	without making it visible in the header */
	int score = 0;

	class guessing {
	private:
		int difficulty;
		int secret_number;
		std::vector <int> count = {2,4,6};
	public:
		// this is where i will be keeping the scores

		guessing() {
			int input; //input to put difficulty (could put it in difficulty but yeah this is cleaner)
			cout << "insert difficulty 1-3: ";
			cin >> input;

			while (true) {
				difficulty = VALIDATE_BOUNDS(1, input, 3);
				if (difficulty != 0) break;

				system("cls");
				cout << "number out of bounds, insert valid difficulty 1-3: ";
				cin >> input;
			}

			// i decremented difficulty so it can match the indexes
			secret_number = rand() % count[difficulty - 1] + 1;
		}
		~guessing() {
		}
		
		inline int upper_bound() { return count[difficulty - 1]; }
		inline int get_num() { return secret_number; }

		
		void play() {
			// "pick a number: " *inputs number*
		
			int input;
			int player_guess;
			cout << "pick a number: ";
			cin >> input;

			// *sees if this is in bounds*
			while (true) {
				player_guess = VALIDATE_BOUNDS(1, input, upper_bound());
				if (player_guess != 0) break;

				cout << "number out of bounds, pick a number in the range 1 to " << upper_bound() << ": ";
				cin >> input;
			}

			// checks if this number is equal to the generated one
			// if it is, then increment the score based on difficulty
			std::vector <int> increment = { 30,90,270 };
			if (secret_number == player_guess) {
				cout << "you win " << increment[difficulty - 1] << "!" << endl;
				score += increment[difficulty - 1];
			}
			else {
				cout << "you lose! the correct number is " << secret_number << endl;
			}
		}
	};

	void core() {
		if (score != 0) cout << "Score: " << score << "\n" << endl;
		guessing game;
		game.play();
	}
	void run () {
		srand((unsigned int)time(NULL));
		while (true) {
			core();
			cout << "\ndo you want to play again? (y/n)" << endl;
			cin.ignore(1, '\n');	// idk i found this easier to type than i would declare and iput seperately
			char input = getchar();
			if (input == 'n') break;
			system("cls");
		}
	}
}

