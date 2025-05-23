#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "beginner_funcs.h"

#define VALIDATE_BOUNDS(low, x, high) ((x) >= (low) && (x) <= (high) ? (x) : 0)

using namespace std;

int main() {
	guessing_game::run();

	return 0;
}