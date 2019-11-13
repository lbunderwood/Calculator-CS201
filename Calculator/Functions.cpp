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

void printVector(std::vector<double> vector)
{
	std::string vecStr = "< ";
	for (auto n : vector)
	{
		vecStr += std::to_string(n) + ", ";
	}
	vecStr.erase(vecStr.size() - 3, vecStr.size() - 1);
	vecStr += " >";
	std::cout << vecStr;
}

std::vector<std::vector<double>> makeMatrix(int num)
{
	return std::vector<std::vector<double>> (num);
}

double degreesToRadians(double radians, const Settings& set)
{
	if (set.radians)
		return radians;
	else
		return radians * M_PI / 180;
}


    int multiply(int x, int res[], int res_size){
        int carry = 0;
      
        // Multiplying n by each digit in result
        for (int i=0; i<res_size; i++)
        {
            int prod = res[i] * x + carry;
      
            //Rewriting result array for new result, storing the last digit of prod
            res[i] = prod % 10;
      
            // we want to carry whhats left into the next digit
            carry  = prod/10;
        }
      
        // This makes sure our result array is the right size
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
