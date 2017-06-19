// Copyright (C) 2016. All rights reserved.
// Created: 2017-06-19

#include "CardEdit.hpp"

// Load cardEdit.txt into memory
void CardEdit::loadEditList()
{
    //fill editList with contents of cardEdit.txt
}

// Load current cards.txt file into memory
void CardEdit::loadOldList()
{
    //fill oldList with contents of cards.txt
}

// Create new list in memory using cardEdit cards with cards.txt format
void CardEdit::createNewList()
{
    
}

// Returns true if cardEdit.txt is properly formatted
bool CardEdit::verifyEditList()
{
    
    return false;
}

// Returns true if cards.txt is properly formatted and sorted
bool CardEdit::verifyOldList()
{
    
    return false;
}

// Creates a line of card attributes in cards.txt format
std::string CardEdit::createCardLine()
{
    
    return "";
}

// Use newList to update cards.txt with new additions or removals
void CardEdit::updateCardFile()
{
    
}

// Repopulate cardEdit.txt using current cards.txt
void CardEdit::repopulateEditFile()
{
    //load cards.txt into currentList
    //for each line:
    //  push_back into editList with attribute and attribute value
    //write over cardEdit.txt with contents of editList 
}
