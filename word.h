/*
* word.h
* Modified : 05/10/2023
*
* This class represents a simple word object that contains a key and various comparison operators.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_WORD_H
#define SENG1120_WORD_H

#include <string>
#include <iostream>

class Word
{
public:
	/*
    * Precondition:    None
    * Postcondition:   A new Word is created with an empty string.
    */
    Word();

    /*
    * Precondition:    None
    * Postcondition:   A new Word is created with the supplied string.
    */
    Word(std::string w);

    /*
    * Precondition:    None
    * Postcondition:   The Word is destroyed and all associated memory is freed.
    */
    ~Word();

    /*
    * Return a reference to the underlying string as the key for the Word object.
    *
    * Precondition:    The word has been initialised.
    * Postcondition:   A reference to the word's string is returned.
    */
    const std::string& get_key() const;

private:
    std::string word;   // The string associated with the word.
};

/*
* The value of the word is appended to the stream, without any spaces.
*
* Precondition:    The supplied Word and ostream are valid.
* Postcondition:   The stream is updated with the word appended.
*/
std::ostream& operator << (std::ostream& os, const Word& word);

/*
* Determine if two words are equal. Two words are considered equal if they have the same underlying string.
*
* Precondition:    The supplied Words are initialised.
* Postcondition:   None.
*/
bool operator == (const Word& w1, const Word& w2);

/*
* Determine if the first word is ordered before the second word. 
*
* Precondition:    The supplied Words are initialised.
* Postcondition:   None.
*/
bool operator < (const Word& w1, const Word& w2);

/*
* Determine if the first word is ordered after the second word. 
*
* Precondition:    The supplied Words are initialised.
* Postcondition:   None.
*/
bool operator > (const Word& w1, const Word& w2);

#endif