// =====================================================================================
// 
//       Filename:  Player.h
// 
//    Description:  This Player class keeps track of spins and values spun 
// 
//        Version:  1.0
//        Created:  10/02/2013 17:19:11
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Wheel.h"

class Player
{
	public:
		Player();
		// Default Constructor
		// pre: none
		// post: Initiates a Player object with zero score and no spins
		
		void spin(Wheel& myWheel);
		// Spins the wheel myWheel and stores the resulting number
		// pre: a Wheel object
		// post: updates spin list
		
		int totalPoints() const;
		// Gets total points spun so far
		// pre: none
		// post: none
		// Return: total points
	
		int numSpins() const;
		// Returns number of spins by player
		// pre: none
		// post: none
		// returns: int >= 0 

		void printScore();
		// Prints out the number for each spin, as well as the total
		// pre: none
		// post: none

		void reset();
		// Resets player data in prepartion for new game
		// pre: none
		// post: none

		void addSpin(int score);
		// This function allows you to manually add spins to the player
		// pre: 0 < score <= 100, should be multiples of 5
		// post: Adds score to spins List as if resulting from a spin
	private:
		// A list containing the values spun by the player
		List spins;
};
