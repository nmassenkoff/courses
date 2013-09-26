// =====================================================================================
// 
//       Filename:  lab_1.cpp
// 
//    Description:  Add commas to a number
// 
//        Version:  1.0
//        Created:  09/16/2013 12:22:59 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nicholas Massenkoff (M4551V3), nmassenkoff@gmail.com
// 
// =====================================================================================

#include <iostream>

using namespace std;


void showCommas ( const int &myNum )
{
	// Purpose:	Takes a positive integer and prints to the std output
	// 		the same number, but using a comma (',') to indicate
	// 		the thousands.
	//
	// Pre:		myNum is a postive integer ( myNum > 0 )
	//
	// Post:	myNum is unchanged, but myNum is written to std output with
	// 		commas added. (note: no newline character is printed following execution)
	int remainder
	if (myNum / 1000 == 0)
	{
		// Base condition reached, end recursive calls
		cout << myNum; 

	} else {
		// Make recursive call, problem size reduced by dividing myNum by 1000
		showCommas(myNum/1000);

		

		// Output the last 3 digits of myNum
		cout << ',' << myNum % 1000;
	}

} // -----  end of function showCommas  -----

int main(int argc, const char *argv[])
{
	// Main driver program to test
	// showCommas function
	
	showCommas(1);
	cout << endl;
	showCommas(12);
	cout << endl;
	showCommas(123);
	cout << endl;
	showCommas(1234);
	cout << endl;
	showCommas(23423);
	cout << endl;
	showCommas(982845);
	cout << endl;
	showCommas(7282485);
	cout << endl;
	showCommas(1001000);
	cout << endl;
	showCommas(1000000);
	cout << endl;
	return 0;
}
