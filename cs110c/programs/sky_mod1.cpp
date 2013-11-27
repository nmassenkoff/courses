#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

using namespace std;

const int NUM_STARS = 100;

const int MIN_X = 0;
const int MAX_X = 20;

const int MIN_Y = 0;
const int MAX_Y = 80;

int main(int argc, const char *argv[])
{
	// seed random number generator
	srand((unsigned)time(NULL));

	// A multidimensional char array to represent the screen
	char screen[MAX_X][MAX_Y];

	// Fill screen
	for(int x = MIN_X; x < MAX_X; x++)
	{
		for(int y = MIN_Y; y < MAX_Y; y++)
			screen[x][y] = ' ';
	}

	// Variables for normal distrbution calculation
	double u1, u2, z1_dbl, z2_dbl;

	// Variables for uniform distribution calculation
	int z1_int, z2_int, x_uni, y_uni;

	for(int i = 0; i < NUM_STARS; i++)
	{
		/* This is for uniform distribution
		x_uni = rand() % ((MAX_X + 1) - MIN_X) + MIN_X;
		y_uni = rand() % ((MAX_Y + 1) - MIN_Y) + MIN_Y;

		if(screen[x_uni][y_uni] == '*')
		{
			// Star already exists so re-calculate star
			i--;
			continue;
		}
		else
			screen[x_uni][y_uni] = '*';
 */
		u1 = ((double) rand() / (RAND_MAX));
		u2 = ((double) rand() / (RAND_MAX));

		// Formulas for normal distribution
		z1_dbl = (sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2) + 3.0) * 13.0; // x-coord
		z2_dbl = (sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2) + 2.3) * 4.5; // y-coord
        
	        if((MIN_X <= z1_dbl) && (z1_dbl < MAX_X) && (MIN_Y <= z2_dbl) && (z2_dbl < MAX_Y))
		{
			z1_int = z1_dbl; // x-coord
			z2_int = z2_dbl; // y-coord
            
			if(screen[z1_int][z2_int] == '*')
			{
				// Star already exists so re-calculate star
				i--;
				continue;
			}
			else
				screen[z1_int][z2_int] = '*';
		}
		else
		{
			// One of the coordinates is invalid so re-calculate star
			i--;
			continue;
		}

	}

	// Display screen
	for(int x = MIN_X; x < MAX_X; x++)
	{
		for(int y = MIN_Y; y < MAX_Y; y++)
			cout << screen[x][y];
		cout << endl;
	}

	return 0;
}
