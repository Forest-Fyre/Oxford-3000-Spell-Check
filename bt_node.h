/*
* bt_node.h
* Modified : 05/10/2023
*
* This class represents a templated binary tree node.
*/

#ifndef SENG1120_BTNODE_H
#define SENG1120_BTNODE_H

#include <iostream>

template <typename T>
class BTNode
{
public:
	/*
    * Precondition:    None
    * Postcondition:   A new BTNode is created with default data, left and right are initialised as appropriate.
    */
    BTNode();

	/*
    * Precondition:    None
    * Postcondition:   A new BTNode is created with the supplied data, left and right are initialised as appropriate.
    */
    BTNode(const T& new_data);

	/*
    * Precondition:    None
    * Postcondition:   The BTNode is destroyed and all associated memory is freed.
    */
    ~BTNode();

    /*
    * Precondition:    None
    * Postcondition:   The data variable has been set to the supplied value.
    */
    void set_data(const T& new_data);

    /*
    * Precondition:    The supplied BTNode is valid.
    * Postcondition:   The left child has been set to the supplied node.
    */
    void set_left(BTNode<T>* new_left);

    /*
    * Precondition:    The supplied BTNode is valid.
    * Postcondition:   The right child has been set to the supplied node.
    */
    void set_right(BTNode<T>* new_right);

    /*
    * Precondition:    The data item has been initialised.
    * Postcondition:   A reference to the data item is returned.
    */
    T& get_data();

    /*
    * Precondition:    The left child has been initialised.
    * Postcondition:   The value of the left child is returned.
    */
    BTNode<T>* get_left() const;

    /*
    * Precondition:    The right child has been initialised.
    * Postcondition:   The value of the right child is returned.
    */
    BTNode<T>* get_right() const;
private:
    T data;                   // Data stored in the BTNode
    BTNode<T>* left;          // The pointer to the left child
    BTNode<T>* right;         // The pointer to the right child
};

/*
* The value of the data variable is appended to the stream, without any spaces.
*
* Precondition:    The supplied BTNode and ostream are valid.
* Postcondition:   The stream is updated with the data value appended.
*/
template <typename T>
std::ostream& operator<<(std::ostream& out, const BTNode<T>& node);

#include "bt_node.hpp"

#endif