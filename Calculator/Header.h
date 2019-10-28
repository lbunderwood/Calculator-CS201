//Luke Underwood
//Created 10/9/19
//Header.h
//Contains library includsions and prototypes for
//CS201 calculator group project application


#ifndef HEADER_H
#define HEADER_H

#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<iomanip>

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





//Converts degrees to radians but only if we're in degrees mode
double degreesToRadians(double radians, const Settings& set);

//Contains menu of trig functions and allows the user to
//use all of them
void trigMenu(const Settings& set);

//Menu for combinatorial operations.
void combinatoricsMenu();

//Funciton that allows multiplication of extremely large integers through array representation.
int multiply(int x, int res[], int res_size);

//Allows the user to change various settings
//Radians/degrees, scientific/fixed, etc
void optionMenu(Settings& set);

#endif
