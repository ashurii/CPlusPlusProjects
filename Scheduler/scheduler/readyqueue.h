#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "dnode3.h"
#include <cstdlib>
#include <iostream>

//	The readyqueue class contains functions for scheduling processes to a priority queue
//	and removing the first process in the list as it is executed by the CPU

namespace Altman_1
{
	class readyqueue
	{
	public:
		typedef std::size_t size_type;
        typedef int value_type;
		readyqueue()
		{
			front = NULL;
			priority = 0;
		}
		~readyqueue( )
		{
			list_clear(front);
		}
		//MEMBER FUNCTIONS
		void enqueue( );
		int dequeue( );
		int peek_front( ) const { return front->data( );}
		int size( ) const { return list_length(front);}
		Altman_1::node<int>* get_front( ){ return front;}
	private: 
		Altman_1::node<int> *front;
		int priority;
	};
	}


#endif // SCHEDULER_H
