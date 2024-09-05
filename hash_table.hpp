/*
* hash_table.hpp
* Modified : 05/10/2023
*
* This class represents a templated hash table that uses a binary search tree for chaining.
* It is assumed that data items contain the method get_key, which returns a string.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

//This method is the default constructor for the HashTable, appointing all variable values
template  <typename T>
HashTable<T>::HashTable(int table_capacity)
{
//sets hashtable count to 0 on creation
count = 0;
//sets capacity to methods table_capacity
capacity = table_capacity;
//sets the size of the hashtable to the inputted capacity of the table
table.resize(capacity);
}

//This method is the destructor for the HashTable
template  <typename T>
HashTable<T>::~HashTable()
{
    //calls on clear method to delete all sections of the hashtable
    table.clear();
}

//This method controls the insertion of data into the hashtable
template  <typename T>
void HashTable<T>::insert(const T& data)
{
    //calls upon the hash_function grabbing the data's key to put it through it
    //sets the hash function key to the integer position 
    int position = hash_function(data.get_key());
    //inserts data into the table at the hash function's position
    table[position].insert(data);
    //adds to the total count
    count++;
}

//This method controls the removal of data in the hashtable
template  <typename T>
void HashTable<T>::remove(const std::string& key)
{
    //calls upon the hash_function grabbing the data's key to put it through it
    //sets the hash function key to the integer position 
    int position  = hash_function(key);
    //removes the item with the selected key at the table's hash function position
    table[position].remove(key);
    //removes from the total count
    count--;
}

//This method returns pointer to item with a selected key
template  <typename T>
T* HashTable<T>::get(const std::string& key) const
{
    //sets the hash function of key to the integer position 
    int position = hash_function(key);
    //loop checks if key's position is valid
    if(position != -1 && position < capacity)
    {
        //returns the position of the key in the table
        return table[position];
    }
    //returns nullptr if key is not found
    return nullptr;
}

//This method returns true or false on the existence of an item
template  <typename T>
bool HashTable<T>::contains(const std::string& key) const
{
    //sets the hash function of key to the integer position 
    int position = hash_function(key);
    //if position is valid check if the table contains it
    if(position != -1 && position < capacity)
    {
        //return true if table contains key
        if(table[position].contains(key))
        {
            return true;
        }
        //return false if table doesn't contain key
        else
        {
            return false;
        }
    }
    //return false if position is not valid
    else
    {
        return false;
    }
}

//This method clears all items from the hash table
template  <typename T>
void HashTable<T>::clear()
{
    int i = 0;
    
    //while integer i is less than the hashtable capacity enter loop
    while (i < capacity)
    {
        //if table section at i is empy increment to next place in hashtable
        if(table[i].empty())
        {
            i++;
        }
        //if table section at i is not empty clear the binary tree inside
        else
        {
        table[i].clear();
                
        }
        
    }
    //returns hashtable count to 0 once table has been cleared
    count = 0;
}

//This method checks whether or not the hashtable is empty
template  <typename T>
bool HashTable<T>::empty() const
{
    //If count is equal to 0 it returns true
    return count == 0;
}

//This method counts the size of the hashtable, including all binary cells
template  <typename T>
int HashTable<T>::size() const
{
    //returns the count variable that holds the number of areas filled in the table
    return count;
}

//This method prints every single item in the hash table
template  <typename T>
std::ostream&  HashTable<T>::print(std::ostream& os) const
{
    //This loop goes through all sections of hashtable until the capacity is reached
    for (int i = 0; i < capacity; i++)
    {
        //labels section number then prints it
        os << i << ": " << table[i] << "\n";
    }
    //returns the total string
    return os;  
}

//This method is the operator overloader that prints out the entire hash table
template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table)
{
    //if the table isnt empty implement the BT print method to print out the table sections
    if(!table.empty())
    {
        table.print(out);
    }
    else
    {
        out << "Hash Table empty";
    }
    //returns the total string
    return out;
}

//This method utilises the std::hash function to calculate hash value of selected keys
template  <typename T>
int  HashTable<T>::hash_function(const std::string& key) const
{
    //creates std::hash instance for a string
    std::hash<std::string> hf;
    //returns the hash of the key, used to store it in the hash table
    return hf(key) % capacity;
}