#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "beginner_funcs.h"
#include <string>
#include <variant>
#include <stack>
#include <queue>

using namespace std;


void print_queue(queue <variant<char, int>> q) {
	while (!q.empty()) {
		variant <char, int> front = q.front();
		if (holds_alternative<int>(front))
			cout << get<int>(front) << " ";
		else
			cout << get<char>(front) << " ";
		q.pop();
	}
}


int main() {
	cout << shunting_yard_algorithm::eval("1 - (1 + 1)") << endl;


	return 0;
}



namespace calculator {
	/*ok i made this to make the main logic
	easier by eliminating the handling of ' ' in
	the bigger function that is supposed to compute
	the string.*/

	// utilities
	string		remove_spaces(const string& str) {
		string new_str;
		for (char ch : str)
			if (ch != ' ') new_str.push_back(ch);
		return new_str;
	}
	inline int  precedence(char op) {
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		if (op == '^') return 3;
		return 0;
	}
	inline bool is_operator(const char& op) {
		static const unordered_set <char>
			op_s = { '-','+','/','*','^' };
		return (bool)op_s.count(op);
	}
	inline bool is_operand(const char& ch) {
		return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
	}
	inline bool is_right_associative(char op) {
		return op == '^';
	}

	// condionals
	bool should_push_operator(char op, const stack<char>& op_s) {
		if (op_s.empty())
			return true;
		if (op_s.top() == '(')
			return true;
		if (precedence(op) > precedence(op_s.top()))
			return true;
		return false;
	}
	bool should_flush(const stack <char>& operators, char ch) {
		if (operators.empty()) return false;
		const char top = operators.top();
		const int ch_prec = precedence(ch);
		const int top_prec = precedence(top);

		return (ch_prec < top_prec) || (ch_prec == top_prec && !is_right_associative(ch));
	}

	// action functions
	void resolve_and_push(stack <char>& operators, string& output, char ch) {
		while (should_flush(operators, ch)) {
			output.push_back(operators.top());	// output the top element
			operators.pop();					// then pop it
		}

		operators.push(ch);
	}
	void handle_closing_parenthesis(stack <char>& operators, string& output) {
		while (!operators.empty() && operators.top() != '(') {
			char ch = operators.top();
			output.push_back(ch);
			operators.pop();
		}
		if (!operators.empty() && operators.top() == '(')
			operators.pop();
	}
	void flush_stack(stack <char>& operators, string& output) {
		while (!operators.empty()) {
			output.push_back(operators.top());
			operators.pop();
		}
	}


	// main
	string get_postfix(string infix) {
		// DECLARATIONS
		stack <char> operators;
		string output;

		// remove unnecessary spaces
		infix = remove_spaces(infix);

		for (char ch : infix) {
			if (is_operand(ch))
				output.push_back(ch);

			else if (ch == '(')
				operators.push(ch);

			else if (ch == ')')
				handle_closing_parenthesis(operators, output);

			else
				if (should_push_operator(ch, operators))
					operators.push(ch);

				else
					resolve_and_push(operators, output, ch);
		}

		flush_stack(operators, output);


		return output;
	}


	/*
	* Reference: GeeksforGeeks article on converting infix to postfix expressions
	* https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/
	* (CTRL + Click to open the link)
	* This article helped me understand how postfix expressions are formed.
	*/



}
