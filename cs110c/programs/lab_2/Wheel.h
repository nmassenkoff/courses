// =====================================================================================
// 
//       Filename:  Wheel.h
// 
//    Description:  Inherits from List.h, implements a circular list
//    		        that keeps track of current position of the list
//    		        as well as provides a method for spinning the wheel
//    		        and moving the current postion forward a random number
//    		        of times between  22 and 42.
//				    
//					Also initiates the wheel with 20 numbers from 5 to 100, incrementing
// 					by 5 and ordered randomly
// 
//        Version:  1.0
//        Created:  10/02/2013 12:30:44
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "List.h"

class Wheel : public List
{
	public:
		Wheel();
		// Default Constructor
		// Parrent constructor called first
		// pre: none
		// post: A randomly order list of 20 numbers
		// 	 whose values run from 5 to 100 (inclusive)
		//	 and increment by 5 (ie 5, 10, 15, ... 90, 95, 100)

		void spin();
		// Randomly advances the current position of the list between 22 and 42 positions
		// pre: none
		// post: current postion is updated to account for new postion

		ListItemType getNumber() const;
		// Retrieves the number at the current position of the wheel
		// pre: none
		// post: none
		// return: number at the current postion of the wheel

	private:
		// Current position of the wheel
		int currentPos;

		int randomInt(int min, int max);
		// Returns random number between min and max
		// pre: min > 0, max > min
		// post: none
		// return: random number between min and max

		void displaySpin(int targetPos) const;
		// Displays an animated wheel that starts from current pos and ends at targetPos
		// pre: 1 <= targetPos <= 20
		// post: none

		int translatePos(int linearPos) const;
		// Converts a linear pos to the actual position of the wheel 
		// which is circular
		// pre: linearPos > 0
		// post: none
		// return: current position of the wheel
};
