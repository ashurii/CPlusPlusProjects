#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "deque.h"

using namespace std;

using namespace main_savitch_8C;


void run( )
{
	deque<int> d1;
	int input = 0;
	cout << "Enter integers to fill a double ended queue. Enter -1 to finish." << endl;
	cin >> input;
	while(input != -1)
	{
		d1.push_rear(input);
		cin >> input;
	}
	cout << "Front of the deque:\t" << d1.get_front( ) << endl;
	cout << endl;
	cout << "Rear of the deque:\t" << d1.get_rear( ) << endl;
	
	d1.pop_front();
	cout << "after popping the front, the front is now:\t" << d1.get_front( ) << endl;
	d1.pop_rear();
	cout << "after popping the rear, the rear is now:\t" << d1.get_rear( ) << endl;
	
	d1.print( );
}
	
int main(int argc, char **argv)
{
	run( );
}
