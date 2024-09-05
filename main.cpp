/*
* main.cpp
* Modified : 05/10/2023
*
* This file is a simple demonstration of a basic spell checking application.
*/
#include <iostream>
#include <fstream>

#include "word.h"
#include "spell_checker.h"

/*
* Populates the supplied SpellChecker with words read from the file "words.txt".
*/ 
void populate_sc(SpellChecker& sc)
{
	std::ifstream infile("words.txt");
	std::string word;
	//exit if we run out of lines
    while(std::getline(infile, word))
    {
		//insert the new word into the spell_checker
        sc.add_word(word);
    }

	infile.close();
}

/*
* The main function, which runs a few simple tests on the SpellChecker object.
*/ 
int main()
{
	// Construct and populate with initial word list
	SpellChecker sc;
	populate_sc(sc);

	// To display the spell checker's contents
	//std::cout << sc << std::endl;

	// Spell check a few words, some of which are spelled correctly and some are not
	sc.spell_check("test");
	sc.spell_check("etst");
	sc.spell_check("analyse");
	sc.spell_check("analyes");
	sc.spell_check("analyze");
	sc.spell_check("aat");
	sc.spell_check("beaf");
	sc.spell_check("SENG");
	sc.spell_check("foo");

	// Remove some words from the dictionary
	std::cout << "Removing some words" << std::endl;
	sc.remove_word("above");
	sc.remove_word("violence");
	sc.remove_word("bear");

	//recheck this word to confirm "bear" is no longer a suggestion
	sc.spell_check("beaf");

	//Add a few custom words, which did not previously exist
	std::cout << "Adding some words" << std::endl;
	sc.add_word("SENG");
	sc.add_word("foo");

	// Check that the new words are considered to be spelled correctly
	sc.spell_check("SENG");
	sc.spell_check("foo");
}