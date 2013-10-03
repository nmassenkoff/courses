#include "Player.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	Wheel myWheel;
	Player players[3];
	char spinAgain;
	char userInput;

	for (int i = 0; i < 3; i++)
	{
		spinAgain = 'y';
		userInput = 'n';
		
		while(userInput != 'y')
		{
			cout << "Player " << i+1 << " are you ready to spin? (y/n):  " ;
			cin >> userInput;
		}

		while(spinAgain == 'y')
		{

			players[i].spin(myWheel);
			players[i].printScore();

			cout << "Whould you like to spin again? (y/n):  ";
			cin >> spinAgain;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "Player " << i+1 << " final score:" << players[i].totalPoints() << endl;
	}

	return 0;
}
