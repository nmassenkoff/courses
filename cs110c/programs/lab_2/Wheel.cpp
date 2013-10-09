// =====================================================================================
// 
//       Filename:  Wheel.cpp
// 
//    Description:  Implementation of Wheel class
// 
//        Version:  1.0
//        Created:  10/02/2013 12:47:58
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Wheel.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

Wheel::Wheel(): List(), currentPos(1)
{
	// Seed random number generator
	srand((unsigned)time(NULL));

	// create a list containing all possible values for each wheel list item
	List possibleValues;
	ListItemType newItem;
	for (int i = 1; i <= 20; i++)
	{
		newItem = i * 5;
		possibleValues.push(newItem);
	}

	// Randomly select each possible item and add them to the wheel list
	int random_pos;
	ListItemType value;
	for (int i = 1; i <= 20; i++)
	{
		random_pos = randomInt(1,possibleValues.getLength());
		possibleValues.retrieve(random_pos, value);

		push(value);
		possibleValues.remove(random_pos);
	}

}

ListItemType Wheel::getNumber() const
{
	ListItemType value;
	retrieve(currentPos, value);
	return value;
}

void Wheel::spin()
{
	int shift = randomInt(22, 42);
	int newPos = currentPos + shift;
	newPos = translatePos(newPos);

	displaySpin(newPos);

	currentPos = newPos;
}

int Wheel::randomInt(int min, int max)
{
	max++;
	return (rand()%(max-min))+min;
}

int Wheel::translatePos(int linearPos) const
{
	return ((linearPos -1) % 20) + 1;
}

void printFirstNum(int offset, int value)
{
	// Helper function for displaySpin() that determines which digits
	// of the first number to print
	// pre: 0 <= offset <= 3; value representing whatever is currently the first
	//      number displayed on the wheel.
	// post: none
	// note: * = space in comments
	
	int dec = value % 100;
	if (dec >= 10)
	{
		// value is 2 digits
		// displayed as *10*
		switch(offset)
		{
			case 0:
				// output *10*
				cout << ' ' << value << ' ';
				break;
			case 1:
				// output 10*
				cout << value << ' ';
				break;
			case 2:
				// output 0*
				cout << value % 10 << ' ';
				break;
			case 3:
				// output *
				cout << ' ';
				break;
		}
	}
	else if (dec >= 1)
	{
		// value is 1 digit
		// displayed as **1*
		switch(offset)
		{
			case 0:
				// output *1**
				cout << ' ' << value << "  ";
				break;
			case 1:
				// output 1**
				cout << value << "  ";
				break;
			case 2:
				// output **
				cout << "  ";
				break;
			case 3:
				// output *
				cout << ' ';
				break;
		}

	}
	else 
		// value is 100
		// Displayed as 100*
		switch(offset)
		{
			case 0:
			// output 100*
				cout << value << ' ';
				break;
			case 1:
			// output 00*
				cout << "00 ";
				break;
			case 2:
			// output 0*
				cout << "0 ";
				break;
			case 3:
			// output *
				cout << " ";
				break;
		}
}
void printLastNum(int offset, int value)
{
	// Helper funciton for displaySpin() that determines which digits of the
	// last number to print
	// pre: 0 <= offset <= 3; value representing whatever is currently the last
	//      number displayed on the wheel.
	// post: none
	// note: * = space

	int dec = value % 100;
	if (dec >= 10)
	{
		// value is 2 digits
		// displayed as *10*
		switch(offset)
		{
			case 0:
			// output: 
				break;
			case 1:
			// output: *
				cout << ' ';
				break;
			case 2:
			// output: *1
				cout << ' ' << value / 10;
				break;
			case 3:
			// output: *10
				cout << ' ' << value;
				break;
		}
	}
	else if (dec >= 1)
	{
		// value is 1 digit
		// displayed as *1**
		switch(offset)
		{
			case 0:
			// output: 
				break;
			case 1:
			// output: *
				cout << " ";
				break;
			case 2:
			// output: *1
				cout << ' ' << value;
				break;
			case 3:
			// output: *1*
				cout << ' ' << value << ' ';
				break;
		}

	}
	else 
		// value is 100
		// displayed as 100*
		switch(offset)
		{
			case 0:
			// output:
				break;
			case 1:
			// output: 1
				cout << "1";
				break;
			case 2:
			// output: 10
				cout << "10";
				break;
			case 3:
			// output: 100
				cout << "100";
				break;
		}
}

void Wheel::displaySpin(int targetPos) const
{
	// initialize variables pertaining to the wheel spin physics
	double speed = 1;
	double delay = 10;
	double resistance = pow(10.0, -33);
	bool preSpin = true;

	// Print wheel arrow that points at current value
	cout << "                                    |\n";
	cout << "                                    |\n";
	cout << "                                    |\n";
	cout << "                                    V\n";

	// Initialize variables that help determine how to wrap numbers arround
	int i, j;
	int offset = 1;
	int numItems = getLength();
	int tempPos = currentPos;
	int lastItem = translatePos(currentPos + 10);
	int firstItem = translatePos(currentPos + 11);
	ListItemType listItemValue;
	
	while(true)
	{
		// Main loop that animates the wheel spinning

		// Print first number accounting for the offset position
		retrieve(firstItem, listItemValue);
		printFirstNum(offset, listItemValue);

		for (i = firstItem + 1, j = 2; j <= numItems ; i++, j++) // skip 1st item of wheel
		{ 
			// This loop prints all the values that aren't the first value
			// and depending on the position and number of digits, spaces
			// before the value or after
			// j keeps count of the actual number of items that we have printed
			// i keeps track of the actual index of the item currently being printed

			retrieve(translatePos(i), listItemValue);
			if (listItemValue % 100 >= 10)
				cout << ' ' << listItemValue << ' ';
			else if (listItemValue % 100 >= 1)
				cout << ' ' << listItemValue << "  ";
			else
				cout << listItemValue << ' ';

		}

		// Determine what to print at the end of the line depending on the offset
		retrieve(firstItem, listItemValue);
		printLastNum(offset, listItemValue);

		// Cycle offset counter
		offset = (offset + 1) % 3;
		if (offset == 0) 
		{
			// Advance tempPos if position has cycled through to zero
			tempPos = translatePos(tempPos + 1);
			firstItem = translatePos(tempPos + 11);
		}


		// Delay the update of the display to simulate spinning animation
		// Flush output buffer and return cursor to begining of line to print 
		// next frame
		usleep(delay);
		cout.flush();
		cout << "\r";

		if (preSpin)
		{
			// If initial frame of spin, pause first to
			// show current position of values before animating spin
			usleep(1000000);
			preSpin = false;
		}

		// Increase delay for next frame
		delay = resistance * (pow(speed,17));
		speed+= 0.1;
		
		// If spin slows enough and current offset matches target position then stop
		// animation and exit function
		if (delay > 90000 && tempPos == targetPos && offset == 2)
		{
		// end animation after pausing on final number
		// by breaking out of the loop and ending function
			usleep(800000);
			cout << endl;
			break;
		} 
		else if (delay < 0)
		{
		// Delay can't be negative
			delay = 10;
		}

	}
}
