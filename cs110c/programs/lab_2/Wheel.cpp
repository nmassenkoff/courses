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
	int value;
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

void Wheel::displaySpin(int targetPos) const
{
	// initialize variables pertaining to the wheel spin physics
	double speed = 1;
	double delay = 10;
	double resistance = pow(10.0, -33);
	bool preSpin = true;

	// Print wheel arrow that points at current value
	cout << "                           |\n";
	cout << "                           |\n";
	cout << "                           |\n";
	cout << "                           V\n";

	// Initialize variables that help determine how to wrap numbers arround
	int i, j;
	int pos = 1;
	int numItems = getLength();
	int tempPos = currentPos;
	int lastItem = translatePos(currentPos + 10);
	int firstItem = translatePos(currentPos + 11);
	ListItemType listItemValue;
	while(true)
	{
		// Main loop that animates the wheel spinning
		j = 2;
		if ( pos == 1 )
		{
			// Position one prints the last digit of the first value 
			retrieve(firstItem, listItemValue);
			cout << listItemValue % 10;
			cout << ' ';
		}
		else if ( pos == 0)
		{
			// Position 0 prints the whole first value
			retrieve(firstItem, listItemValue);
			cout << listItemValue;
			cout << ' ';
		}

		for (i = firstItem + 1; j <= numItems ; i++) {
			// This loop prints all the values that aren't the first value
			// and depending on the position, a space before the value or after
			if (pos == 2)
			{
				retrieve(translatePos(i), listItemValue);
				cout << ' ' << listItemValue;
			}
			else
			{
				retrieve(translatePos(i), listItemValue);
				cout << listItemValue << ' ';	
			}
			j++;
		}

		// Determine what to print at the end of the line depending on the position
		// Also advance tempPos if position has cycled to next position
		if ( pos == 1) 
		{
			retrieve(firstItem, listItemValue);
			cout << "\b ";
			cout << listItemValue / 10;
			cout << ' ';
			pos++;

		} else if ( pos == 2) {
			retrieve(firstItem, listItemValue);
			cout << " ";
			cout << listItemValue;
			cout << ' ';
			pos = 0;
			tempPos = translatePos(tempPos + 1);
			firstItem = translatePos(tempPos + 11);

		} else {
			cout << ' ';
			pos++;
		}

		// Delay the update of the display to simulate spinning animation
		// Flush output buffer and return cursor to begining of line to print 
		// next frame
		usleep(delay);
		cout.flush();
		cout << "\r";

		if (preSpin)
		{
			// If intial frame of spin, pause first to
			// show current position of values before animating spin
			usleep(1000000);
			preSpin = false;
		}

		// Increase delay for next frame
		delay = resistance * (pow(speed,17));
		speed+= 0.1;
		
		// If spin slows enough and current pos matches target position then stop
		// animation and exit function
		if (delay > 80000 && tempPos == targetPos && pos == 2)
		{
			cout << endl;
			break;
		} 
		else if (delay < 0)
		{
			delay = 10;
		}

	}
}
