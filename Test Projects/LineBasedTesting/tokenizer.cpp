/*
	tokenizer.cpp
	Andrew Ng
	Oct 15 2019
	source for string/token functions for hw 4
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include "tokenizer.h"
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::vector;


// puts line received from user into referenced string
bool ReadLine(string& str)
{
	std::getline(cin, str);

	// returns false if string is empty
	if (str.empty()) {
		return false;
	}
	else {
		return true;
	}
}

// 15 + (sin(50) * -4) / ln(4^2) - -7.3
// separates strings by whitespace, pushes strings into a vector
unsigned StringToTokensWS(vector<string>& tokens, string& str)
{
	istringstream instream(str);
	string strToPush;
	string empty;
	unsigned tokenCounter = 1;
	for (size_t i = 0; i < str.size(); ++i) {
		for (size_t j = i + 1; j <= str.size(); ++j) {
			if (str[i] == '-' && str[j] == '-') {
				tokens.push_back(str.substr(i, j - i));
				i = j;
			}
			if ((isdigit(str[i]) || str[i] == '-' || str[i] == '.') && (!isdigit(str[j]) && str[j] != '-' && str[j] != '.' && str[j] != ' ')) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
			}
			else if (isalpha(str[i]) && !isalpha(str[j])) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
			}
			else if (ispunct(str[i]) && str[i] != '-') {
				tokens.push_back(str.substr(i, 1));
				++i;
			}
			else if (iswspace(str[i])) {
				++i;
			}
		}
	}
	for (const auto s : tokens) {
		cout << "///" << s;
	}
	// AnalyzeTokens(tokens);
	EvaluateTokens(tokens);
	/*
	while (true) {
		instream >> strToPush;
		if (instream) {
			tokens.push_back(strToPush);
			tokenCounter++;
		}
		else {
			break;
		}
	}
	tokens.push_back(empty);
	*/

	// returns number of tokens pushed
	return tokenCounter;
}

// 15 + (sin(50)*-4) / ln(4^2) - -7.3
// 5^(ln(5*(2-0.75)/23))-13
// sin(cos(tan(ln((4+(3*2))^2))))
//  0 1 2  3  4  5 6 7  8 9 1011121314151617 18

void EvaluateTokens(vector<string>& tokens) {
	cout << endl;
	for (const auto& s : tokens) {
		cout << s << " ";
	}
	cout << endl;
	size_t num = 0;
	vector<int> leftParen;
	for (size_t i = 0; i < tokens.size(); ++i) {
		// cout << i << endl;
		if (tokens[i] == "(") {
			leftParen.push_back(i);
			for (size_t j = i + 1; j < tokens.size(); ++j) {
				if (tokens[j] == "(") {
					++num;
					leftParen.push_back(j);
					i = j;
					continue;
				}
				if (tokens[j] == ")") {
					long double result = EvalInside(i, j, tokens);
					tokens.erase(tokens.begin() + i, tokens.begin() + j + 1);
					tokens.insert(tokens.begin() + i, std::to_string(result)); //EvalInside(i, j));
					if (num > 0) {
						--num;
					}
					else {
						leftParen.clear();
					}
					i = 0;
					for (const auto& s : tokens) {
						cout << s << " ";
					}
					cout << endl;
					break;
				}
			}
		}
	}
	long double r = EvalInside(0, tokens.size(), tokens);
	cout << r << endl;
	tokens.clear();
}

long double EvalInside(const size_t& left, const size_t& right, vector<string>& tokens) {
	vector<string> op;
	vector<long double> numbers;
	for (size_t i = left; i < right; ++i) {
		istringstream is(tokens[i]);
		long double num;
		if (is >> num) {
			op.push_back("null");
			numbers.push_back(num);
		}
		else if (tokens[i] != "(" && tokens[i] != ")") {
			op.push_back(tokens[i]);
			numbers.push_back(0);
		}
	}

	cout << endl;
	for (const auto s : op) {
		cout << s << " ";
	}
	cout << endl;
	for (const auto n : numbers) {
		cout << n << " ";
	}
	cout << endl;

	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "sin") {
			long double result = sin(numbers[i + 1]);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 2);
			numbers.insert(numbers.begin() + i, result);
			op.erase(op.begin() + i, op.begin() + i + 1);
			
			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;
			
			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "cos") {
			long double result = cos(numbers[i + 1]);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 2);
			numbers.insert(numbers.begin() + i, result);
			op.erase(op.begin() + i, op.begin() + i + 1);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "tan") {
			long double result = tan(numbers[i + 1]);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 2);
			numbers.insert(numbers.begin() + i, result);
			op.erase(op.begin() + i, op.begin() + i + 1);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "ln") {
			long double result = log(numbers[i + 1]);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 2);
			numbers.insert(numbers.begin() + i, result);
			op.erase(op.begin() + i, op.begin() + i + 1);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "^") {
			long double result = pow(numbers[i - 1], numbers[i + 1]);
			numbers.erase(numbers.begin() + i - 1, numbers.begin() + i + 2);
			if (numbers.empty()) {
				numbers.push_back(result);
			}
			else {
				numbers.insert(numbers.begin() + i - 1, result);
			}
			op.erase(op.begin() + i, op.begin() + i + 2);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "*") {
			long double result = numbers[i - 1] * numbers[i + 1];
			numbers.erase(numbers.begin() + i - 1, numbers.begin() + i + 2);
			if (numbers.empty()) {
				numbers.push_back(result);
			}
			else {
				numbers.insert(numbers.begin() + i - 1, result);
			}
			op.erase(op.begin() + i, op.begin() + i + 2);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "/") {
			long double result = numbers[i - 1] / numbers[i + 1];
			numbers.erase(numbers.begin() + i - 1, numbers.begin() + i + 2);
			if (numbers.empty()) {
				numbers.push_back(result);
			}
			else {
				numbers.insert(numbers.begin() + i - 1, result);
			}
			op.erase(op.begin() + i, op.begin() + i + 2);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "+") {
			long double result = numbers[i - 1] + numbers[i + 1];
			numbers.erase(numbers.begin() + i - 1, numbers.begin() + i + 2);
			if (numbers.empty()) {
				numbers.push_back(result);
			}
			else {
				numbers.insert(numbers.begin() + i - 1, result);
			}
			op.erase(op.begin() + i, op.begin() + i + 2);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	for (size_t i = 0; i < op.size(); ++i) {
		if (op[i] == "-") {
			long double result = numbers[i - 1] - numbers[i + 1];
			numbers.erase(numbers.begin() + i - 1, numbers.begin() + i + 2);
			if (numbers.empty()) {
				numbers.push_back(result);
			}
			else {
				numbers.insert(numbers.begin() + i - 1, result);
			}
			op.erase(op.begin() + i, op.begin() + i + 2);

			cout << endl;
			for (const auto s : op) {
				cout << s << " ";
			}
			cout << endl;
			for (const auto n : numbers) {
				cout << n << " ";
			}
			cout << endl;

			i = 0;
		}
	}
	return numbers[0];
}

void EvaluateTokens2(vector<string>& tokens)
{

}

// performs various checks on tokens, prints them with determined type of token
void AnalyzeTokens(const vector<string>& tokens)
{
	for (const auto& s : tokens) {

		// whitespace: if empty string
		if (s.empty()) {
			cout << "[whitespace]\t" << "\"" << s << "\"" << endl;
			continue;
		}

		// integer: if all characters are digits
		for (int i = 0; i < s.size(); ++i) {
			if (!isdigit(s[i])) {
				break;
			}
			if (i == s.size() - 1) {
				cout << "[integer]\t" << "\"" << s << "\"" << endl;
				goto determined;
			}
		}

		// string: if starts and ends with double quote
		if (s.front() == '"' && s.back() == '"' && s.size() > 2) {
			cout << "[string]\t" << "\"\\"
				 << s.substr(0, s.size() - 1) << "\\\"\"" << endl;
			continue;
		}

		// identifier: if first char is a letter or underscore, and
		// characters beyond that are alphanumerical or underscores
		for (int j = 0; j < s.size(); ++j) {
			if (!isalpha(s[0]) && s[0] != '_') {
				break;
			}
			if (!isalnum(s[j]) && s[j] != '_') {
				break;
			}
			if (j == s.size() - 1) {
				cout << "[identifier]\t" << "\"" << s << "\"" << endl;
				goto determined;
			}
		}

		// other: if single character that is considered punctuation
		if (s.size() == 1 && ispunct(s[0])) {
			cout << "[other]\t\t" << "\"" << s << "\"" << endl;
			continue;
		}

		// unknown: if none of the others are met
		cout << "[unknown]\t" << "\"" << s << "\"" << endl;

	// goto statement label for continuing from nested for-loops
	determined:;
	}
}