

#ifndef ALTMAN_1_NODE_3_H 
#define ALTMAN_1_NODE_3_H
#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag

namespace Altman_1
{
    template <class Item>
    class node
    {
    public:
        // TYPEDEF
        typedef Item value_type;
        // CONSTRUCTOR
        node(const Item& init_data=Item( ), node* init_link_fore=NULL, node* init_link_back=NULL)
            { data_field = init_data; link_fore = init_link_fore; link_back = init_link_back;}
        // MODIFICATION MEMBER FUNCTIONS
        Item& data( ) { return data_field; }
        node* get_link_fore( ) { return link_fore; }
		node* get_link_back( ) { return link_back; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_link_fore(node* new_link) { link_fore = new_link; }
		void set_link_back(node* new_link) { link_back = new_link; }
        // CONST MEMBER FUNCTIONS
        const Item& data( ) const { return data_field; }
        const node* get_link_fore( ) const { return link_fore; }
		const node* get_link_back( ) const { return link_back; }
    private:
        Item data_field;
        node *link_fore;
		node *link_back;
		
    };

    // FUNCTIONS to manipulate a linked list:
    template <class Item>
    void list_clear(node<Item>*& head_ptr);

    template <class Item>
    void list_copy
        (const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);

    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry); 

    template <class Item>
    void list_head_remove(node<Item>*& head_ptr);

    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry);
 
    template <class Item>
	std::size_t list_length(const node<Item>* head_ptr);

    template <class NodePtr, class SizeType>
    NodePtr list_locate(NodePtr head_ptr, SizeType position);

    template <class Item>
    void list_remove(node<Item>* previous_ptr);
   
    template <class NodePtr, class Item>
    NodePtr list_search(NodePtr head_ptr, const Item& target);

    // FORWARD ITERATORS to step through the nodes of a linked list
    // A node_iterator of can change the underlying linked list through the
    // * operator, so it may not be used with a const node. The
    // node_const_iterator cannot change the underlying linked list
    // through the * operator, so it may be used with a const node.
    // WARNING:
    // This classes use std::iterator as its base class;
    // Older compilers that do not support the std::iterator class can
    // delete everything after the word iterator in the second line:


    template <class Item>
    class node_iterator
    : public std::iterator<std::forward_iterator_tag, Item>
    {
    public:
    	node_iterator(node<Item>* initial = NULL)
	    { current = initial; }
	Item& operator *( ) const
	    { return current->data( ); }
	node_iterator& operator ++( ) // Prefix ++
	    { 
		current = current->link( );
		return *this;
	    }
	node_iterator operator ++(int) // Postfix ++
	    {
		node_iterator original(current);
		current = current->link( );
		return original;      	  
	    }
	bool operator ==(const node_iterator other) const
	    { return current == other.current; }
	bool operator !=(const node_iterator other) const
	    { return current != other.current; }
    private:
	node<Item>* current;
    };

    template <class Item>
    class const_node_iterator
    : public std::iterator<std::forward_iterator_tag, const Item>
    {
    public:
    	const_node_iterator(const node<Item>* initial = NULL)
	    { current = initial; }
	const Item& operator *( ) const
	    { return current->data( ); }
	const_node_iterator& operator --( ) // Prefix ++
	    {
		current = current->get_link_back( );
		return *this;
	    }
	const_node_iterator operator ++(int) // Postfix ++
	    {
		const_node_iterator original(current);
		current = current->link( );
		return original;
	    }
	bool operator ==(const const_node_iterator other) const
	    { return current == other.current; }
	bool operator !=(const const_node_iterator other) const
	    { return current != other.current; }
    private:
	const node<Item>* current;
    };

}

#include "dnode3.template"
#endif
