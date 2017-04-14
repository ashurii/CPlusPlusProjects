#include "readyqueue.h"
#include "dnode3.h"
#include <iostream>


namespace Altman_1
{
	void readyqueue::enqueue( )
	{
//		Postcondition: The process is placed in the queue
//		in order of priority (greatest value to smallest)
//		if the priority values are the same, it is placed in the queue
//		after the first process to enter the queue. The priority is a randomly generated number.

		priority = ((int)(rand( )) % 10000 +1);
		Altman_1::node<int> *cursor;	
		cursor = front;
		
		if(front == NULL || priority > front->data( ))
		{
			
			list_head_insert(front, priority);
			
		}
		else
		{
			while(cursor->get_link_fore( ) != NULL && cursor->get_link_fore()->data( ) <= priority)
				cursor = cursor->get_link_fore();
			list_insert(cursor, priority);
		}

	}
	int readyqueue::dequeue( )
	{
//		Remove the process at the front of the ready queue
		int pID;
		pID = front->data();
		list_head_remove(front);	
		return pID;
		
	}
	
}
