// =====================================================================================
// 
//       Filename:  Player.cpp
// 
//    Description:  Implementation for Player class
// 
//        Version:  1.0
//        Created:  10/02/2013 19:03:07
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{

}

void Player::spin(Wheel& myWheel)
{
	myWheel.spin();
	spins.push(myWheel.getNumber());
}

int Player::totalPoints() const
{
	int total = 0;
	int num = spins.getLength();
	ListItemType value;
	for (int i = 1; i <= num; i++)
	{
		spins.retrieve(i, value);
		total += value;
	}

	return total;
}

int Player::numSpins() const
{
	return spins.getLength();
}

void Player::reset()
{
	spins.clear();
}

void Player::addSpin(int score)
{
	spins.push(score);
}

void Player::printScore()
{
	int total = 0;
	int num = spins.getLength();
	ListItemType value;
	for (int i = 1; i <= num; i++)
	{
		spins.retrieve(i, value);
		cout << "For spin number " << i << " you landed on: " << value << endl;
	}

	cout << "Your total score is: " << totalPoints() << endl;
}
