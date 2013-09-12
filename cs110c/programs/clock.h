#include <string.h>

class Clock 
{
	int hours;
	int minutes;

public:
	Clock();
	Clock(int, int);

	void setTime(int, int);

	void addMinutes(int);

	void displayMinutes();
	void display12();
	void display24();
};
