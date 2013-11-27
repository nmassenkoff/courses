// =====================================================================================
// 
//       Filename:  JobManager.cpp
// 
//    Description:  This class maintains a priority queue of jobs
// 
//        Version:  1.0
//        Created:  11/20/2013 11:07:15
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

JobManager::JobManager()
{
}

void JobManager::remove (QueueItemType& jobNumber) throw(RemoveFromEmptyQueueException)
{
	if (isEmpty())
		// Can't remove job if queue is empty, throw exception
		throw RemoveFromEmptyQueueException("Remove item from empty queue");
	else
	{
		// Find the highest non empty priorty queue and dequeue the next item
		int highest_priority;
		for (highest_priority = 9; highest_priority >= 0; highest_priority--)
			if (!myJobs[highest_priority].isEmpty())
				break;

		myJobs[highest_priority].dequeue(jobNumber);
	}
}

void JobManager::add (QueueItemType& jobNumber, int priority)
{
	// add job number to the corresponding priority index of myJobs queue
	myJobs[priority].enqueue(jobNumber);
}

void JobManager::display()
{
	if (isEmpty())
		cout << "The priority queue is empty" << endl;
	else
	{
		cout << "Jobs in order of priority: " << endl << endl;
		cout << "Job Number\tPriority" << endl;

		int priority;
		int queuePos;
		int queueSize;
		QueueItemType currJob;

		// Loop through each priority index, starting with the highest
		// if that priority queue is not empty, iterate through each
		// item in the queue and retrieve the job number and display it 
		// to the user
		for (priority = 9; priority >= 0; priority--)
			if (!myJobs[priority].isEmpty())
			{
				queueSize = myJobs[priority].getSize();
				for (queuePos = 1; queuePos <= queueSize; queuePos++)
				{
					myJobs[priority].retrieve(queuePos, currJob);
					cout << currJob << "\t\t" << priority << endl;
				}

			}
		cout << endl;
	}
}

bool JobManager::isEmpty()
{
	bool emptySoFar = true;

	// Iterate through each priority queue index and check if empty
	// If find one that is not empty, set emptySoFar to false and break
	// out of loop
	for (int priority = 9; priority >= 0; priority--)
		if(!myJobs[priority].isEmpty())
		{
			emptySoFar = false;
			break;
		}

	return emptySoFar;
}
