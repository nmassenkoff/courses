// =====================================================================================
// 
//       Filename:  test_wheel.cpp
// 
//    Description:  Wheel picker 
// 
//        Version:  1.0
//        Created:  09/16/2013 15:43:58
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include <iostream>
#include <unistd.h>
#include <cmath>
#include <ctime>

using namespace std;

const int width = 20;

int spinWheel (int myArray[], const int &width, int current_index, double &strength)
{

	int size = width-1;
	int i, j;
	int pos = 0;
	int lastItem = size;
	current_index = 0;
	double speed = (rand() % 100 + 2)/2 * (-1000 * strength);
	double shift = rand() % 1000;
	double delay;
	double resistance = pow(10.0, -33);
	cout << "Speed: " << speed << endl;
	cout << "Resistance: " << resistance << endl;
	speed = -10000;

	cout << "                           |\n";
	cout << "                           |\n";
	cout << "                           |\n";
	cout << "                           V\n";

	while(true)
	{
		j = 0;
		if ( pos == 1 )
			cout << ' ';
		else if ( pos == 2)
			cout << myArray[lastItem] % 10;

		for (i = current_index; j < width; i++) {
			if (i < 0) 
			{
				i = size;
			} else if (i > size) {
				i = 0;
			}

			if (pos == 2)
				cout << ' ' << myArray[i];
			else
				cout << myArray[i] << ' ';	
			j++;
		}
		if ( pos == 1) 
		{
			cout << "\b\b ";
			pos++;
		} else if ( pos == 2) {
			cout << "\b\b ";
			pos = 0;
			current_index--;
			if (current_index < 0)
				current_index = size;
		} else {
			lastItem = i - 1;
			if (lastItem < 0)
				lastItem = size;
			pos++;
		}

		delay = resistance * (pow((speed - shift),17));
		if (delay > 800000 && pos == 1)
		{
			int selection;
			if (current_index + (size/2) > size) 
				selection = (current_index + (size/2)) - width;
			else
				selection = current_index + (size/2);
			cout << endl;
			cout << "The number you spun is: " << myArray[selection] << "  Index = " << selection  << endl; 
			return selection;
		} else if (delay < 0) {
			delay = 10;
		}
		cout << "   Speed: " << speed << "       ";
//		usleep(delay);
		speed += 1;
		cout.flush();
		cout << "\r";

	}
}

void testRandomSpread(int numTests, int numbers[], int width, int index, double strength) {
	int counter[20];

	for (int k = 0 ; k < 20 ; k++)
	{
		counter[k] = 0;
	}

	for (int k = 0 ; k < numTests ; k++)
	{
		counter[spinWheel(numbers, width, index, strength)]++;
		cout << "*********************" << k << "*********************************" << endl;
	}

	for (int k=0 ; k < 20 ; k++)
	{
		cout << k << " : " << counter[k] << "  (%" << counter[k]/1000.0 * 100 << ")" << endl;
	}

}

int main(int argc, const char *argv[])
{
	srand((unsigned)time(NULL));
	int numbers[width];
	for (int i = 0 ; i < width ; i ++) 
	{
		numbers[i] = (i + 1) * 5;
	}
	double strength = 1;
	while(true)
	{
		cout << "How hard would you like to spin? (Enter a number 1-10): " ;
		cin >> strength;

		spinWheel(numbers, width, 3, strength);
	}
//	testRandomSpread(100000, numbers, width, 3, 10);
	return 0;
}
