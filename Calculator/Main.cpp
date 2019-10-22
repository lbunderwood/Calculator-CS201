//Luke Underwood
//Created 10/9/19
//Main.cpp
//Contains main function for
//CS201 calculator group project application

#include"Header.h"

int main()
{
	int menuchoice = 0;

	while (menuchoice != 8)
	{

		//Main Menu that opens into submenus
		std::cout << std::endl 
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Four-Function Calculator" << std::endl
			<< "\t 2. Trigonometric Functions" << std::endl
			<< "\t 3. Polynomials" << std::endl
			<< "\t 4. Calculus" << std::endl
			<< "\t 5. Statistics" << std::endl
			<< "\t 6. Vectors" << std::endl
			<< "\t 7. Matrices" << std::endl
			<< "\t 8. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				//Function Call Here
				break;
			case 2:
				trigMenu();
				break;
			case 3:
				//Function Call Here
				break;
			case 4:
				//Function Call Here
				break;
			case 5:
				//Function Call Here
				break;
			case 6:
				//Function Call Here
				break;
			case 7:
				//Function Call Here
				break;
			case 8:
				break;
			default:
				std::cout << "Please enter one of the numbers listed." 
					<< std::endl;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
			continue;
		}

	}

}