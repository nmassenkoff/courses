#include "Player.h"
#include <iostream>

using namespace std;


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  Main program function for actualy game show.
//  		  
//  		  Instantiates  a game wheel and 3 players, and then initiates the game
//  		  logic. Each player is allowed to spin up to 2 times a wheel that 
//  		  contains 20 numbers starting with 5 and incrementing by 5, ending with 
//  		  100.  The order of these numbers are completely randomized at the 
//  		  begining the program.
//
//  		  If any player upon spinning a second time has a total number of points
//  		  over 100, that player has "busted" and is disqualified from winning.
//
//  		  If players 1 and 2 both bust, then player 3 is only allowed one spin,
//  		  after which he/she becomes the automatic winner.
//
//  		  Once all 3 players are done with their spins, the game logic determines
//  		  who had the highest without going over 100, and whether or not there
//  		  were any ties.
//
// =====================================================================================
int main(int argc, const char *argv[])
{
	// Instantiate game wheel and 3 players
	Wheel myWheel;
	Player players[3];

	// playerRanking[] is an array of indexes corresponding to players
	// in players[] and is used to order the players from highest score
	// to lowest score (i.e. player index at index 0 of playerRankings[]
	// is the highest score)
	int playerRanking[3];

	// Variables to control flow
	char spinAgain;
	char playerReady;
	char playAgain = 'y';

	// Counter to indicate how many players have busted
	int bustCounter;

	while(playAgain == 'y')
	{
		// Main game loop

		bustCounter = 0;
		for (int i = 0; i < 3; i++)
		{
			// Each iteration of for loop executes
			// spinning for each player in players[]
			
			spinAgain = 'y';
			playerReady = 'n';
			
			while(playerReady != 'y')
			{
				// Wait to spin until current player is ready
				cout << "Player " << i+1 << " are you ready to spin? (y/n):  " ;
				cin >> playerReady;
			}

			while(spinAgain == 'y')
			{

				// have player spin the wheel
				// and display the resulting score
				players[i].spin(myWheel);
				players[i].printScore();

				if (players[i].totalPoints() > 100)
				{
					// Player has busted
					cout << "Oh no! You've busted... your total score is over 100.  Better luck next time." << endl << endl;
					bustCounter++;
					break;
				}

				if (players[i].numSpins() < 2 && bustCounter < 2)
				{
					// See if player would like to spin again
					cout << "Would you like to spin again? (y/n):  ";
					cin >> spinAgain;
				}
				else
					spinAgain = 'n';

				cout << endl;
			}
		}

		cout << "****************************" << endl;
		cout << "*       Final Scores       *" << endl;
		cout << "****************************" << endl;

		for (int i = 0; i < 3; i++)
		{
			// Print final scores for each player (noting if they have busted)
			if (players[i].totalPoints() <= 100)
				cout << "Player " << i+1 << " final score: " << players[i].totalPoints() << endl;
			else
				cout << "Player " << i+1 << " final score: " << players[i].totalPoints() << "  **(Busted)** " << endl;
		}
		
		cout << endl;

		// Initialize rankings array
		for (int i = 0; i < 3; i++)
			playerRanking[i] = i;

		// Temporay int placehold for swapping elements in playerRanking[]
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
				// No players have busted, so check for both 3-way and 2-way ties
				if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[2]].totalPoints())
					// If highest score == lowest score, all three scores are equal becaues playerRanking[] is orderd 
					// from highest score to lowest score;
					threeTieFlag = true;
				else if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[1]].totalPoints())
					twoTieFlag = true;
				break;
			case 1:
				// One player has busted so check only for 2-way tie
				if (players[playerRanking[highestWithoutBust]].totalPoints() == players[playerRanking[2]].totalPoints())
					twoTieFlag = true;
				break;
			// If 2 players busted than no ties are possible
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
		cout << endl;

		// if playAgain reset each player
		if (playAgain == 'y')
			for (int i=0; i < 3; i++)
				players[i].reset();
	}
	return 0;
}
