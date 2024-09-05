/*
* bs_tree.h
* Modified : 05/10/2023
*
* This class represents a templated binary search tree.
*/

#ifndef SENG1120_BSTREE_H
#define SENG1120_BSTREE_H

#include "bt_node.h"
#include "empty_collection_exception.h"
#include <iostream>

template <typename T>
class BSTree
{
public:
    /*
    * Precondition:    None
    * Postcondition:   A new BSTree is created, with variables initialised as appropriate.
    */
    BSTree();

	/*
    * Precondition:    None
    * Postcondition:   The BSTree is destroyed and all associated memory is freed. Pointers should be set to nullptr.
    */
    ~BSTree();

    /*
    * The supplied data is inserted into the binary search tree.
    * 
    * Precondition:    The supplied data is valid.
    * Postcondition:   The data is inserted into the correct location in the tree. The count is increased by 1.
    */
    void insert(const T& data);

    /*
    * Remove the item with the specified key from the tree, if it exists. 
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The item with the specified key has been removed, if it exists. The count is reduced by 1 if an item is removed.
    */
    void remove(const std::string& key);

    /*
    * Determine if an item with the specified key exists.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */
    bool contains(const std::string& key) const;

    /*
    * Return a pointer to the item with the specified key, if it exists. If no such item exists, nullptr is returned.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified. 
    */
    T* find(const std::string& key) const;

    /*
    * Return a reference to the item with the minimum data value. If the tree is empty, an empty_collection_exception is thrown.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified. 
    */
    T& find_min() const;

    /*
    * Return a reference to the item with the maximal data value. If the tree is empty, an empty_collection_exception is thrown.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified. 
    */
    T& find_max() const;

    /*
    * Return true if the tree is emtpy, false otherwise.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */  
    bool empty() const;

    /*
    * Return the number of nodes in the tree.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */  
    int size() const;

    /*
    * Append the value of each node in the tree to the supplied stream using an inorder traversal. Each element should be separated by a space.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */ 
    void print_inorder(std::ostream& out) const;

    /*
    * Append the value of each node in the tree to the supplied stream using a preorder traversal. Each element should be separated by a space.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */ 
    void print_preorder(std::ostream& out) const;

    /*
    * Append the value of each node in the tree to the supplied stream using a postorder traversal. Each element should be separated by a space.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */ 
    void print_postorder(std::ostream& out) const;

private:
    BTNode<T>* root;    // The root of the binary search tree.
    int count;          // The number of nodes in the tree

    /*
    * Clears all nodes from the sub-tree rooted at the supplied node.
    *
    * Precondition:    None
    * Postcondition:   All nodes from the sub-tree are removed and any associated memory is reclaimed. Pointers are set to nullptr.
    */
    void clear(BTNode<T>* root);

    /*
    * The supplied data is inserted into the sub-tree rooted at the supplied node. A pointer to the node is returned.
    * 
    * Precondition:    The supplied data is valid.
    * Postcondition:   The data is inserted into the correct location in the tree. The count is increased by 1.
    */
    BTNode<T>* insert(const T& data, BTNode<T>* node);

    /*
    * Remove the item with the specified key from the sub-tree rooted at the supplied node, if it exists. A pointer to the node is returned.
    * 
    * Precondition:    None.
    * Postcondition:   The item with the specified key has been removed, if it exists. The count is reduced by 1 if an item is removed.
    */
    BTNode<T>* remove(const std::string& key, BTNode<T>* node);

    /*
    * Determine if an item with the specified key exists in the sub-tree rooted at the supplied node.
    * 
    * Precondition:    None.
    * Postcondition:   The tree has not been modified.
    */
    bool contains(const std::string& key, BTNode<T>* node) const;

    /*
    * Return a pointer to the node containing the item with the specified key, if it exists, in the sub-tree rooted at the supplied node. 
    * If no such item exists, nullptr is returned.
    * 
    * Precondition:    None.
    * Postcondition:   The tree has not been modified. 
    */
    BTNode<T>* find(const std::string& key, BTNode<T>* node) const;

    /*
    * Return a pointer to the node containing the item with the minimum data value in the sub-tree rooted at the supplied node. 
    * 
    * Precondition:    None.
    * Postcondition:   The tree has not been modified. 
    */
    BTNode<T>* find_min(BTNode<T>* node) const;

    /*
    * Return a pointer to the node containing the item with the maximum data value in the sub-tree rooted at the supplied node. 
    * 
    * Precondition:    None.
    * Postcondition:   The tree has not been modified. 
    */
    BTNode<T>* find_max(BTNode<T>* node) const;

    /*
    * Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream, using an inorder traversal. 
    * Each element should be separated by a space.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */ 
    void print_inorder(std::ostream& out, BTNode<T>* node) const;

    /*
    * Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream, using a preorder traversal. 
    * Each element should be separated by a space.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */ 
    void print_preorder(std::ostream& out, BTNode<T>* node) const;

    /*
    * Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream, using a postorder traversal. 
    * Each element should be separated by a space.
    * 
    * Precondition:    The tree has been initialised.
    * Postcondition:   The tree has not been modified.
    */ 
    void print_postorder(std::ostream& out, BTNode<T>* node) const;
};

/*
* Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream. 
* By default, the tree should be printed according to an inorder traversal.
* 
* Precondition:    The supplied BSTree and ostream are valid.
* Postcondition:   The stream is updated with the data values from the tree appended.
*/
template <typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree);

#include "bs_tree.hpp"
#endif
