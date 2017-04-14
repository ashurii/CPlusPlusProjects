
#ifndef MAIN_SAVITCH_DEQUE_H     // Prevent duplicate definition
#define MAIN_SAVITCH_DEQUE_H
#include <cstdlib>   // Provides std::size_t
#include "dnode2.h"   // Node template class

namespace main_savitch_8C
{
    template <class Item>
    class deque
    {
    public:
        // TYPEDEFS 
        typedef std::size_t size_type;
        typedef Item value_type;
		
        // CONSTRUCTORS and DESTRUCTOR
	deque( );
	deque(const deque<Item>& source);
	~deque( );
        // MODIFICATION MEMBER FUNCTIONS
	void pop_front( );
	void pop_rear( );
	void push_front(const Item& entry);
	void push_rear(const Item& entry);
	void operator =(const deque<Item>& source);
        // CONSTANT MEMBER FUNCTIONS
	void print( );
	bool empty( ) const { return (count == 0); }
	bool full( ) const { return (size( ) == capacity);}
	Item get_front( ) const;
	Item get_rear( ) const;
	size_type size( ) const { return count; }
	main_savitch_6B::node<Item> get_front_ptr( ) const {return front_ptr;}
	main_savitch_6B::node<Item> get_rear_ptr( ) const {return rear_ptr;}
    private:
		size_type capacity; 
        main_savitch_6B::node<Item> *front_ptr;
        main_savitch_6B::node<Item> *rear_ptr; 
        size_type count;       // Total number of items in the deque
    };
}
#include "deque.template" // Include the implementation
     
#endif
