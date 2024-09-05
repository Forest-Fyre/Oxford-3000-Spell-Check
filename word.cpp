/*
* word.cpp
* Modified : 05/10/2023
*
* The implementation of a simple word object that contains a key and various comparison operators.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#include "word.h"

Word::Word()
{
    word = std::string("");
}

Word::Word(std::string w)
{
    word = w;
}

Word::~Word()
{
    //nothing to delete!
}

const std::string& Word::get_key() const
{
    return word;
}

std::ostream& operator <<(std::ostream& os, const Word& word)
{
    os << word.get_key();
    return os;
}

bool operator ==(const Word& w1, const Word& w2)
{
    return w1.get_key() == w2.get_key();
}

bool operator < (const Word& w1, const Word& w2)
{
	return w1.get_key() < w2.get_key();
}

bool operator > (const Word& w1, const Word& w2)
{
	return w1.get_key() > w2.get_key();
}

