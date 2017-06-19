// Copyright (C) 2016. All rights reserved.
// Created: 2017-06-19

#include "CardEdit.hpp"

CardEdit::CardEdit()
{
}

CardEdit::~CardEdit()
{
}
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
    std::ifstream file;
    std::string lineContent{""};
    std::vector<std::string> fields;

    file.open("cards.txt", std::ifstream::in);

    while (!file.eof()) {
        getline(file, lineContent);
        currentList.push_back(lineContent);
    }
   
    for (size_t i{0}; i < currentList.size(); ++i) {
        fields = split(lineContent);
        editList.push_back("Card ID: " << fields[0];
        editList.push_back("Season: " << fields[1];
        editList.push_back("Name: " << fields[2];
        editList.push_back("Description: " << fields[3];
        editList.push_back("Effect: " << fields[4];
        editList.push_back("Target: " << fields[5];
        editList.push_back("Value: " << fields[6];
        editList.push_back("Cost: " << fields[7];
        editList.push_back("Initial Face Value: " << fields[8];
        editList.push_back("\n");
    }
    //write over cardEdit.txt with contents of editList 
}

std::vector<std::string> CardEdit::split(std::string cardInfo)
{
    std::vector<std::string> fields;
    std::string delim = "|";
    size_t pos = 0;

    while ((pos = cardInfo.find(delim)) != std::string::npos) {
        fields.push_back(cardInfo.substr(0, pos));
        cardInfo.erase(0, pos + delim.length());
    }
    return fields;
}
