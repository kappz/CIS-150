/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/08/17
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

// define input and output files
#define chartIn "chartIn.txt"
#define chartOut "chartOut.txt"

// declare struct
struct rows
{
	int Row;
	char a, b, c, d;
};

// declare array
rows seatChat[][];

// declare functions

/*
Author: Peter O'Donohue
Creation Date: 04/08/17
Modification Date: 04/08/17
Purpose: main function
*/
int main()
{

	system("pause");
	return 1;
}