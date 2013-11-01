#include <iostream>
#include <cstdlib>

// This program asks the user for the size of their sky and the number of 
// stars to be displayed in the sky.

using namespace std;

int main()
{
	// seeding random generator
	unsigned seed = time(0);
	srand(seed);

	// to hold user input
	int rows;
	int cols;
	int num_stars;

	// prompt user for input
	cout << "Enter the number of rows for your sky: ";
	cin >> rows;

	cout << "Enter the number of columns for your sky: ";
	cin >> cols;

	cout << "Enter the number of stars you want in your sky: ";
	cin >> num_stars;

	bool sky[rows][cols]; // open 2d array for sky
	bool star = true; // set star value to be true
	int rand_row; // to hold generated random number for rows
	int rand_col; // to hold generated random number for columns
	int r, c; // loop counters

	// fill the sky with user's input for rows and columns
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
			sky[r][c] = !star; // sky is filled with non-star objects
	}

	// search two dimensional array for open cell
	// if cell is not full, enter a star in that cell
	// else search for next empty cell
	// continue until we reach user's input for num_stars
	int i = 0; // loop counter
	int count = 0; // count number of stars in the sky
	while(i < num_stars)
	{
		rand_row = rand() % (rows);
		rand_col = rand() % (cols);
		if(sky[rand_row][rand_col] == !star)
		{
			sky[rand_row][rand_col] = star; // fill cell with star object
			i++;
			count++;;
		}
	}

	// display sky
	count = 0;
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
		{
			if(sky[r][c] == star)
			{
				count++;
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "We've counted " << count << " stars in the sky.\n";

	return 0;
}
