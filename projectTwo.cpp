/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/19/17
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
#define chartIn "chartIn3.txt"

// seat chart array
char seatChart[1000][1000];

// function declarations
int readFile(ifstream& inFile, int& row, int col);
void quit();
void menu();
void help();
void greeting();
void statistics(char seatChart[1000][1000], int rows, int cols);
void cancelSeat(ifstream& ins, char seatChart[1000][1000], int rows, int cols);
void reserveSeat(ifstream& ins, char seatChart[1000][1000], int rows, int cols);
void calculateAisleSeat(char seatChart[1000][1000], int rows, int cols);
void calculateWindowSeat(char seatChart[1000][1000], int rows, int cols);
void saveChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);
void displayChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);
void fillArray(ifstream& inFile, char seatChart[1000][1000], int rows, int cols);

/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/19/17
Purpose: main function
*/
int main(){
	// main variables
	int userChoice;  // stores user's choice
	int rowSize = 0;  // stores number of rows 
	int colSize = 1;  // stores snumber of columns
	ifstream ins;    // reads data in text file data to stream
	ofstream outs;   // writes data to text file using stream
	
	// open input file
	ins.open(chartIn);
	if (ins.fail())
		cout << "ERROR: Unable to open input file." << endl;

	colSize = readFile(ins, rowSize, colSize); // compute number of rows and columns
	fillArray(ins, seatChart, rowSize, colSize); // fill array with data from text file
	
	greeting();  // display greeting message

	// switch case for each menu choice
	do
	{
		// display menu
		menu();
		cout << "Please select an option: "; // prompt user for choice
		cin >> userChoice;
		cout << endl;

		switch (userChoice)
		{

		case 1:  // user chooses to display chart
			displayChart(ins, seatChart, rowSize, colSize); // display seat chart
			system("pause");
			break;

		case 2 :  // user chooses to reserve a seat
			reserveSeat(ins, seatChart, rowSize, colSize);  // reserve seat
			system("pause");
			break;

		case 3 :  // user chooses to cancel a reserved seat
			cancelSeat(ins, seatChart, rowSize, colSize);  // cancel reservation
			system("pause");
			break;

		case 4 :  // user would like to save seat chart to a file
			saveChart(ins, seatChart, rowSize, colSize);  // save seat chart to file
			system("pause");
			break;

		case 5:  // user displays statistics
			statistics(seatChart, rowSize, colSize);  // display statistics
			system("pause");
			break;

		case 6:   // user chooses help
			help();
			system("pause");
			break;

		case 7 :  // quit program
			quit();
			break;

		default :  // user selects an invalid option
			cout << "Error: Invalid input. " << endl; 
		}
	} while (userChoice != 7);

	ins.close();  // close input file
	outs.close();  // close output file
	system("pause");
	return 1;
}

// function definitions

/*
Author: Peter O'Donohue
Creation Date: 04/11/17
Modification Date: 04/19/17
Purpose: greeting message
*/
void greeting()
{
	cout << "----------------------------------------------" << endl
		<< "   *  *  AIRPLANE SEAT SELECTOR  *  *" << endl
		<< "----------------------------------------------" << endl;
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
Modification Date: 04/19/17
Purpose: menu
*/
void menu()
{
	cout << "--------------------MENU----------------------" << endl << endl
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
Modification Date: 04/19/17
Purpose: display seat chart
*/
void displayChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols)
{
	cout << "-------------------SEAT CHART-----------------" << endl << endl;
	for (int i = 0; i < rows; ++i)  // loop through each array element
	{
		if (i >= 99)
			cout << "ROW " << i + 1 << setw(3);  // adjusts spacing
		else if (i >= 9 && i <= 98)
			cout << "ROW " << i + 1 << setw(4);  // adjusts spacing
		else
		cout << "ROW " << i + 1 << setw(5);  // adjusts spacing
		
		for (int j = 0; j < cols; ++j)
		{
			cout << seatChart[i][j] << "  ";  // display each array element
		}
		cout << endl;
	}
	cout << endl << "----------------------------------------------" << endl;
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/13/17
Modification Date: 04/18/17
Purpose: reserve seat
*/
void reserveSeat(ifstream& ins, char seatChart[1000][1000], int rows, int cols)
{
	// variables to store user's seat choice
	int userRow;
	int userCol;
	int tempRow = 0;
	char userSeat;
	char reserved = 'X';

	displayChart(ins, seatChart, rows, cols);  // display chart

	cout << "---------------RESERVE SEATS------------------" << endl;
	cout << "Seats " << seatChart[0][(cols / 2) - 1] << " and " << seatChart[0][cols / 2]  // aisle seats
		<< " are aisle seats." << endl << "Seats " << seatChart[0][0] << " and " << seatChart[0][cols -1] 
		 << " are windows seats." << endl;  // window seats
	cout << "Please enter your desired row number and seat choice: ";
	cin >> userRow >> userSeat;  // collect user's seat choice
	tempRow = userRow;

		tempRow -= 1; // adjust user's choice to allign with correct array row 
		
		userSeat = toupper(userSeat);
		userCol = int(userSeat) - 65;  // assign ascii value to userSeat
		if (userSeat == seatChart[tempRow][userCol])
		{
			cout << "Seat " << userRow << userSeat << " reserved." << endl;
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
Modification Date: 04/18/17
Purpose: cancel reservation
*/
void cancelSeat(ifstream& ins, char seatChart[1000][1000], int rows, int cols)
{
	int userRow;  // stores index row number
	int userCol; // stores index column number
	int tempRow = 0; // stores row number for print
	char userSeat;	// store user's seat choice

	displayChart(ins, seatChart, rows, cols);  //display chart
	cout << "------------CANCEL RESREVATION----------------" << endl;
	// prompt user for seat to be cancelled
	cout << "Seats " << seatChart[0][(cols / 2) - 1] << " and " << seatChart[0][cols / 2]
		<< " are aisle seats." << endl << "Seats " << seatChart[0][0] << " and " << seatChart[0][cols - 1]
		<< " are window seats." << endl;
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
		cout << "Reservation for seat " << tempRow << userSeat << " has been canceled." << endl;
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
Modification Date: 04/19/17
Purpose: save seat chart
*/
void saveChart(ifstream& inFile, char seatChart[1000][1000], int rows, int cols)
{
	
	string fileName;  // variable for user's file name
	ofstream outs;
	cout << "--------------SAVE SEAT CHART-----------------" << endl;
	cout << "Enter a file name to store the seat chart in: ";
	cin >> fileName;
	outs.open(fileName.c_str());  // open user's file
	if (outs.fail())
		cout << "Error: Failed to open file." << endl;
	else
		for (int i = 0; i < rows; ++i)  // for loop for each row
		{
			// display each element and adjust spacing
			outs << "Row " << i + 1;
			if ((i >= 99) && (i < 999))
				outs << "    ";
			else if ((i >= 9) && (i < 99))
				outs << "      ";
			else
				outs << "        ";
			for (int j = 0; j < cols; ++j)  // for loop for each column
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
Modification Date: 04/19/17
Purpose: statistics
*/
void statistics(char seatChart[1000][1000], int rows, int cols)
{
	int totalSeats;  // stores total seats
	int reservedSeats;  // stores number of reserved seats
	int availableSeats = 0;  // stores number of available seats
	float rsrvdSeatsPrctg;  // stores percentage of reserved seats
	cout << "-----------------STATISTICS-------------------" << endl;
	totalSeats = rows * cols; // calculate total seats

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
	
	// print results
	cout << endl << "The total number of seats available is: " << availableSeats << endl << endl;
	cout << "The percentage of reserved seats is: " << fixed << setprecision(2)
		<< rsrvdSeatsPrctg << "%" << endl << endl;
	calculateAisleSeat(seatChart, rows, cols);  // calculate and print available aisle seats
	calculateWindowSeat(seatChart, rows, cols);  // calculate and print available window seats
	cout << endl;
	
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/17/17
Modification Date: 04/18/17
Purpose: calculate available aisle seats
*/
void calculateAisleSeat(char seatChart[1000][1000], int rows, int cols)
{
	cout << "The following aisle seats are still available for reservation:" << endl;
	for (int i = 0; i < rows; ++i)
	{
		if (seatChart[i][(cols / 2) - 1] != 'X') // verify aisle seat isn't reserved
			cout << i + 1 << seatChart[i][(cols / 2) - 1] << " "; // print available aisle seat
		if (seatChart[i][cols / 2] != 'X')  // verify aisle seat isn't reserved
			cout << i + 1 << seatChart[i][cols / 2] << " "; // print available aisle seat
		if (i == (rows / 2) + 1)
			cout << endl;

	}
	cout << endl << endl;
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/17/17
Modification Date: 04/18/17
Purpose: calculate available window seats
*/
void calculateWindowSeat(char seatChart[1000][1000], int rows, int cols)
{
	cout << "The following window seats are still available for reservation:" << endl;
	for (int i = 0; i < rows; ++i)
	{
		if (seatChart[i][0] != 'X')  // verify window seat isn't reserved
			cout << i + 1 << seatChart[i][0] << " ";  // print available window seat
		if (seatChart[i][cols - 1] != 'X')  // verifiy window seat isn't reserved
			cout << i + 1 << seatChart[i][cols - 1] << " "; // print available window seat
		if (i == (rows / 2) + 1)
			cout << endl;

	}
	cout << endl << endl;
	return;
}

/*
Author: Peter O'Donohue
Creation Date: 04/17/17
Modification Date: 04/17/17
Purpose: help message
*/
void help()
{
	cout << "-----------------DIRECTIONS-------------------" << endl
	     << endl << "Start out by displaying the seat chart and reserving a single seat." << endl
		 << "You can reserve a seat by typing in the row number and seat letter (e.g., 2D, 10A, 7C)"
		 << endl << " You can cancel a reservation the same way." << endl
		 << "Once you've reserved a seat, verify that seat was reserved by "
		 << "displaying the seat chart once more." << endl
		 << "Reserved seats are marked with an 'X'. " << endl << endl;
	return;
}