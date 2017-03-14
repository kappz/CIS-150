/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/14/17
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
	float addition = 0.0; 
	float subtraction = 0.0;
	float muliplication = 0.0;
	float division = 0.0;
	float root = 0.0;
	float power = 0.0;
	float percentage = 0.0;
	int numThree = 0;
	int numFour = 0;
	int resultTwo = 0;
	
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
		case 'A':
			cout << "Please enter the first number: ";
			cin >> numOne;
			cout << "Please enter the second number: ";
			cin >> numTwo;
			// call addition function
			resultOne = computeSum(numOne, numTwo);
			// print result
			cout << numOne << " + " << numTwo << " = " << resultOne << endl;
			break;

			// if user selects subraction
		case 'B':
			cout << "Please enter the first number: ";
			cin >> numOne;
			cout << "Please enter the second number: ";
			cin >> numTwo;

			// call subraction function
			resultOne = computeSub(numOne, numTwo);
			cout << numOne << " - " << numTwo << " = " << resultOne << endl;
			break;

		// user selects multiplication
		case 'C':	
			cout << "Please enter the first number: ";
			cin >> numOne;
			cout << "Please enter the second number: ";
			cin >> numTwo;
			resultOne = computeMul(numOne, numTwo);		// calculate multiplication

			// display results
			cout << numOne << " * " << numTwo << " = " << resultOne << endl;
			break;


		// user selects division
		case 'D' :

			// collect input values
			cout << "Please enter the first number: ";
			cin >> numOne;
			cout << "Please enter the second number: ";
			cin >> numTwo;
			do
			{
				if (numTwo == 0)
				{
					cout << "Division by zero is not allowed." << endl;
					cout << "Please enter the first number: ";
					cin >> numOne;
					cout << "Please enter the second number: ";
					cin >> numTwo;
				}
			} while (numTwo == 0);
			resultOne = computeDiv(numOne, numTwo);		// calculate division and assign value to resultOne

			// display results
			cout << numOne << " / " << numTwo << " = " << resultOne << endl;
			break;

			// if user selects roots
		case 'E':
			cout << "Please enter your number: ";
			cin >> numOne;
			cout << "Please enter the root value: ";
			cin >> numThree;
			do
			{
				if ((numOne < 0) || (numThree < 0))
				{
					cout << "Please input postive integers only." << endl;
					cout << "Please enter your number: ";
					cin >> numOne;
					cout << "Please enter the root value: ";
					cin >> numThree;
				}
			} while ((numOne < 0) || (numThree < 0));
			resultOne = computeRoot(numOne, numThree);
			cout << numOne << " to the root of " << numThree << " = " << computeRoot(numOne, numThree) << endl;
			break;

		// if user selects powers
		case 'F' :
			cout << "Please enter the base number: ";
			cin >> numOne;
			cout << "Please enter the exponent: ";
			cin >> numThree;

			// call powers function
			resultOne = computePower(numOne, numThree);
			do
			{
				if ((numOne < 0) || (numThree < 0))
				{
					cout << "Please input postive integers only." << endl;
					cout << "Enter the base: ";
					cin >> numOne;
					cout << "Enter the exponent: ";
					cin >> numThree;
				}
			} while ((numOne < 0) || (numThree < 0));
			resultOne = computePower(numOne, numThree);
			cout << numOne << " to the power of " << numThree << " = " << resultOne << endl;
		break;

		// user selects percentage
		case 'G' :
			// collect user input
			cout << "Please enter your number here: ";
			cin >> numOne;
			cout << "Please enter the desired percentage: ";
			cin >> numTwo;
			resultOne = computePerc(numOne, numTwo);
			cout << numTwo << "% of " << numOne << " is " << resultOne << endl;
			break;

		// user selects LCM
		case 'H' :
			// collect user input
			cout << "Please enter the first whole number: ";
			cin >> numThree;
			cout << "please enter the second whole number: ";
			cin >> numFour;
			if ((numThree < 0) || (numFour < 0))
			{
				cout << "Please use postiive numbers only." << endl;
				cout << "Please enter the first whole number: ";
				cin >> numThree;
				cout << "please enter the second whole number: ";
				cin >> numFour;
			}
			resultOne = computeLCM(numThree, numFour); // calculate LCM and assign value to resultOne
			cout << "The LCM of " << numThree << " and " << numFour;
			cout << " is: " << resultOne << endl; 
			break;
		
		// user selects GCD
		case 'I' :
			// promt user for both numbers
			cout << "Please enter the first whole number: ";
			cin >> numThree;
			cout << "Please enter the second whole number: ";
			cin >> numFour;
			if ((numThree < 0) || (numFour < 0))
			{
				cout << "Please use postiive numbers only." << endl;
				cout << "Please enter the first whole number: ";
				cin >> numThree;
				cout << "please enter the second whole number: ";
				cin >> numFour;
			}
			resultTwo = computeGCD(numThree, numFour);	// calculate GCD and assign value to resultTwo
			cout << "The GCD for " << numThree << " and " << numFour << " is " << resultOne << endl;
			break;

		// user selects modulus
		case 'J' :
			cout << "Please enter the first number: ";
			cin >> numThree;
			cout << "Please enter the second number: ";
			cin >> numFour;
			resultTwo = computeMod(numThree, numFour); // calculate modulus and assign value to resultTwo
			cout << "The modulo of " << numThree << " and " << numFour << " is " << resultTwo << endl;
			break;

		// if user selects quit
		case 'L':
			quit();
			break;

		// if user's input was invalid
		default:
			cout << "An invalid input was read. " << endl;
		}

		cout << endl;

	} while (menuChoice != 'L');
	
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
float computeMul(float a, float b)
{
	float c;
	c = a * b;
	return c;
}

/*
Author: Peter O'Donohue
Creation Date: 03/13/17
Modification Date: 03/14/17
Purpose: calculate division
*/
float computeDiv(float a, float b)
{
	float c;

	c = a / b;
	return c;
}

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
Purpose: calculate powers
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

/*
Author: Peter O'Donohue
Creation Date: 03/14/17
Modification Date: 03/14/17
Purpose: calculate percentage
*/
float computePerc(float a, float b)
{
	float c;
	c = a * (b * .01);
	return c;
}

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

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/14/17
Purpose: calculate modulus
*/
int computeMod(int a, int b)
{
	int c;
	c = a % b;
	return c;
}

// display functions execute

/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/14/17
Purpose: print exit message
*/
void quit()
{
	cout << endl << "Thanks for using my application! " << endl << "Have a great day!" << endl << endl;
}