//Luke Underwood
//Created 10/9/19
//Header.h
//Contains library inclusions and prototypes for
//CS201 calculator group project application


#ifndef HEADER_H
#define HEADER_H

#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<cctype>
#include<iomanip>
#include "GMPHeader.h"




//Stores various settings to be easily passed into functions
struct Settings {
	//true = radians, false = degrees
	bool radians = true; 

	//Stores the number of digits past the decimal the user wants
	int floatnum = 5; 

	//true = output in scientific
	bool scientific = false; 

	//more coming?
};

//Collects a line of text from the user. 
//Returns whether it was an int
//Returns int by reference
bool getInt(int& num);

//Collects a line of text from the user.
//returns whether it was a number
//returns double by reference
bool getDouble(double& num);

//Collects a line of text from the user.
//returns whether it was a number
//returns float by reference
bool getFloat(float & num);

//return a new vector of vectors of doubles with num vectors in it
//original use was for setting up the vector used in vectorMenu
//but it is not being used anymore
std::vector<std::vector<double>> makeMatrix(int num);

//Used to collect data from the user to fill vecNum vectors with vecPlaces
//elements
std::vector<std::vector<double>> populateVectors(int vecNum, int vecPlaces);

//Concatonates a string that holds the vector of doubles in proper 
//notation, then sends the string to cout.
void printVector(std::vector<double> vector);

//Converts degrees to radians but only if we're in degrees mode
double degreesToRadians(double radians, const Settings& set);

//Funciton that allows multiplication of extremely large integers through array representation.
int multiply(int x, int res[], int res_size);



//Contains menu of trig functions and allows the user to
//use all of them
void trigMenu(const Settings& set);

//Contaims menu of polynomial operations
void polynomialMenu(const Settings& set);

//Menu for vector operations
void vectorMenu(const Settings& set);

//Menu for combinatorial operations.
void combinatoricsMenu();

//Allows the user to change various settings
//Radians/degrees, scientific/fixed, etc
void optionMenu(Settings& set);


//(TEMP) Andrew's tokenizer stuff

void lineBasedMenu();

void makeTokens(std::vector<std::string>& tokens, std::string& str);

void evaluateTokens(std::vector<std::string>& tokens);

long double evalInside(const size_t& left, const size_t& right, std::vector<std::string>& tokens);

#endif
