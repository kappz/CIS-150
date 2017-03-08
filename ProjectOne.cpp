/*
Author: Peter O'Donohue
Creation Date: 03/07/17
Modification Date: 03/07/17
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
	float firstNumber = 0.0;
	float secondNumber = 0.0;
	float addition = 0.0; 
	float subtraction = 0.0;
	float muliplication = 0.0;
	float division = 0.0;
	float root = 0.0;
	float power = 0.0;
	float percentage = 0.0;
	int firstInteger = 0;
	int secondInteger = 0;
	int lcm = 0;
	int gcd = 0;
	int modulus = 0;

	// display greeting
	greeting();

	do
	{
		// display menu
		menu();

		cout << "Please select a choice from the list above: " << endl;
		cin >> menuChoice;
		menuChoice = toupper(menuChoice);
		
		switch (menuChoice)
		{

		case 'H' :
			cout << "Please enter two integers: ";
			cin >> firstInteger >> secondInteger;
			lcm = computeLCM(firstInteger, secondInteger);
			cout << lcm;
			break;
		case 'L':
			quit();
			break;
		default:
			cout << "An invalid input was read. "
				 << "Please choose an option from the list above: ";
			cin >> menuChoice;
			menuChoice = toupper(menuChoice);
		}

		cout << "Please choose another option" << endl;
		cin >> menuChoice;
		menuChoice = toupper(menuChoice);
	} while (menuChoice != 'Q');
	
	// display goodbye message

	system("pause");
	return 1;
}

// greeting message
void greeting()
{
	cout << "----------------------------" << endl;
	cout << "C  A  L  C  U  L  A  T  O  R" << endl;
	cout << "----------------------------" << endl << endl;
}
// menu
void menu()
{
	cout << "Please selection an option below." << endl << endl;
	cout << "A.)  A D D I T I O N" << endl;
	cout << "B.)  S U B T R A C T I O N" << endl;
	cout << "C.)  M U L T I P L I C A T I O N" << endl;
	cout << "D.)  D I V I S I O N" << endl;
	cout << "E.)  R O O T S (positive numbers only)" << endl;
	cout << "F.)  P O W E R S (postive numbers only)" << endl;
	cout << "G.)  P E R C E N T A G E" << endl;
	cout << "H.)  L E A S T  C O M M O N  M U L T I P L I E R" << endl;
	cout << "I.)  G R E A T E S T  C O M M O N  D I V I S O R" << endl;
	cout << "J.)  M O D U L U S" << endl;
	cout << "K.)  D I S P L A Y   F U N C T I O N  E X E C U T I O N" << endl;
	cout << "L.)  Q U I T" << endl << endl;
}

// compute addition

// compute subraction

// compute multiplication

// compute division

// compute root

// compute power

// computer percentage

// compute lcm
int computeLCM(int a, int b)
{
	int tmp_lcm;
	tmp_lcm = ((a * b) / computeGCD(a, b));
	return tmp_lcm;
}

// compute gcd
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

// quit
void quit()
{
	cout << "Good day to you!" << endl;
}