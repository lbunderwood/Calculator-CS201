//Luke Underwood
//Created 10/28/19
//Menus.cpp
//Contains menu functions for
//CS201 calculator group project application

#include"Header.h"

void trigMenu(const Settings& set)
{
	int menuchoice = 0;
	double num;

	while (menuchoice != 13)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1.  Sine" << std::endl
			<< "\t 2.  Cosine" << std::endl
			<< "\t 3.  Tangent" << std::endl
			<< "\t 4.  Secant" << std::endl
			<< "\t 5.  Cosecant" << std::endl
			<< "\t 6.  Cotangent" << std::endl
			<< "\t 7.  Arcsine" << std::endl
			<< "\t 8.  Arccosine" << std::endl
			<< "\t 9.  Arctangent" << std::endl
			<< "\t 10. Arcsecant" << std::endl
			<< "\t 11. Arccosecant" << std::endl
			<< "\t 12. Arccotangent" << std::endl
			<< "\t 13. Exit" << std::endl;

		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				if (getDouble(num))
				{
					std::cout << "sin(" << num << ") = "
						<< sin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 2:
				if (getDouble(num))
				{
					std::cout << "cos(" << num << ") = "
						<< cos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 3:
				if (getDouble(num))
				{
					std::cout << "tan(" << num << ") = "
						<< tan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 4:
				if (getDouble(num))
				{
					std::cout << "sec(" << num << ") = "
						<< 1 / cos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 5:
				if (getDouble(num))
				{
					std::cout << "csc(" << num << ") = "
						<< 1 / sin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 6:
				if (getDouble(num))
				{
					std::cout << "cot(" << num << ") = "
						<< 1 / tan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 7:
				if (getDouble(num))
				{
					std::cout << "asin(" << num << ") = "
						<< asin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 8:
				if (getDouble(num))
				{
					std::cout << "acos(" << num << ") = "
						<< acos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 9:
				if (getDouble(num))
				{
					std::cout << "atan(" << num << ") = "
						<< atan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 10:
				if (getDouble(num))
				{
					std::cout << "asec(" << num << ") = "
						<< 1 / acos(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 11:
				if (getDouble(num))
				{
					std::cout << "acsc(" << num << ") = "
						<< 1 / asin(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 12:
				if (getDouble(num))
				{
					std::cout << "acot(" << num << ") = "
						<< 1 / atan(degreesToRadians(num, set)) << std::endl;
				}
				else
				{
					std::cout << "Please enter a number." << std::endl;
				}
				break;
			case 13:
				break;
			default:
				std::cout << "Please enter one of the options." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
		}
	}
}


void optionMenu(Settings& set)
{
	int menuchoice = 0;
	int num;
	std::string choice;

	while (menuchoice != 4)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Radians/Degrees" << std::endl
			<< "\t 2. Floating point ammount" << std::endl
			<< "\t 3. Normal/Scientific" << std::endl
			<< "\t 4. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				std::cout << "Please type \"R\" for radians, or "
					<< "\"D\" for degrees: ";
				getline(std::cin, choice);
				if (choice == "R" || choice == "r")
				{
					set.radians = true;
					std::cout << "You are now in radians mode" << std::endl;
				}
				else if (choice == "D" || choice == "d")
				{
					set.radians = false;
					std::cout << "You are now in degrees mode" << std::endl;
				}
				else
				{
					std::cout << "Unrecognized input. Please try again."
						<< std::endl;
				}
				break;
			case 2:
				std::cout << "Please enter the number of digits you would"
					<< " like to have after the decimal: " << std::endl;
				if (getInt(num))
				{
					std::cout << std::fixed << std::setprecision(num);
					set.floatnum = num;
					std::cout << "There will now be " << num
						<< " decimal places" << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer.";
				}
				break;
			case 3:
				std::cout << "Please type \"N\" for normal, or "
					<< "\"S\" for scientific: ";
				getline(std::cin, choice);
				if (choice == "N" || choice == "n")
				{
					set.scientific = false;
					std::cout << std::fixed << "You are now in normal mode" << std::endl;
				}
				else if (choice == "S" || choice == "s")
				{
					set.scientific = true;
					std::cout << std::scientific << "You are now in scientific mode" << std::endl;
				}
				else
				{
					std::cout << "Unrecognized input. Please try again."
						<< std::endl;
				}
				break;
			case 4:
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


void combinatoricsMenu() {
	int menuchoice = 0;
	float num1;
	float num2;
	int num3;
	int res[500];

	// Function for paramaters will probably use getint

	while (menuchoice != 10)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1.  Permuatation" << std::endl
			<< "\t 2.  Combination" << std::endl
			<< "\t 3.  K-list" << std::endl
			<< "\t 4.  Multiset" << std::endl
			<< "\t 5.  Stirling-Number" << std::endl
			<< "\t 6.  Sum Stirling-Number" << std::endl
			<< "\t 7.  Bell Number" << std::endl
			<< "\t 8.  Partitions of an Integer" << std::endl
			<< "\t 9.  Sum Partitions of an Integer" << std::endl
			<< "\t 10. Exit" << std::endl;

		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{
			case 1:
				std::cout << "Please enter an integer." << std::endl;
				if (getInt(num3)) {

					// Initialize result
					res[0] = 1;
					int res_size = 1;

					// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
					for (int x = 2; x <= num3; x++)
						res_size = multiply(x, res, res_size);

					std::cout << num3 << "! is: ";
					for (int i = res_size - 1; i >= 0; i--)
						std::cout << res[i];
				}
				else
				{
					std::cout << "Please enter an integer." << std::endl;
				}

				//permutation paramaters int
				break;

			case 2:
				std::cout << "Please enter 2 integers" << std::endl;
				if (getFloat(num1) && getFloat(num2))
				{
					float result = num1;
					for (int i = 2; i <= num2; ++i)
					{
						result *= (num1 - i + 1);
						result /= i;
					}
					std::cout << num1 << " choose " << num2 << " is " << result << std::endl;
				}
				else
				{
					std::cout << "Please enter 2 integers." << std::endl;
				}
				break;

			case 3:
				// K list paramaters 2 ints
				break;

			case 4:
				// Multiset pramaters 2 ints
				break;
			case 5:
				//stirling number paramaters 2 ints
				break;
			case 6:
				//sum stirling number paramaters 2 ints
				break;
			case 7:
				// bell number paramater 1 int
				break;
			case 8:
				// partitions of an integer paramaters 2 ints
				break;
			case 9:
				// sum partitions of an integer paramates 2 ints
				break;
			case 10:
				break;
			default:
				std::cout << "Please enter one of the options." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Please enter an integer." << std::endl;
		}
	}
}


void vectorMenu(const Settings& set)
{
	int menuchoice = 0;
	int vecNum = 0;
	int vecPlaces = 0;
	std::vector<std::vector<double>> vecVec;

	while (menuchoice != 8)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Find the Magnitude" << std::endl
			<< "\t 2. Add Vectors" << std::endl
			<< "\t 3. Scalar Multiplication" << std::endl
			<< "\t 4. Dot Product" << std::endl
			<< "\t 5. Cross Product" << std::endl
			<< "\t 6. Scalar Triple Product" << std::endl
			<< "\t 7. Normalize the Vector" << std::endl
			<< "\t 8. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{

			//Magnitude
			case 1:
				vecNum = 1;
				std::cout << "How many elements are in the vector?"
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					std::cout << "|| ";
					printVector(vecVec[0]);
					std::cout << " ||";
					std::cout << std::endl;
					double magnitude = 0;
					for (size_t i = 0; i < vecVec[0].size(); i++)
					{
						magnitude += pow(vecVec[0][i], 2);
					}
					magnitude = pow(magnitude, 0.5);
					std::cout << " = " << magnitude << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

			//Addition
			case 2:
				std::cout << "How many vectors are you adding?\n";
				if (getInt(vecNum))
				{
					vecVec = makeMatrix(vecNum);
					std::cout << "How many elements are in each vector?\n";
					if (getInt(vecPlaces))
					{
						vecVec = populateVectors(vecNum, vecPlaces);

						for (auto n : vecVec)
						{
							printVector(n);
							if (n != vecVec.back())
							{
								std::cout << " + ";
							}
						}

						std::vector<double> addAns(vecPlaces, 0);
						for (auto n : vecVec)
						{
							for (size_t i = 0; i < n.size(); i++)
							{
								addAns[i] += n[i];
							}
						}
						std::cout << " = ";
						printVector(addAns);
					}
					else
					{
						std::cout << "Please enter an integer.\n";
					}
				}
				else
				{
					std::cout << "Please enter an integer.\n";
				}
				break;

			//Scalar Multiplication
			case 3:
				vecNum = 1;
				std::cout << "How many elements are in the vector?"
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					std::cout << "What are you multiplying by?";
					std::cout << std::endl;
					double scalar;
					if (!getDouble(scalar))
					{
						std::cout << "Bad input. Please enter a number\n";
						while (!getDouble(scalar))
						{
							std::cout << "Bad input. Please enter a number\n";
						}
					}
					std::cout << scalar << " * ";
					printVector(vecVec[0]);
					std::cout << std::endl;

					std::vector<double> scaled(vecPlaces, 0);
					for (int i = 0; i < vecPlaces; i++)
					{
						scaled[i] = vecVec[0][i] * scalar;
					}
					std::cout << " = ";
					printVector(scaled);
					std::cout << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

			//Dot Product
			case 4:
				vecNum = 2;
				std::cout << "How many elements are in each vector?" 
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					printVector(vecVec[0]);
					std::cout << " DOT ";
					printVector(vecVec[1]);
					std::cout << std::endl;
					double dotAns = 0;
					for (size_t i = 0; i < vecVec[0].size(); i++)
					{
						dotAns += vecVec[0][i] * vecVec[1][i];
					}
					std::cout << " = " << dotAns << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

			//Cross Product
			case 5:
				std::cout << "Work In Progress\n";
				break;

			//Triple Product
			case 6:
			{
				vecNum = 3;
				vecPlaces = 3;
				std::cout << "The first two vectors will be crossed, and"
					<< " the result will be dotted with the third vector."
					<< std::endl;

				vecVec = populateVectors(vecNum, vecPlaces);

				std::cout << "( ";
				printVector(vecVec[0]);
				std::cout << " X ";
				printVector(vecVec[1]);
				std::cout << " ) DOT ";
				printVector(vecVec[2]);
				std::cout << std::endl;

				std::vector<double> crossAns(vecPlaces, 0);
				crossAns[0] = vecVec[0][1] * vecVec[1][2] - vecVec[1][1] * vecVec[0][2];
				crossAns[1] = (vecVec[0][0] * vecVec[1][2] - vecVec[1][0] * vecVec[0][2]) * -1;
				crossAns[2] = vecVec[0][0] * vecVec[1][1] - vecVec[1][0] * vecVec[0][1];

				double dotAns = 0;
				for (size_t i = 0; i < vecPlaces; i++)
				{
					dotAns += vecVec[2][i] * crossAns[i];
				}
				std::cout << " = " << std::to_string(dotAns) << std::endl;
				break;
			}

			//Normalize
			case 7:
				vecNum = 1;
				std::cout << "How many elements are in the vector?"
					<< std::endl;
				if (getInt(vecPlaces))
				{
					vecVec = populateVectors(vecNum, vecPlaces);

					double scalar = 0;
					for (size_t i = 0; i < vecVec[0].size(); i++)
					{
						scalar += pow(vecVec[0][i], 2);
					}
					scalar = pow(scalar, 0.5);

					printVector(vecVec[0]);
					std::cout << " / " << scalar;
					std::cout << std::endl;

					std::vector<double> scaled(vecPlaces, 0);
					for (int i = 0; i < vecPlaces; i++)
					{
						scaled[i] = vecVec[0][i] / scalar;
					}
					std::cout << " = ";
					printVector(scaled);
					std::cout << std::endl;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
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


void polynomialMenu(const Settings& set)
{
	int menuchoice = 0;
	int magnitude = 0;
	std::vector<double> zeros;

	while (menuchoice != 4)
	{
		std::cout << std::endl
			<< "Please select one of the following options:" << std::endl
			<< "\t 1. Find the Zeros" << std::endl
			<< "\t 2. Solution of two Polynomials" << std::endl
			<< "\t 3. Polynomial Expansion" << std::endl
			<< "\t 4. Exit" << std::endl;

		//Collects input and handles errors
		if (getInt(menuchoice))
		{
			switch (menuchoice)
			{

			//Zeros
			case 1:
				std::cout << "What is the highest exponent in your polynomial?"
					<< std::endl;
				if (getInt(magnitude))
				{
					std::vector<double> coefficients(magnitude);

					for (int i = 0; i < magnitude; i++)
					{
						std::cout << "What is the coefficient of x ^ "
							<< std::setprecision(0) << i
							<< std::setprecision(set.floatnum) << "?";
						while (!getDouble(coefficients[i]))
						{
							std::cout << "Please enter a number.";
						}
					}

					while (coefficients[0] == 0)
					{
						coefficients.erase(coefficients.begin());
						magnitude--;
						if (*zeros.begin() != 0)
						{
							zeros.push_back(0);
						}
					}

					int positives = 0;
					for (size_t i = 1; i < magnitude; i++)
					{
						if ((coefficients[i] < 0 && coefficients[i - 1] > 0) ||
							(coefficients[i] > 0 && coefficients[i - 1] < 0))
						{
							positives++;
						}
					}

					int negatives = 0;
					std::vector<double> negativesTest = coefficients;
					for (size_t i = 1; i < magnitude; i += 2)
					{
						negativesTest[i] *= -1;
					}

					for (size_t i = 1; i < magnitude; i++)
					{
						if ((coefficients[i] < 0 && coefficients[i - 1] > 0) ||
							(coefficients[i] > 0 && coefficients[i - 1] < 0))
						{
							negatives++;
						}
					}

					long double x = 0;
					long double h = 0.000000001;
					long double m1 = 0;
					long double m2 = 0;
					long double fXplusH = 0;
					long double fofX = 0;
					long double fXminusH = 0;

					for (size_t i = 0; i < magnitude; i++)
					{
						fofX += coefficients[i] * pow(x, i);
						fXplusH += coefficients[i] * pow(x + h, i);
						fXminusH += coefficients[i] * pow(x - h, i);
					}

					m1 = ((fXplusH - fofX) / h);
					m2 = ((fofX - fXminusH) / h);
					std::cout << "f(x) = " << fofX << std::endl << "f(x + h) = " << fXplusH
						<< std::endl << "f(x-h) = " << fXplusH << std::endl << "f'(x)1 = " << m1 << std::endl << "f'(x)2 = " << m2
						<< std::endl << "AVE m = " << (m1 + m2) / 2.0;
				}
				else
				{
					std::cout << "Please enter an integer\n";
				}
				break;

				//
			case 2:
				
				break;

				//Expansion
			case 3:
				
				break;

			//Exit
			case 4:
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