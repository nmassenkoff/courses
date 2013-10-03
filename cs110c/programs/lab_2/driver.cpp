#include "Player.h"
#include <iostream>

using namespace std;


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  For this driver application all the game logic code related to 
//  		  the players spinning and receiving their resulting scores has
//  		  been commented out.
//
//  		  Instead the user is able to enter scores manually for each player's 
//  		  spin.  The rest of the game logic is unchanged from the main program.
// =====================================================================================
int main(int argc, const char *argv[])
{
	Wheel myWheel;
	Player players[3];
	int playerRanking[3];
	char spinAgain;
	char playerReady;
	char playAgain = 'y';
	int scoreInput = 0;
	int bustCounter = 0;

	while(playAgain == 'y')
	{
		// Main game loop
		bustCounter = 0;
		for (int i = 0; i < 3; i++)
		{
			spinAgain = 'y';
			while(spinAgain == 'y')
			{
				cout << "Enter Player " << i+1 << " score for spin " << players[i].numSpins()+1 << ": ";
				cin >> scoreInput;

				players[i].addSpin(scoreInput);

				if (players[i].totalPoints() > 100)
				{
					cout << "Oh no! You've busted... your total score is over 100.  Better luck next time." << endl << endl;
					bustCounter++;
					break;
				}

				if (players[i].numSpins() < 2 && bustCounter < 2)
				{
					cout << "Would you like to spin again? (y/n):  ";
					cin >> spinAgain;
				}
				else
					spinAgain = 'n';
			}

/* 
 * Game logic pertaining to player spinning and receiving scores
 *
			spinAgain = 'y';
			playerReady = 'n';
			
			while(playerReady != 'y')
			{
				cout << "Player " << i+1 << " are you ready to spin? (y/n):  " ;
				cin >> playerReady;
			}

			while(spinAgain == 'y')
			{

				players[i].spin(myWheel);
				players[i].printScore();

				if (players[i].totalPoints() > 100)
				{
					cout << "Oh no! You've busted... your total score is over 100.  Better luck next time." << endl << endl;
					bustCounter++;
					break;
				}

				if (players[i].numSpins() < 2 && bustCounter < 2)
				{
					cout << "Would you like to spin again? (y/n):  ";
					cin >> spinAgain;
				}
				else
					spinAgain = 'n';

				cout << endl;
			}
*/
		}

		cout << "****************************" << endl;
		cout << "*       Final Scores       *" << endl;
		cout << "****************************" << endl;

		for (int i = 0; i < 3; i++)
		{
			if (players[i].totalPoints() <= 100)
				cout << "Player " << i+1 << " final score: " << players[i].totalPoints() << endl;
			else
				cout << "Player " << i+1 << " final score: " << players[i].totalPoints() << "  **(Busted)** " << endl;
		}
		
		cout << endl;

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
		int highestWithoutBust;
		for (int i = 0; i < 3; i++)
			if (players[playerRanking[i]].totalPoints() <= 100)
			{
				highestWithoutBust = i;
				break;
			}

		// Determine if there are any ties
		bool twoTieFlag = false;
		bool threeTieFlag = false;
		switch(highestWithoutBust)
		{
			case 0:
				if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[2]].totalPoints())
					threeTieFlag = true;
				else if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[1]].totalPoints())
					twoTieFlag = true;
				break;
			case 1:
				if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[2]].totalPoints())
					twoTieFlag = true;
				break;
		}
		
		cout << endl;

		// Display correct message for whether there were any ties, or if there was a winner
		if (threeTieFlag)
			cout << "All three players tied with a score of " << players[0].totalPoints();
		else if (twoTieFlag)
			cout << "Players " 
				<< playerRanking[highestWithoutBust]+1 
				<< " and " 
				<< playerRanking[highestWithoutBust+1]+1 
				<< " tied with a score of " 
				<< players[playerRanking[highestWithoutBust]].totalPoints();
		else
			cout << "Player "
				<< playerRanking[highestWithoutBust]+1
				<< " had the highest score of "
				<< players[playerRanking[highestWithoutBust]].totalPoints()
				<< " and is the WINNER!";
				
		cout << endl;
		cout << endl;
		cout << "****************************" << endl;
		cout << "*         GAME OVER        *" << endl;
		cout << "****************************" << endl;
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
