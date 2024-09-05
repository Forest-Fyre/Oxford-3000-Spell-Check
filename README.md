# Spell Checker Project

---

## Overview

This C++ project implements a basic **spell-checking program** using a **hash table** with **binary search tree (BST)** chaining for managing a dictionary of words. The goal is to efficiently check if a word is spelled correctly, suggest potential corrections for misspelled words, and allow the user to add or remove words from the dictionary.

The program uses a list of ≈3000 words as the dictionary, which is stored in a hash table. For misspelled words, the program suggests corrections by performing single-character substitutions and adjacent character swaps.

---

## Features

- **Check spelling**: Verify whether a word exists in the dictionary.
- **Suggest corrections**: Suggest possible correct spellings for misspelled words using:
  - Single-character substitutions.
  - Adjacent character swaps.
- **Modify dictionary**: Add or remove words from the dictionary dynamically.
- **Efficient data structures**: 
  - A **Hash Table** to store the dictionary with **BST chaining** for collision handling.
  - A **Binary Search Tree (BST)** to manage word lists inside each hash table bucket.

---

## Files

The following files are included in the project:

- **`main.cpp`**: Contains the main function to initialize the spell checker and execute basic operations.
- **`spell_checker.h`**: Header file for the `SpellChecker` class, managing dictionary operations.
- **`word.h / word.cpp`**: Defines and implements the `Word` class, representing words stored in the hash table.
- **`bt_node.h`**: Templated class for binary tree nodes.
- **`bs_tree.h`**: Templated class for the binary search tree used for chaining in the hash table.
- **`hash_table.h`**: Implements the hash table with BST chaining.
- **`makefile`**: Automates the build process for the project.
- **`words.txt`**: Contains the list of ≈3000 words used to populate the dictionary.

---

## Data Structures

1. **BTNode**: Represents a node in the binary search tree, storing key-value pairs used in the chaining mechanism of the hash table.
2. **Binary Search Tree (BSTree)**: Manages dictionary entries within each bucket of the hash table. It provides efficient searching, insertion, and deletion operations.
3. **Hash Table**: Uses a hash function to map words into buckets, each of which stores a binary search tree for handling collisions.

---
