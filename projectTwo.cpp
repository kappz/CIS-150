/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/11/17
Purpose: Practice with c++
*/

// ProjectTwo.cpp
// from project two
// this program presents the user with a seat chart for an upcoming airplane flight.
// the user can observe which seats are available and which are taken taken. the user 
// can then reserve and cancel seats as needed, as well as save the seat chart to a file.

// c++ libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// input and output files
#define chartIn "chartIn.txt"
#define chartOut "chartOut.txt"

// seat chart array
char seatChart[1000][1000];

// function declarations
int readFile(ifstream& inFile, int& row, int col);
void menu();
void options();
void greeting();
void displayChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);
void fillArray(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);

/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/11/17
Purpose: main function
*/
int main(){
	// main variables
	int userChoice;
	int rowSize = 0;
	int colSize = 1;
	ifstream ins;
	ofstream outs;

	// open input file
	ins.open(chartIn);
	if (ins.fail())
		cout << "Error: Failed to open seat chart file." << endl;

	colSize = readFile(ins, rowSize, colSize); // compute number of rows and columns
	fillArray(ins, seatChart, rowSize, colSize); // fill array with data from text file
	
	// display menu
	menu();
	cout << "Please select an option: "; // prompt user for choice
	cin >> userChoice;

	while (userChoice != 7)
	{
		switch (userChoice)
		{

		case 1:
			displayChart(ins, seatChart, rowSize, colSize); // display seat chart
			break;

		default:
			cout << "Goodbye!" << endl;
		}
		system("pause");
		options();
		cout << endl << "Please select the next option: " << endl;
		cin >> userChoice;
	}

	system("pause");
	return 1;
}

// function definitions

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/11/17
Purpose: greeting message
*/
void greeting()
{
	cout << endl << "Hello!" << endl << "This program will help you reserve seats" << endl
		<< "for your flight." << endl << "Below is a menu to help guide you through" << endl
		<< "the process." << endl << endl;
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/11/17
Purpose: list of options
*/
void options()
{
	cout << "-----------------------------------------" << endl << endl
	     << "1.) Display Seat Chat" << endl
		 << "2.) Reserve Seat" << endl
		 << "3.) Cancel Reservation" << endl
		 << "4.) Save Seat Chart to File" << endl
		 << "5.) Statistics" << endl
		 << "6.) Help" << endl
		 << "7.) Quit" << endl << endl
	     << "-----------------------------------------" << endl;
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/11/17
Purpose: menu
*/
void menu()
{
	cout << "-----------------------------------------" << endl
		 << "   *  *  AIRPLANE SEAT SELECTOR  *  *" << endl
		 << "-----------------------------------------" << endl;

	greeting();  //display greeting message
	options();  // display list of options
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/11/17
Purpose: read file
*/
int readFile(ifstream& inFile, int& rows, int col)
{
	// local variables
	const char NWLN = '\n';
	char nextCh;
	string line;

	// get number of columns
	inFile.get(nextCh);
	while (nextCh != NWLN)
	{
		inFile >> nextCh;
		++col;
		inFile.get(nextCh);
	}

	inFile.seekg(0);  // reset pointer to beginning of file

	// get number of rows
	getline(inFile, line);
	++rows;
	while ((line.length() != 0) && (!inFile.eof()))
	{
		++rows;
		getline(inFile, line);
	}
	inFile.seekg(0);  // reset pointer to beginning of file
	return col;
}

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/11/17
Purpose: fill array
*/
void fillArray(ifstream& inFile, char seatChart[1000][1000], int rows, int cols)
{
	// local variables
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			inFile >> seatChart[i][j];
		}
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/11/17
Purpose: display seat chart
*/
void displayChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols)
{
	cout << "-----------------------------------------" << endl << endl;
	for (int i = 0; i < rows; ++i)
	{
		if (1 >= 100)
		cout << "Row " << i + 1 << setw(3);
		else if (i >= 9)
		cout << "Row " << i + 1 << setw(4);
		else
		cout << "Row " << i + 1 << setw(5);
		
		for (int j = 0; j < cols; ++j)
		{
			cout << seatChart[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "-----------------------------------------" << endl;
	return;
}