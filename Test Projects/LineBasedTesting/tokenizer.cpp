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
#include <cfloat>

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

unsigned StringToTokensWS2(vector<string>& tokens, string& str)
{
	string token;
	bool op = 0;
	bool num = 0;
	bool deci = 0;
	bool alph = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (isblank(c)) {
			if (!token.empty()) {
				tokens.push_back(token);
			}
			token.clear();
			continue;
		}
		if (ispunct(c) && c != '.') {
			if (i == 0) {
				op = 1;
			}
			if (op && c == '-') {
				op = 0;
				num = 1;
				if (!token.empty()) {
					tokens.push_back(token);
				}
				token.clear();
				token.push_back(c);
				continue;
			}
			if (!token.empty()) {
				tokens.push_back(token);
			}
			token.clear();
			token.push_back(c);
			tokens.push_back(token);
			token.clear();
			if (c != '(' && c != ')') {
				op = 1;
			}
			num = 0;
			alph = 0;
		}
		else if (isdigit(c) || c == '.') {
			op = 0;
			if (!alph) {
				num = 1;
				token.push_back(c);
			}
			else {
				tokens.push_back(token);
				token.clear();
				alph = 0;
				num = 1;
				token.push_back(c);
			}
		}
		else if (isalpha(c)) {
			op = 0;
			if (!num) {
				alph = 1;
				token.push_back(c);
			}
			else {
				tokens.push_back(token);
				token.clear();
				num = 0;
				alph = 1;
				token.push_back(c);
			}
		}
		if (i + 1 == str.size()) {
			if (!token.empty()) {
				tokens.push_back(token);
			}
			token.clear();
		}
	}
	cout << "TESTING OUTPUT" << endl;
	for (const auto t : tokens) {
		cout << t << " || ";
	}
	cout << endl;
	EvaluateTokens(tokens);
	return 0;
}

// 15 + (sin(50) * -4) / ln(4^2) - -7.3
// separates strings by whitespace, pushes strings into a vector
unsigned StringToTokensWS(vector<string>& tokens, string& str)
{
	istringstream instream(str);
	string strToPush;
	string empty;
	unsigned tokenCounter = 1;
	bool deci = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		deci = 0;
		for (size_t j = i; j <= str.size(); ++j) {
			if (str[j] == '.') {
				if (deci) {
					cout << "error" << endl;
					deci = 0;
					//return 1;
				}
				else {
					deci = 1;
				}
			}
			else if (str[i] == '-' && str[j] == '-') {
				tokens.push_back(str.substr(i, j - i));
				i = j;
				break;
			}
			else if ((isdigit(str[i]) || str[i] == '-' || str[i] == '.') && (!isdigit(str[j]) && str[j] != '-' && str[j] != '.')) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
				break;
			}
			else if ((isdigit(str[i]) || str[i] == '-' || str[i] == '.') && (str[j] == '-')) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
				break;
			}
			else if (isalpha(str[i]) && !isalpha(str[j])) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
				break;
			}
			else if (ispunct(str[i]) && str[i] != '-') {
				if (ispunct(str[i]) && ispunct(str[j]) && j == i + 1 && str[j] != '-') {
					cout << "ERROR" << endl;
					return 1;
				}
				tokens.push_back(str.substr(i, 1));
				++i;
				break;
			}
			else if (iswspace(str[i])) {
				++i;
			}
			cout << std::to_string(deci) << endl;
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
					if (result == LDBL_MAX) {
						cout << "ERROR" << endl;
						return;
					}
					tokens.erase(tokens.begin() + i, tokens.begin() + j + 1);
					tokens.insert(tokens.begin() + i, std::to_string(result));
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
	if (r == LDBL_MAX) {
		cout << "ERROR" << endl;
		return;
	}
	cout << r << endl;
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
			numbers.push_back(LDBL_MAX);
		}
	}
	if (numbers.size() == 1) {
		return numbers[0];
	}
	if (left + 1 == right) {
		return LDBL_MAX;
	}
	for (size_t i = 0; i < numbers.size() - 1; ++i) {
		if (numbers[i] != LDBL_MAX && numbers[i + 1] != LDBL_MAX) {
			return LDBL_MAX;
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
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = sin(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = cos(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = tan(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
		if (op[i] == "arcsin") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = asin(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
		if (op[i] == "arccos") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = acos(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
		if (op[i] == "arctan") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = atan(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = log(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
		if (op[i] == "sqrt") {
			if (i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = sqrt(numbers[i + 1]);
			numbers.insert(numbers.begin() + i, result);
			numbers.erase(numbers.begin() + i + 1, numbers.begin() + i + 3);
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
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = pow(numbers[i - 1], numbers[i + 1]);
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
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
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] * numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
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
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] / numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
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
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] + numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
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
			if (i == 0 || i == op.size() - 1) {
				return LDBL_MAX;
			}
			if (numbers[i - 1] == LDBL_MAX || numbers[i + 1] == LDBL_MAX) {
				return LDBL_MAX;
			}
			long double result = numbers[i - 1] - numbers[i + 1];
			numbers.insert(numbers.begin() + i - 1, result);
			numbers.erase(numbers.begin() + i, numbers.begin() + i + 3);
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