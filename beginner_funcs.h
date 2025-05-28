#pragma once
#include <string>
using namespace std;

void is_working();
extern const int internal_number;

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



// 5/23/2025: WEIRD CASINO GAME THING

namespace guessing_game {
	
	void run();
}

namespace SoC {
	class guess {
	private:
		int secret_number;
		int upper_bound;
	public:
		static int score;
		guess(int);

		void ts_so_gurt			();
		int  get_upper_bound	() const;
		bool check_guess		(int);
		int  get_score			() const;
		
	};
	int get_difficulty();

	void play_game();
}


namespace calculator {
	string remove_spaces(const string& str);
	string get_postfix(string infix);
}