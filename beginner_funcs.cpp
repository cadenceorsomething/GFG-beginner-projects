#include "beginner_funcs.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // for system("cls")
#include <ctime>
#include <cctype>
#include <unordered_map>

void is_working() {
	std::cout << "yep its working." << std::endl;
}

const int MAX_COURSES = 5;
using std::cout, std::cin, std::endl, std::string;

// 5/21/2025: CGPA CALCULATOR

// Define course methods
course::course() {
	name = "Untitled course";
}
void course::input() {
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
string course::get_name() { return name; }
int course::get_hours() { return credit_hours; }
double course::get_grade() { return grade; }
// Now the project function that uses course
namespace projects {
	void CGPA_calculator() {
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


	void core() {
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

	void run() {
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