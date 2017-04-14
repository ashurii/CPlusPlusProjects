//TYPEDEFS
//	value_Type: The data of the items in the priority queue from the Item parameter
//	for this version of the priority queue, the Item must have a "less than" 
//	operator < defined, forming a strict weak ordering (see figure 3.12 on page 139).
//	size_type: The data type to keep track of how many items are in a priority queue.
//
//CONSTRUCTOR
//	Default constructor. Creates an empty priority queue.
//	
//VOID FUNCTIONS TO INSERT AND REMOVE ITEMS:
//	pop( ): Removes the highest priority item of the priority queue
//	push( const Item& entry): Adds an item to the priority queue.
//	
//FUNCTIONS TO EXAMINE THE QUEUE AND ITS ITEMS:
//	empty( ): 	Returns true of the queue is empty
//	size( ): 	Returns the number of items in the queue
//	top( ): 	Returns the highest priority item of the queue. If there is 
//				more than one with equal priorities, the implementation may decide which one to return.
//				
//VALUE SEMANTICS:
//	Assignments and the copy constructor may be used with priority_queue<Item> objects.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace Altman_1
{
class priority_queue
{
public:
	typedef int value_type;
	typedef std::size_t size_type;
	//CONSTRUCTOR
	priority_queue() { }
	
	//Insertion and removal
	value_type pop( );
	void push (const value_type priority);
	bool empty( ) { 
		if(heap.size( ) > 0)
			return false;
		else
			return true;}
	size_type size( ) { return heap.size( ); }
	size_type max_size( ) {return heap.max_size( );}
	value_type top( ) { return heap.front( ); }
	
	private:
	std::vector<int> heap;
	value_type left(value_type parent);
	value_type right(value_type parent);
	value_type parent(value_type child);
	void heapify(value_type entry);
};}

#endif // PRIORITY_QUEUE_H
