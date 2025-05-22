#pragma once
#include <string>

void is_working();


// 5/21/2025: CGPA CALCULATOR

class course {
private:
	std::string name;
	int credit_hours;
	double grade;
public:
	course();                    // Constructor
	void input();                // Input method
	std::string get_name();      // Getters
	int get_hours();
	double get_grade();
};
namespace CGPA_calculator {
	void run();         // Function prototype
}



// 5/22/2025: ROCK PAPER SCISSORS

namespace rock_paper_scissors {
	void run();
}