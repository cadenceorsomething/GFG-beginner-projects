#pragma once
#include <string>

void is_working();

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

namespace projects {
	void input_vector();         // Function prototype
}
