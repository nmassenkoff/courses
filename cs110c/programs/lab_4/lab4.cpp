// =====================================================================================
// 
//       Filename:  lab4.cpp
// 
//    Description:  Main program loop
// 
//        Version:  1.0
//        Created:  11/20/2013 00:54:39
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Queue.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	Queue myQueue;

	myQueue.enqueue(4);
	myQueue.enqueue(2);
	myQueue.enqueue(0);

	int item;

	myQueue.dequeue(item);
	cout << item << endl;
	cout << "Size: " << myQueue.getSize() << endl;
	myQueue.dequeue(item);
	cout << item << endl;
	cout << "Size: " << myQueue.getSize() << endl;
	myQueue.dequeue(item);
	cout << item << endl;

	cout << "Size: " << myQueue.getSize() << endl;

	return 0;
}
