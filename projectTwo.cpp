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
using namespace std;

// input and output files
#define chartIn "chartIn.txt"
#define chartOut "chartOut.txt"

// array to store seat chart
char seatChart[1000][1000];

// function declarations
int readFile(ifstream& inFile, int& row, int col);
void fillArray(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);

/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/11/17
Purpose: main function
*/
int main()
{
	// main variables
	int rowSize = 0;
	int colSize = 0;
	ifstream ins;
	ofstream outs;

	// open input file
	ins.open(chartIn);
	if (ins.fail())
		cout << "Error: Failed to open seat chart file." << endl;

	colSize = readFile(ins, rowSize, colSize); // compute number of rows and columns
	cout << rowSize << endl << colSize << endl;
	fillArray(ins, seatChart, rowSize, colSize); // fill array with data from text file
	system("pause");
	return 1;
}

// function definitions

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
	++col;
	while (nextCh != NWLN)
	{
		inFile >> nextCh;
		++col;
		inFile.get(nextCh);
	}
	// reset pointer to beginning of file
	inFile.clear();
	inFile.seekg(0);

	// get number of rows
	getline(inFile, line);
	++rows;
	while ((line.length() != 0) && (!inFile.eof()))
	{
		++rows;
		getline(inFile, line);
	}
	// reset pointer to beginning of file
	inFile.clear();
	inFile.seekg(0);
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
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			cout << seatChart[i][j] << " ";
			if (j == cols - 1)
				cout << endl;
		}
	return;
}