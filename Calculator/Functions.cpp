//Luke Underwood
//Created 10/9/19
//Functions.cpp
//Contains all functions for
//CS201 calculator group project application

#include"Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Testing for GMP Library
// Test Space Test Space Test Space Test Space Test Space
void fact(int n){
  int i;
  mpz_t p;

  mpz_init_set_ui(p,1); /* p = 1 */
  for (i=1; i <= n ; ++i){
    mpz_mul_ui(p,p,i); /* p = p * i */
  }
  printf ("%d!  =  ", n);
  mpz_out_str(stdout,10,p);
  mpz_clear(p);

}
// Test Space Test Space Test Space Test Space Test Space






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
	std::cout << "< ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i != vector.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " >";
}

std::vector<std::vector<double>> makeMatrix(int num)
{
	return std::vector<std::vector<double>> (num);
}

std::vector<std::vector<double>> populateVectors(int vecNum, int vecPlaces)
{
	std::vector<std::vector<double>> vecVec (vecNum);
	double vecElement = 0;
	for (auto i = 0; i < vecNum; i++)
	{
		for (auto j = 0; j < vecPlaces; j++)
		{
			std::cout << "What is element " << j + 1
				<< " in vector " << i + 1 << "?\n";
			if (getDouble(vecElement))
			{
				vecVec[i].push_back(vecElement);
			}
			else
			{
				std::cout << "Bad input. "
					<< "Please enter a number\n";
				while (!getDouble(vecElement))
				{
					std::cout << "Bad input. "
						<< "Please enter a number\n";
				}
				vecVec[i].push_back(vecElement);
			}
		}
	}
	return vecVec;
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
