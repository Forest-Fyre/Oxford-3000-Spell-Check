/*
* spell_checker.cpp
* Modified : 05/10/2023
*
* The class represents a simple spell checker that provides suggestions for incorrectly spelled words.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#include "spell_checker.h"

//This is the default constructor for SpellChecker
SpellChecker::SpellChecker()
{
    //nothing is initialised in constructor
    //dictionary is initialsed in private header
}

//This is the default destructor for SpellChecker
SpellChecker::~SpellChecker()
{
    //nothing to delete
}

//This method inserts a word into the SpellChecker dictionary
void SpellChecker::add_word(const std::string& word)
{
    //Calls hash_table.h method to insert word into dictionary
    dictionary.insert(word);
}

//This method deletes a word from the SpellChecker dictionary
void SpellChecker::remove_word(const std::string& word)
{
    //Calls hash_table.h method to remove word into dictionary
    dictionary.remove(word);
}

//This method runs the spelling checking on selected words
void SpellChecker::spell_check(const std::string& word) const
{   //make a copy of the inputted word
    std::string clone = word;
    //checks if clone is spelled correctly by calling spelled_correctly method
    if(spelled_correctly(clone))
    {
        //outputs that word is spelled correctly
        std::cout << clone << " is spelled correctly.";
    }
    else
    {
        //outputs that word is spelled incorrectly
        std::cout << clone << " is not spelled correctly.";
        //places all similar words to clone in vector
        std::vector<std::string> similarWords = similar_words(clone);
        //check if similar words vector is empty
        if(similarWords.empty())
        {
            //outputs that there are no similar words
            std::cout << " There are no suggestions.";
        }
        else
        {
            //outputs full list of suggestions
            std::cout << " Here is a list of suggestions: ";
            //loops through the entire similarWords vector
            for (int i = 0; i < similarWords.size(); ++i)
            {
                //outputs current similarWords increment
                std::cout << similarWords[i] << std::endl;
            }
        }
    }
}

//This method returns whether true or false at the correct spelling of a word
bool SpellChecker::spelled_correctly(const std::string& word) const
{
    //returns the contains method from the hash_table header to check for word
    return dictionary.contains(word);
}

//This method scans for words similar to an inputted string word
std::vector<std::string> SpellChecker::similar_words(const std::string& word) const
{
    std::vector<std::string> words;
    //make a copy of the inputted word
    std::string clone = word;
    //check swaps
    for (int i = 1; i < (int)clone.length(); i++)
    {
        std::swap(clone[i-1], clone[i]);
        // clone is now the modified word
        // checks if clone is a valid suggestion
        if (dictionary.contains(clone))
        {
            words.push_back(clone);
        }
        // put word back as before
        std::swap(clone[i-1], clone[i]);
    }
    //checks one-letter replacements
    for (int i = 0; i < (int)clone.length(); i++)
    {
        char orig = clone[i];
        //use ASCII codes for letters
        for(int j = 97; j < 123; j++)
        {
            clone[i] = j;
            // clone is now the modified word
            // checks if clone is valid suggestion
            if (dictionary.contains(clone))
            {
                //pushes clone to words if valid
                words.push_back(clone);
            }
        }
        // put word back as before
        clone[i] = orig;
    }
    // returns all similar words through the words vector
    return words;

}

//This method takes the spellchecker contents and prints them to a stream
std::ostream& SpellChecker::print(std::ostream& os) const
{
    //overloads dictionary to print
    os << dictionary;
    //returns string
    return os;
}

//This method prints the entire contents of the SpellChecker dictionary
std::ostream& operator << (std::ostream& os, const SpellChecker& sc)
{
    //returns the spellchecker print method, with the os stream
    return sc.print(os);

}

