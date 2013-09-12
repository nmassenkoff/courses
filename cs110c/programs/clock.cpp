#include "clock.h"
#include <math.h>
#include <iostream>

using namespace std;

Clock::Clock()
{
	hours = 0;
	minutes = 0;
}
Clock::Clock(int inHours, int inMinutes)
{
	if (inHours > 23)
		inHours = 23;
	if (inMinutes > 59)
		inMinutes = 59;

	hours = inHours;
	minutes = inMinutes;
}

void Clock::setTime(int inHours, int inMinutes)
{
	hours = inHours;
	minutes = inMinutes;
}

void Clock::addMinutes(int numMinutes)
{
	if (numMinutes < 0) 
		numMinutes = 0;
	minutes +=  numMinutes;
	hours += floor(minutes / 60);

	minutes = minutes % 60;
}

void Clock::displayMinutes()
{
	if (minutes < 10)
	{
		cout << "0" << minutes;

	} else {
		cout << minutes;
	}
}

void Clock::display12()
{
	if (hours > 12)
	{
		cout << hours - 12 << ":" ;
		displayMinutes();
		cout << " pm" << endl;
	} else if (hours == 12) {
		cout << hours << ":" ;
		displayMinutes();
		cout << " pm" << endl;
	} else {
		cout << hours << ":" ;
		displayMinutes();
		cout << " am" << endl;
	}
}

void Clock::display24()
{
	cout << hours << ":" ;
	displayMinutes();
	cout << endl;
}

