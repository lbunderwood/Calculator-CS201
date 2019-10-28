/*
	tokenizertest.cpp
	Andrew Ng
	Oct 15 2019
	main function for tokenizer program for hw 4
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "tokenizer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string str;
	vector<string> tokens;
	//cout << "Enter some text, and type "
	//	 << "\"End\", \"end\", or \"END\" when done." << endl;

	// Reads lines until it reads end input
	while (true) {
		ReadLine(str);
		StringToTokensWS(tokens, str);
		/*
		if (tokens[tokens.size() - 2] == "end" ||
			tokens[tokens.size() - 2] == "End" || 
			tokens[tokens.size() - 2] == "END") {

			// removes final newline token
			tokens.pop_back();
			break;
		}
		*/
	}

	// Analyzes after reading all lines
	// AnalyzeTokens(tokens);
}