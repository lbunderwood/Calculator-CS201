//Luke Underwood
//Created 10/9/19
//Main.cpp
//Contains main function for
//CS201 calculator group project application

#include"Header.h"

int main()
{
	int menuchoice = 0;
	Settings set;

	while (menuchoice != 7)
	{

		//Main Menu that opens into submenus
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Text Calculator" << std::endl
			<< "\t 2. Trigonometry" << std::endl
			<< "\t 3. Polynomials" << std::endl
            << "\t 4. Combinatorics" << std::endl
			<< "\t 5. Vectors" << std::endl
			<< "\t 6. Settings" << std::endl
			<< "\t 7. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				lineBasedMenu(set);
				break;
			case 2:
				trigMenu(set);
				break;
			case 3:
				polynomialMenu(set);
				break;
			case 4:
                combinatoricsMenu();
				break;
			case 5:
				vectorMenu(set);
				break;
			case 6:
				optionMenu(set);
				break;
			case 7:
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
    return 1;
}
