// =====================================================================================
// 
//       Filename:  JobManager.h
// 
//    Description:  This class maintains job queue with priority.
//    		    
//    		    New jobs are assigned a priority and then enqueued into the queue
//    		    that corresponds to that priority level.
// 
//        Version:  1.0
//        Created:  11/20/2013 10:46:52
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Queue.h"
#include <exception>
#include <string>

using namespace std;

typedef int QueueItemType;

class RemoveFromEmptyQueueException : public logic_error
{
	public:
		RemoveFromEmptyQueueException(const string & Message = ""):
			logic_error(Message.c_str())
		{ }
};

class JobManager
{
	public:
		JobManager();
		// Default constructor
		// Destructor supplied by compiler
		// pre: none
		// post: An empty priority queue
		
		void remove (QueueItemType& jobNumber) throw(RemoveFromEmptyQueueException);
		// Removes the next job in the highest priority queue
		// and sets it to jobNumber
		// Throws RemoveFromEmptyQueue exception if there are no jobs in the queue
		// pre: Queues for each priority level must not be empty
		// post: jobNumber is set to the next job number of the queue with highest priority
		// 	 The job is then removed from that priority queue

		void add (QueueItemType& jobNumber, int priority);
		// Adds jobNumber to the correspondiny priority queue
		// pre: jobNumber >= 0, 0 <= priority <= 9
		// post: jobNumber is enqueued at the corresponding priority queue

		void display ();
		// Displays a listing in order of priority
		// pre: non empty job queue
		// post: none

		bool isEmpty ();
		// Checks queue manager if empty of jobs or not
		// pre: none
		// post: none
		// returns: true if empty, false if not

	private:
		// An array of Queue objects
		// each index represents a new priority level
		// index 9 is highest priority
		// index 0 is lowest priority
		Queue myJobs[10];
};
