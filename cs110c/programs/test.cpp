#include "clock.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{

	int userHours;
	int userMinutes;

	cout << "Enter Initial Time." << endl;
	cout << "Hours (must be 0-23): ";
	cin >> userHours;

	cout << "Minutes (must be 0-59): ";
	cin >> userMinutes;

	Clock userClock(userHours, userMinutes);

	cout << "Inital time is: ";
	userClock.display12();
	cout << endl << endl;

	char keepGoing = 'y';

	while (keepGoing != 'n')
	{
		cout << "Add minutes to time: ";
		cin >> userMinutes;

		userClock.addMinutes(userMinutes);

		cout << "Time is now: ";
		userClock.display12();
		cout << endl << endl;

		cout << "Keep going? (y/n): ";
		cin >> keepGoing;
		cout << endl << endl;
	}

	cout << "Goodbye, come again..." << endl;
	return 0;
}
