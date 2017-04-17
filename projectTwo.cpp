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



// input file
#define chartIn "chartIn.txt"

// seat chart array
char seatChart[1000][1000];

// function declarations
int readFile(ifstream& inFile, int& row, int col);
void quit();
void menu();
void options();
void greeting();
void statistics(char seatChart[1000][1000], int rows, int cols);
void cancelSeat(char seatChart[1000][1000], int rows, int cols);
void reserveSeat(char seatChart[1000][1000], int rows, int cols);
void saveChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);
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
	
	ins.open(chartIn);
	if (ins.fail())
		cout << "ERROR: Unable to open input file." << endl;

	colSize = readFile(ins, rowSize, colSize); // compute number of rows and columns
	fillArray(ins, seatChart, rowSize, colSize); // fill array with data from text file
	
	// display menu
	menu();
	cout << "Please select an option: "; // prompt user for choice
	cin >> userChoice;

	do
	{
		switch (userChoice)
		{

		case 1:
			displayChart(ins, seatChart, rowSize, colSize); // display seat chart
			break;

		case 2 :
			reserveSeat(seatChart, rowSize, colSize);
			break;

		case 3 :
			cancelSeat(seatChart, rowSize, colSize);
			break;

		case 4 :
			saveChart(ins, seatChart, rowSize, colSize);
			break;

		case 5:
			statistics(seatChart, rowSize, colSize);
			break;

		case 7 :
			quit();
			break;

		default :
			cout << "Error: Invalid input. " << endl;
		}
		options();
		cout << "Please select another option: ";
		cin >> userChoice;
	} while (userChoice != 7);
	if (userChoice == 7)
		quit();


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
Purpose: exit message
*/
void quit()
{
	cout << "You've officially reserved your seats!" << endl << "Goodbye." << endl;
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
	cout << "----------------------------------------------" << endl << endl
	     << "1.) Display Seat Chat" << endl
		 << "2.) Reserve Seat" << endl
		 << "3.) Cancel Reservation" << endl
		 << "4.) Save Seat Chart to File" << endl
		 << "5.) Statistics" << endl
		 << "6.) Help" << endl
		 << "7.) Quit" << endl << endl
	     << "----------------------------------------------" << endl;
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
	cout << "----------------------------------------------" << endl
		 << "   *  *  AIRPLANE SEAT SELECTOR  *  *" << endl
		 << "----------------------------------------------" << endl;

	greeting();  //display greeting message
	options();  // display list of options4
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
Modification Date: 04/15/17
Purpose: display seat chart
*/
void displayChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols)
{
	cout << "----------------------------------------------" << endl << endl;
	for (int i = 0; i < rows; ++i)
	{
		if (i >= 99)
			cout << "ROW " << i + 1 << setw(3);
		else if (i >= 9 && i <= 98)
			cout << "ROW " << i + 1 << setw(4);
		else
		cout << "ROW " << i + 1 << setw(5);
		
		for (int j = 0; j < cols; ++j)
		{
			cout << seatChart[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl << "----------------------------------------------" << endl;
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/13/17
Modification Date: 04/15/17
Purpose: reserve seat
*/
void reserveSeat(char seatChart[1000][1000], int rows, int cols)
{
	// variables to store user's seat choice
	int userRow;
	int userCol;
	int tempRow = 0;
	char userSeat;
	char reserved = 'X';

	// collect user input
	cout << "Seats B and C are aisle seats, while A and D are windows seats." << endl;
	cout << "Please enter your desired row number and seat choice: ";
	cin >> userRow >> userSeat;
	tempRow = userRow;

		tempRow -= 1;
		
		userSeat = toupper(userSeat);
		userCol = int(userSeat) - 65;
		if (userSeat == seatChart[tempRow][userCol])
		{
			cout << "Seat " << userRow << userSeat << " reservered." << endl;
			seatChart[tempRow][userCol] = reserved;
		}
		else
		{
			cout << "Seat " << userRow << userSeat << " is not available." << endl;
		}
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/16/17
Modification Date: 04/16/17
Purpose: cancel reservation
*/
void cancelSeat(char seatChart[1000][1000], int rows, int cols)
{
	int userRow;  // stores index row number
	int userCol; // stores index column nmmber
	int tempRow = 0; // stores row number for print
	char userSeat;	// store user's seat choice

	// prompt user for seat to be cancelled
	cout << "Seats B and C are aisle seats, while seats A and D are considered windows seats.";
	cout << "Enter the row number and letter for the seat you wish the cancel: ";
	cin >> userRow >> userSeat;
	userSeat = toupper(userSeat);
	tempRow = userRow;
	userCol = int(userSeat) - 65; // change userSeat char to ascii int value for array index
	userRow -= 1; // change to reflect array index number


	// check if seat is reserved
	if (seatChart[userRow][userCol] == 'X')
	{
		seatChart[userRow][userCol] = userSeat;
		cout << "Reservartion for seat " << tempRow << userSeat << " has been canceled." << endl;
	}
	else
	{
		cout << "Unable to cancel reservation, seat " << tempRow << userSeat
			 << " has not yet been reserved." << endl;
	}

	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/13/17
Purpose: save seat chart
*/
void saveChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols)
{
	string fileName;  // variable for user's file name
	ofstream outs;
	cout << "Enter a file name to store the seat chart in: ";
	cin >> fileName;
	outs.open(fileName.c_str());
	if (outs.fail())
		cout << "Error: Failed to open file." << endl;
	else
		for (int i = 0; i < rows; ++i)
		{
			outs << "Row " << i + 1;
			if ((i >= 99) && (i < 999))
				outs << "    ";
			else if ((i >= 9) && (i < 99))
				outs << "      ";
			else
				outs << "        ";
			for (int j = 0; j < cols; ++j)
			{
				outs.put(seatChart[i][j]);
				outs << "      ";
			}
			outs.put('\n');
			
		}
		cout << "Seat chart saved to file '" << fileName << "'" << endl;

	
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/16/17
Modification Date: 04/16/17
Purpose: statistics
*/
void statistics(char seatChart[1000][1000], int rows, int cols)
{
	int totalSeats;
	int reservedSeats;
	int availableSeats = 0;  // stores number of available seats
	float rsrvdSeatsPrctg;

	totalSeats = rows * cols; // calculate total seats
	cout << totalSeats << endl;
	// calculate number of available seats;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (seatChart[i][j] != 'X')
				++availableSeats;
		}
	}

	// calculate percentage of reserved seats
	totalSeats = rows * cols; // calculate total seats
	reservedSeats = totalSeats - availableSeats;
	rsrvdSeatsPrctg = (float(reservedSeats) / float(totalSeats)) * 100;
		
	return;
}