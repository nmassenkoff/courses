// =====================================================================================
// 
//       Filename:  main.cpp
// 
//    Description:  Main loop for lab 4
// 
//        Version:  1.0
//        Created:  11/20/2013 12:01:33
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================


#include "JobManager.h"
#include <iostream>

using namespace std;

typedef int QueueItemType;

void printOptions()
{
	// Function to display the options to theh user
	// pre: none
	// post: none
	cout << "R -- Remove" << endl;
	cout << "A -- Add" << endl;
	cout << "L -- List" << endl;
	cout << "Q -- Quit" << endl;

	cout << endl;
	cout << "Enter your choice (R, A, L, Q): ";
}

int main(int argc, const char *argv[])
{
	// User input stored in this variable
	char userChoice;

	// User input priority stored in this variable
	int priority = 0;

	// Queue items to input and retreive queue items
	QueueItemType nextJob;
	QueueItemType newJob;

	// Job manager to control priority queue
	JobManager jobs;

	cout << endl << "Job Priority Queue:" << endl << endl;

	while(userChoice != 'Q')
	{
		// Main program loop

		printOptions();
		cin >> userChoice;

		switch (userChoice)
		{
			// Switch to process user input
			// if no match then just keep repeating loop
			case 'R':
				try
				{
					jobs.remove(nextJob);
					cout << "Job number " << nextJob << " removed from queue" << endl << endl;
				}
				catch(RemoveFromEmptyQueueException exception)
				{
					// Exception occured, the priorty queue is empty
					cout << "Unable to remove job from empty queue." << endl << endl;
				}
				break;
			case 'A':
				// Get job number from user
				cout << "Enter job number: ";
				cin >> newJob;

				// Get priority from user
				cout << "Enter priority: ";
				cin >> priority;
				cout << endl;

				jobs.add(newJob, priority);
				break;
			case 'L':
				jobs.display();
				cout << endl;
				break;
		}
	}
	cout << "Goodbye!" << endl;
	return 0;
}
