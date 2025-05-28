#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "beginner_funcs.h"
#include <string>
#include <variant>
#include <stack>

using namespace std;


int main() {
	cout << calculator::get_postfix("A+B*C+D * (9+2+7607)") << endl;


	cout << endl;

	return 0;
}