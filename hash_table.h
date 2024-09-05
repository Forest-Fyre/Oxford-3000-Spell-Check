/*
* hash_table.h
* Modified : 05/10/2023
*
* This class represents a templated hash table that uses a binary search tree for chaining.
* It is assumed that data items contain the method get_key, which returns a string.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_HASH_TABLE_H
#define SENG1120_HASH_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include "bs_tree.h"

template <typename T>
class HashTable
{
public:
    /*
    * Initialise a hash table with the specified capacity.
    *
    * Precondition:    None
    * Postcondition:   A new HashTable is created, with variables initialised as appropriate.
    */
    HashTable(int table_capacity = 101);

	/*
    * Precondition:    None
    * Postcondition:   The HashTable is destroyed and all associated memory is freed. Pointers should be set to nullptr.
    */
    ~HashTable();

    /*
    * The supplied data is inserted into the hash table.
    * 
    * Precondition:    The supplied data is valid.
    * Postcondition:   The data is inserted into the correct cell in the hash table. The count is increased by 1.
    */
    void insert(const T& data);

    /*
    * Remove the item with the specified key from the hash table, if it exists. 
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The item with the specified key has been removed, if it exists. The count is reduced by 1 if an item is removed.
    */
    void remove(const std::string& key);

    /*
    * Return a pointer to the item with the specified key, if it exists. If no such item exists, nullptr is returned.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified. 
    */
    T* get(const std::string& key) const;

    /*
    * Determine if an item with the specified key exists.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */
    bool contains(const std::string& key) const;

    /*
    * Clears all items from the hash table.
    *
    * Precondition:    None
    * Postcondition:   All cells in the hash table are emptied and any associated memory is reclaimed. Pointers are set to nullptr.
    */
    void clear();

    /*
    * Return true if the hash table is empty, false otherwise.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */  
    bool empty() const;

    /*
    * Return the number of items in the hash table.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */  
    int size() const;

    /*
    * Append the value of each cell in the hash table, to the supplied stream. 
    * As each cell is a binary search tree, the tree should be printed using the tree's
    * stream insertion operator.
    * 
    * Each cell should be printed on its own line, as "index: <tree>".
    * 
    * Precondition:    The hash table and supplied ostream have been initialised.
    * Postcondition:   The hash table has not been modified and has been appended to the stream.
    */ 
    std::ostream& print(std::ostream& os) const;

private:
    std::vector<BSTree<T>> table;  // The vector of BSTs, representing the cells. 
    int capacity;                  // The number of cells in the hash table.
    int count;                     // The number of elements in the hash table.

    /*
    * Compute the hash function for the supplied string. This should use std::hash<std::string> 
    * and return a valid index within the hash table. See the assignment spec for the implementation.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */ 
    int hash_function(const std::string& key) const;
};

/*
* Append the value of each cell in the hash table, to the supplied stream. 
* Each cell should be printed on its own line, as "index: <tree>".
* 
* Precondition:    The hash table and supplied ostream have been initialised.
* Postcondition:   The hash table has not been modified and has been appended to the stream.
*/ 
template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table);

#include "hash_table.hpp"
#endif