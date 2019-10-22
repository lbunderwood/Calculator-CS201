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

void trigMenu()
{
	int menuchoice = 0;

	std::cout << "Please select one of the following options:" << std::endl
		<< "\t 1. Sine" << std::endl
		<< "\t 2. Cosine" << std::endl
		<< "\t 3. Tangent" << std::endl
		<< "\t 4. Secant" << std::endl
		<< "\t 5. Cosecant" << std::endl
		<< "\t 6. Cotangent" << std::endl
		<< "\t 7. Arcsine" << std::endl
		<< "\t 8. Arccosine" << std::endl
		<< "\t 9. Arctangent" << std::endl
		<< "\t 10. Arcsecant" << std::endl
		<< "\t 11. Arccosecant" << std::endl
		<< "\t 12. Arccotangent" << std::endl
		<< "\t 13. Exit" << std::endl;

	while (menuchoice != 13)
	{
		if(getInt(menuchoice))
			switch (menuchoice)
			{

			}
	}
}