/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/09/17
Purpose: 
*/

// ProjectOne.cpp
// from project one
// this program is a calculator

#include <iostream>

using namespace std;

// function protoypes
void greeting();
void menu();
void quit();
float computeSum(float num1, float num2);
float computeSub(float num1, float num2);
float computeMul(float num1, float num2);
float computeDiv(float num1, float num2);
float computeRoot(float num1, int n);
float computePower(float num1, int index);
float computePerc(float num1, float perc);
int computeLCM(int num1, int num2);
int computeGCD(int num1, int num2);
int computeMod(int num1, int num2);

int main()
{
	// main variables
	char menuChoice;
	float numOne = 0.0;
	float numTwo = 0.0;
	float resultOne = 0.0;
	float resultTwo = 0.0;
	float addition = 0.0; 
	float subtraction = 0.0;
	float muliplication = 0.0;
	float division = 0.0;
	float root = 0.0;
	float power = 0.0;
	float percentage = 0.0;
	int numThree = 0;
	int numFour = 0;
	
	// display greeting
	greeting();

	do
	{
		// display menu
		menu();

		// collect user's menu choice
		cout << "Please select a choice from the list above: ";
		cin >> menuChoice;
		menuChoice = toupper(menuChoice);
		
		// list cases for each choice
		switch (menuChoice)
		{

		// if user selects addition
		case 'A' :
			cout << "Please enter two numbers: ";
			cin >> numOne >> numThree;
			// call addition function
			resultOne = computeSum(numOne, numThree);
			// print result
			cout << numOne << " + " << numThree << " = " << resultOne << endl;
			break;

		// if user selects subraction
		case 'B' :
			cout << "Enter the first number: ";
			cin >> numOne;
			cout << "Enter the second number: ";
			cin >> numTwo;
			
			// call subraction function
			resultOne = computeSub(numOne, numTwo);
			cout << numOne << " - " << numTwo << " = " << resultOne << endl;
			break;

		// if user selects multiplication
		case 'C' :
			break;

		// if user selects roots
		case 'E' :
			cout << "Please enter your number: ";
			cin >> numOne;
			cout << "Enter the root value: ";
			cin >> numThree;
			resultOne = computeRoot(numOne, numThree);
			do
			{
				if (resultOne >= 0)
				{
					cout << numOne << " to the root of " << numThree << " = " << resultOne << endl;
				}
				// if positive numbers weren't used
				else
				{
					cout << "Please use postive numbers only." << endl;
					cout << "Enter your number: ";
					cin >> numOne;
					cout << "Enter the root value: ";
					cin >> numThree;
					resultOne = computeRoot(numOne, numThree);
					cout << numOne << " to the root of " << numThree << " = " << resultOne << endl;
				}
			} while (resultOne < 0);
			break;

		// if user selects powers
		case 'F' :
			cout << "Enter the base: ";
			cin >> numOne;
			cout << "Enter the exponent: ";
			cin >> numThree;

			// call powers function
			resultOne = computePower(numOne, numThree);
			do
			{
				if (resultOne >= 0)
				{
					cout << numOne << " to the power of " << numThree << " = " << resultOne << endl;
				}
				// if positive numbers weren't used
				else
				{
					cout << "Please user postive numbers only." << endl;
					cout << "Enter the base: ";
					cin >> numOne;
					cout << "Enter the exponent: ";
					cin >> numThree;
					resultOne = computePower(numOne, numThree);
					cout << numOne << " to the power of " << numThree << " = " << resultOne << endl;
				}
			} while (resultOne < 0);
		break;

		// if user selects 'H'
		case 'H' :
			
			cout << "Please enter two whole numbers: ";
			cin >> numOne >> numTwo;
			
			resultOne = computeLCM(numThree, numFour);
			cout << "The LCM of " << numThree << " and " << numFour;
			cout << " is: " << resultOne << endl;
			break;
		
		// if user selects quit
		case 'L':
			quit();
			break;

		// if user's input was invalid
		default:
			cout << "An invalid input was read. "
				 << "Please choose an option from the list above: ";
			cin >> menuChoice;
			menuChoice = toupper(menuChoice);
		}

		cout << endl;
		system("pause");
	} while (menuChoice != 'L');
	
	// display goodbye message
	quit();

	system("pause");
	return 1;
}

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/13/17
Purpose: print greeting message
*/
void greeting()
{
	cout << "Welcome to my calculator program." << endl << endl;
}

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/13/17
Purpose: print menu
*/
void menu()
{
	cout << endl << "----------------------------" << endl;
	cout << "        CALCULATOR" << endl;
	cout << "----------------------------" << endl << endl;
	cout << "A.)  ADDITION" << endl;
	cout << "B.)  SUBTRACTION" << endl;
	cout << "C.)  MULTIPLICATION" << endl;
	cout << "D.)  DIVISION" << endl;
	cout << "E.)  ROOTS (positive numbers only)" << endl;
	cout << "F.)  POWERS (postive numbers only)" << endl;
	cout << "G.)  PERCENTAGE" << endl;
	cout << "H.)  LEAST  COMMON  MULTIPLIER" << endl;
	cout << "I.)  GREATEST  COMMON  DIVISOR" << endl;
	cout << "J.)  MODULUS" << endl;
	cout << "K.)  DISPLAY   FUNCTION  EXECUTION" << endl;
	cout << "L.)  QUIT" << endl << endl;
}

/*
Author: Peter O'Donohue
Creation Date: 03/09/17
Modification Date: 03/13/17
Purpose: calculate addition
*/
float computeSum(float a, float b)
{
	float c;
	c = a + b;
	return c;
}

/*
Author: Peter O'Donohue
Creation Date: 03/13/17
Modification Date: 03/13/17
Purpose: calculate subraction
*/
float computeSub(float a, float b)
{
	float c;
	c = a - b;
	return c;
}


/*
Author: Peter O'Donohue
Creation Date: 03/13/17
Modification Date: 03/13/17
Purpose: calculate multiplication
*/
float computeMult(float a, float b)
{
	float c;
	c = a * b;
	return c;
}

// compute division

/*
Author: Peter O'Donohue
Creation Date: 03/13/17
Modification Date: 03/13/17
Purpose: calculate root
*/
float computeRoot(float root, int index)
{
	float tp, mid;
	float low = 0;
	float high = root;
	do
	{
		mid = (low + high) / 2;
		if (computePower(mid, index) > root)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
		mid = (low + high) / 2;
		tp = (computePower(mid, index) - root);
		if (tp < 0)
		{//grab absolute value
			tp = tp * (-1.0);
		}
	} while (tp > .000005);//accuracy of our root
	return mid;
}

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/13/17
Purpose: calculate power
*/
float computePower(float a, int b)
{
	int count = 1;
	float power = 1.0;
	while (count <= b)
		{
		power = power * a;
		++count;
		}
		return power;
}

// computer percentage

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/13/17
Purpose: calculate LCM
*/
int computeLCM(int a, int b)
{
	int tmp_lcm;
	tmp_lcm = ((a * b) / computeGCD(a, b));
	return tmp_lcm;
}

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/13/17
Purpose: calculate GCD
*/
int computeGCD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}

// compute modulus

// display functions execute

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/13/17
Purpose: print exit message
*/
void quit()
{
	cout << endl << endl << "Have a great day!" << endl << endl;
}