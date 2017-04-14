#include "priority_queue.h"
#include <iostream>

namespace Altman_1
{
	
	void priority_queue::push(const value_type priority)
	{
		//Postcondition: the process is added to the queue, maintaining heap structure based on priority
		
		heap.push_back(priority);							//The entry is added to the root of the heap
		heapify(heap.size( ) -1);							//Heap structure maintained
	}
	priority_queue::value_type priority_queue::pop( )
	{
		value_type pID = heap[0];
		heap.erase(heap.begin( ));
		heapify(heap.size( ) - 1);
		return pID;
	}
	void priority_queue::heapify(value_type entry)
	{
		if(entry >= 0 && parent(entry) >= 0 && heap[parent(entry)] > heap[entry])
		{
			value_type temp = heap[entry];
			heap[entry] = heap[parent(entry)];
			heap[parent(entry)] = temp;
			heapify(parent(entry));
		}
	}
	priority_queue::value_type priority_queue::parent(value_type child)
	{
		value_type p = (child - 1)/2;
		if(child == 0)
			return -1;
		else
			return p;
	}
	priority_queue::value_type priority_queue::left(value_type parent)
	{
		unsigned int l = 2*parent + 1;
		if( l < heap.size( ))
			return l;
		else
			return -1;
	}
	priority_queue::value_type priority_queue::right(value_type parent)
	{
		unsigned int r = 2*parent + 2;
		if( r < heap.size( ))
			return r;
		else
			return -1;
	}
}
