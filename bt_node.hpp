/*
* bt_node.hpp
* Modified : 05/10/2023
*
* This class represents the hpp implementation of the binary tree node.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

//This method acts as the default constructor for the binary tree node, forming the neccessary components of a node
template <typename T>
BTNode<T>::BTNode()
{
    //The constructor creating the data for the node through the T template
    data = T();
    //left & right variables represent the binary paths the node takes to its children
    //setting them as nullptr as they are created empty
    left = nullptr;
    right = nullptr;
}

//This method acts as an alternative constructor for the binary tree node, containg new_data parameter
template <typename T>
BTNode<T>::BTNode(const T& new_data)
{
    //The constructor creating the data for the node through the new_data parameter
    data = new_data;
    //left & right variables represent the binary paths the node takes to its children
    //setting them as nullptr as they are created empty
    left = nullptr;
    right = nullptr;
}

template <typename T>
BTNode<T>::~BTNode()
{
    //Destructor remains empty, all memory concerns are dealt with in bt_tree destructor
}

//This method sets node data to the new_data insertable parameter
template <typename T>
void BTNode<T>::set_data(const T& new_data)
{
    data = new_data;
}

//This method sets left node child to the left insertable parameter
template <typename T>
void BTNode<T>::set_left(BTNode<T>* new_left)
{
    left = new_left;
}

//This method sets right node child to the right insertable parameter
template <typename T>
void BTNode<T>::set_right(BTNode<T>* new_right)
{
    right = new_right;
}

//This method retrieves the data from the node
template <typename T>
T& BTNode<T>::get_data()
{
    return data;
}

//This method retrieves the data from the left child node

template <typename T>
BTNode<T>* BTNode<T>::get_left() const
{
    return left;
}

//This method retrieves the data from the right child node

template <typename T>
BTNode<T>* BTNode<T>::get_right() const
{
    return right;
}