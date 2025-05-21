#include "beginner_funcs.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // for system("cls")

const int MAX_COURSES = 5;
using std::cout, std::cin, std::endl, std::string;

// Working function
void is_working() {
	cout << "yep its working." << endl;
}

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
	void input_vector() {
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
