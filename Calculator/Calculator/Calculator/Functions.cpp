//Luke Underwood
//Created 10/9/19
//Functions.cpp
//Contains all functions for
//CS201 calculator group project application

#include"Header.h"

bool getInt(int & num)
{
	std::string input;

	getline(std::cin, input);
	std::istringstream instream(input);
	instream >> num;

	if (instream)
		return true;
	else
		return false;
}

bool getDouble(double& num)
{
	std::string input;
	std::cout << "Please enter a value: ";

	getline(std::cin, input);
	std::istringstream instream(input);
	instream >> num;

	if (instream)
		return true;
	else
		return false;
}

double degreesToRadians(double radians, const Settings& set)
{
	if (set.radians)
		return radians;
	else
		return radians * M_PI / 180;
}


    int multiply(int x, int res[], int res_size){
        int carry = 0;  // Initialize carry
      
        // One by one multiply n with individual digits of res[]
        for (int i=0; i<res_size; i++)
        {
            int prod = res[i] * x + carry;
      
            // Store last digit of 'prod' in res[]
            res[i] = prod % 10;
      
            // Put rest in carry
            carry  = prod/10;
        }
      
        // Put carry in res and increase result size
        while (carry)
        {
            res[res_size] = carry%10;
            carry = carry/10;
            res_size++;
        }
        return res_size;
    }
    


    bool getFloat(float & num)
    {
        std::string input;

        getline(std::cin, input);
        std::istringstream instream(input);
        instream >> num;

        if (instream)
            return true;
        else
            return false;
    }