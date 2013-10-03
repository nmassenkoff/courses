#include "Player.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	Wheel myWheel;
	Player players[3];
	int playerRanking[3];
	char spinAgain;
	char userInput;
	char playAgain = 'y';

	while(playAgain == 'y')
	{
		// Main game loop
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

				if (players[i].totalPoints() > 100)
				{
					cout << "Oh no! You've busted... your total score is over 100.  Better luck next time." << endl;
					break;
				}

				if (players[i].numSpins() < 2)
				{
					cout << "Whould you like to spin again? (y/n):  ";
					cin >> spinAgain;
				}
				else
					spinAgain = 'n';
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (players[i].totalPoints() <= 100)
				cout << "Player " << i+1 << " final score:" << players[i].totalPoints() << endl;
			else
				cout << "Player " << i+1 << " final score:" << players[i].totalPoints() << "  **(Busted)** " << endl;

		}

		// Initialize rankings array
		for (int i = 0; i < 3; i++)
			playerRanking[i] = i;

		int tmp;
		for (int i = 2; i >= 1; i--)
		{
			// Bubble highest score to the top of rankings
			if (players[playerRanking[i]].totalPoints() > players[playerRanking[i-1]].totalPoints())
			{
				// current element is larger than next, so swap
				tmp = playerRanking[i];
				playerRanking[i] = playerRanking[i-1];
				playerRanking[i-1] = tmp;
			}
		}

		// Bubble second highest score
		if (players[playerRanking[2]].totalPoints() > players[playerRanking[1]].totalPoints())
		{
			tmp = playerRanking[2];
			playerRanking[2] = playerRanking[1];
			playerRanking[1] = tmp;
		}

		// Find the highest score that isn't a bust
		int highestWithoutBust = NULL;
		for (int i = 0; i < 3; i++)
			if (players[playerRanking[i]].totalPoints() <= 100)
			{
				highestWithoutBust = i;
				break;
			}

		// Determine if there are any ties
		bool twoTieFlag = false;
		bool threeTieFlag = false;
		bool allBustFlag = false;
		switch(highestWithoutBust)
		{
			case 0:
				if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[1]].totalPoints())
					twoTieFlag = true;
				else if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[2]].totalPoints())
					threeTieFlag = true;
				break;
			case 1:
				if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[2]].totalPoints())
					twoTieFlag = true;
				break;
			default:
				allBustFlag = true;
		}
		
		cout << endl;

		// Display correct message for whether there were any ties, or if there was a winner
		if (threeTieFlag)
		{
			cout << "All three players tied with a score of: " << players[0].totalPoints();
		}
		else if (twoTieFlag)
			cout << "Players " 
				<< playerRanking[highestWithoutBust]+1 
				<< " and " 
				<< playerRanking[highestWithoutBust]+2 
				<< " tied with a score of: " 
				<< players[playerRanking[highestWithoutBust]].totalPoints();
		else if (allBustFlag)
			cout << "All of you busted, your scores were over 100";
		else
			cout << "Player "
				<< playerRanking[highestWithoutBust]+1
				<< " had the highest score of "
				<< players[playerRanking[highestWithoutBust]].totalPoints()
				<< " and is the WINNER!";
				
		cout << endl;
		cout << endl;
		cout << "**********************" << endl;
		cout << "*      GAME OVER     *" << endl;
		cout << "**********************" << endl;
		cout << endl;
		cout << endl;

		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;

		// if playAgain reset each player
		if (playAgain == 'y')
			for (int i=0; i < 3; i++)
				players[i].reset();
	}
	return 0;
}
