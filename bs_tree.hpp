/*
* bs_tree.hpp
* Modified : 05/10/2023
*
* This class represents a templated binary search tree.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

//This method is the constructor for the binary tree, it contains the root node and node count
template <typename T>
BSTree<T>::BSTree()
{
    root = new BTNode<T>();
    //count is set to zero as tree has no children upon creation
    count = 0;
}

//This method is the destructor for the binary tree, it contains the clear method
template <typename T>
BSTree<T>::~BSTree()
{
    //clear(root) systemically destroyes all nodes within the binary tree until nothing is left
    clear(root);
}

//This method inserts an item into the binary tree
template <typename T>
void BSTree<T>::insert(const T& data)
{
    //uses private helper function to recursively add items to binary tree
    root = insert(data, root);
}

//This method removes an item from the binary tree
//Using a key to search for the item within the binary tree
template <typename T>
void BSTree<T>::remove(const std::string& key)
{
    //uses private helper function to recursively remove items from binary tree
    root = remove(key, root);
}

//This method checks if an item exists within the binary tree
template <typename T>
bool BSTree<T>::contains(const std::string& key) const
{
    //uses private helper function to search entire binary tree
    return contains(key, root);
}

//This method returns pointer to an item corressponding to inputted key
template <typename T>
T* BSTree<T>::find(const std::string& key) const
{
    //uses private helper function to search entire binary tree
    return find(key, root);
}

//This method returns item with lowest value in tree
template <typename T>
T& BSTree<T>::find_min() const
{
   //checks if tree is empty or root is empty
   if(empty() || !root)
    {
        throw empty_collection_exception();
    }
    //uses private helper function recursively call itself
    return find_min(root)->get_data();
}

//This method returns item with highest value in tree
template <typename T>
T& BSTree<T>::find_max() const
{
    //checks if tree is empty or root is empty
    if(empty() || !root)
    {
        throw empty_collection_exception();
    }
    //uses private helper function recursively call itself
    return find_max(root)->get_data();
}

//This method checks true or false if binary tree is empty
template <typename T>
bool BSTree<T>::empty() const
{
    //returns true if there are 0 items in tree
    if(count == 0)
    {
        return true;
    }
    //returns false if item count isn't 0
    else
    {
        return false;
    }
}

//This method returns the number of items in tree
template <typename T>
int BSTree<T>::size() const
{
    //returns count variable
    return count;
}

//This method prints binary tree using inorder steps
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out) const
{
    //method recursively calls itself taking out and root
    print_inorder(out, root);
}

//This method prints binary tree using preorder steps
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out) const
{
    //method recursively calls itself taking out and root
    print_preorder(out, root);
}

//This method prints binary tree using postorder steps
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out) const
{
    //method recursively calls itself taking out and root
    print_postorder(out, root);
}

//This method clears binary tree completely, removing all nodes in tree
template <typename T>
void BSTree<T>::clear(BTNode<T>* root)
{
    //This method repeats recursively until the root returns a nullptr
    if (root != nullptr)
    {
        //recursively calls the left and right children, 
        //calling the method on its children deleting down the binary tree
        clear(root->get_left());
        clear(root->get_right());
        //deletes root freeing its memory
        delete root;
    }
    //returns item count to 0
    count = 0;
}

//This method is the private helper function for the insert method
template <typename T>
BTNode<T>* BSTree<T>::insert(const T& data, BTNode<T>* node)
{
    //If no node through recursive call create new
    if(!node)
    {
        //adds to item count
        count++;
        //returns a new node, ending recursive depth and returning out of method through program
        return new BTNode<T>(data);
    }
    //implements recursive call to go further down binary tree
    if(data < node->get_data())
    {
        node->set_left(insert(data, node->get_left()));
    }
    //implements recursive call to go further down binary tree
    else if(data > node->get_data())
    {
        node->set_right(insert(data, node->get_right()));
    }
    //recursive call up of node, returns node back up through program through recursive layers
    return node;
}

//This method is the private helper function for the remove method
template <typename T>
BTNode<T>* BSTree<T>::remove(const std::string& key, BTNode<T>* node)
{
    //If there is no node, recursive depth ends returning up with a nullptr
    if(!node)
    {
        return nullptr;
    }
    //handles if key is less than current node's data
    else if(key < node->get_data())
    {
        //implements recursive call to go further down binary tree
        return remove(key, node->get_left());
    }
    //handles if key is greater than current node's data
    else if(key > node->get_data())
    {
        //implements recursive call to go further down binary tree
        return remove(key, node->get_right());
    }
    //handles if key is equal to current node's data
    else if(node->get_data() == key)
    {
        //If the left child of the current node is nullptr it removes right child
        if(node->get_left() == nullptr)
        {
            BTNode<T>* rightTemp = node->get_right();
            count--;
            //delete current node, returns its value, and lowers count
            delete node;
            return rightTemp;
        }
        //If the right child of the current node is nullptr it removes left child
        else if(node->get_right() == nullptr)
        {
            BTNode<T>* leftTemp = node->get_left();
            count--;
            //delete current node, returns its value, and lowers count
            delete node;
            return leftTemp;
        }
        //If both node children are not null, find the min to replace it
        else
        {
            //sets the minimum to a temporary node
            BTNode<T>* temp = find_min(node->get_right());
            //sets data of current node to data of minimum node
            node->set_data(temp->get_data());
            //retrieves minimum data key and node then recursively calls remove function and sets right child
            node->set_right(remove(temp->get_data().get_key(), node->get_right()));
        }
    }
    //returns node recursively up method layers
    return node;
}

//This method is the private helper function for the contains method
template <typename T>
bool BSTree<T>::contains(const std::string& key, BTNode<T>* node) const
{
    //If there is no node, recursive depth ends returning false
    if(!node)
    {
        return false;
    }
    //handles if key is equal to current node's data
    if(node->get_data() == key)
    {
        //contains returns true ending recursion depth
        return true;
    }
    //handles if key is less than current node's data
    if(key < (node->get_data()))
    {
        //implements recursive call to go further down binary tree
        return contains(key, node->get_left());
    }
    //handles if key is greater than current node's data
   if(key > (node->get_data()))
    {
        //implements recursive call to go further down binary tree
        return contains(key, node->get_right());
    }
    //returns false recursively up method layers 
    return false;
}

//This method is the private helper function for the find method
template <typename T>
BTNode<T>* BSTree<T>::find(const std::string& key, BTNode<T>* node) const
{
    //If there is no node, recursive depth ends returning up with a nullptr
    if(!node)
    {
        return nullptr;
    }
    //If node data is equal to key return node up recursive depth
    if(node->get_data() == key)
    {
        return node;
    }
    //handles if key is less than current node's data
    if(key < node->get_data())
    {
        //implements recursive call to go further down binary tree
        return find(key, node->get_left());
    }
    //handles if key is greater than current node's data
    if(key > node->get_data())
    {
        //implements recursive call to go further down binary tree
        return find(key, node->get_right());
    }
    //returns nullptr recursively up method layers
    return nullptr;
}

//This method is the private helper function for the find_min
template <typename T>
BTNode<T>* BSTree<T>::find_min(BTNode<T>* node) const
{
    if(!node->get_left())
    {
        return node;
    }
    return find_min(node->get_left());
}

///This method is the private helper function for the
template <typename T>
BTNode<T>* BSTree<T>::find_max(BTNode<T>* node) const
{
    //Loop checks if item is the highest value in tree
    if(!node->get_right())
    {
        //returns node if it is highest, returning up recursive depth
        return node;
    }
    //Goes through another recursive layer if current node is not most right
    return find_max(node->get_right());
}

//This method is the private helper function for the print_inorder method
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out, BTNode<T>* node) const
{
    //loop checks if node exists before printing
    if(node)
    {
        //prints inorder through list:
        //1. print left children
        print_inorder(out, node->get_left());
        //2. print node data
        out << node->get_data() << " ";
        //3. print right children
        print_inorder(out, node->get_right());
    }
}

//This method is the private helper function for the print_preorder
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out, BTNode<T>* node) const
{
    //loop checks if node exists before printing
    if(node)
    {
        //prints inorder through list:
        //1. print node data
        out << node->get_data() << " ";
        //2. print left children
        print_preorder(out, node->get_left());
        //3. print right children
        print_preorder(out, node->get_right());
    }
}

//This method is the private helper function for the print_postorder
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out, BTNode<T>* node) const
{
    if(node)
    {
        //prints inorder through list:
        //1. print left children
        print_preorder(out, node->get_left());
        //2. print right children
        print_preorder(out, node->get_right());
        //3. print node data
        out << node->get_data() << " ";
    }
}

//This method is operator overloader printing binary tree in inorder traversal
template <typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
    //If tree is not empty print_inorder
    if(!tree.empty())
    {
        tree.print_inorder(out);
    }
    //If tree is empty print this information
    else
    {
        out << "Binary Tree empty";
    }
    //returns the string inputted into out
    return out;
}