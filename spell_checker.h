/*
* spell_checker.h
* Modified : 05/10/2023
*
* The class represents a simple spell checker that provides suggestions for incorrectly spelled words.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_SPELL_CHECKER_H
#define SENG1120_SPELL_CHECKER_H

#include <string>
#include <vector>
#include "hash_table.h"
#include "word.h"

class SpellChecker
{
public:
    /*
    * Precondition:    None
    * Postcondition:   A new SpellChecker is created.
    */
    SpellChecker();

    /*
    * Precondition:    None
    * Postcondition:   The SpellChecker is destroyed and all associated memory is freed. Pointers should be set to nullptr.
    */
    ~SpellChecker();

    /*
    * Add a Word containing the supplied string to the dictionary, if it was not already present.
    * 
    * Precondition:    The SpellChecker has been initialised and the supplied word is valid.
    * Postcondition:   A new Word is inserted into the dictionary, if it was not already present.
    */
    void add_word(const std::string& word);
    
    /*
    * Remove the Word with the supplied key from the dictionary, if it is present.
    *
    * Precondition:    The SpellChecker has been initialised and the supplied word is valid.
    * Postcondition:   The Word with specified key is removed from the dictionary, if it was present.
    */
    void remove_word(const std::string& word);

    /*
    * Run spell checking on a word. This will determine if a word is spelled correctly or not.
    *
    * If the word is spelled correctly, this prints "<word> is spelled correctly." to cout.
    * 
    * If the word is not spelled correctly and there are potential corrections, this prints 
    * "<word> is not spelled correctly. Here is a list of suggestions: " followed by a list of 
    * suggestions, one per line, to cout.
    * 
    * If the word is not spelled correctly and there are no potential corrections, this prints 
    * "<word> is not spelled correctly. There are no suggestions." to cout.
    * 
    * Precondition:    The SpellChecker has been initialised and the supplied word is valid.
    * Postcondition:   A display message is presented.
    */ 
    void spell_check(const std::string& word) const;

    /*
    * Determine if the word is spelled correctly. A word is considered to be spelled correctly
    * if it exists in the dictionary.
    *
    * Precondition:    The SpellChecker has been initialised and the supplied word is valid.
    * Postcondition:   None.
    */ 
    bool spelled_correctly(const std::string& word) const;

    /*
    * Returns similar words (i.e., suggested corrections) for the supplied word. A word should 
    * only be included in the suggested corrections if it is spelled correctly. 
    *
    * Firstly, this returns words that can be formed by swapping any pair of adjacent letters.
    * Secondly, this returns words that can be formed by swapping any letter with any other letter.
    * Note: only lowercase letters are considered as potential replacements.
    *
    * Precondition:    The SpellChecker has been initialised and the supplied word is valid.
    * Postcondition:   None.
    */ 
    std::vector<std::string> similar_words(const std::string& word) const;

    /*
    * Appends the contents of the dictionary to the supplied stream. This should simply print the hash table
    * using its stream insertion operator.
    * 
    * Precondition:    The SpellChecker has been initialised.
    * Postcondition:   The SpellChecker has not been modified.
    */ 
    std::ostream& print(std::ostream& os) const;

private:
    HashTable<Word> dictionary;
};

/*
* Appends the contents of the SpellChecker's dictionary to the supplied stream. This should simply print the dictionary
* using its stream insertion operator.
* 
* Precondition:    The SpellChecker has been initialised.
* Postcondition:   The SpellChecker has not been modified.
*/ 
std::ostream& operator << (std::ostream& os, const SpellChecker& sc);

#endif