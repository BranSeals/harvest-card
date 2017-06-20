// Copyright (C) 2016. All rights reserved.
// Created: 2017-06-19

#include "CardEdit.hpp"

CardEdit::CardEdit()
{
}

CardEdit::~CardEdit()
{
}

// Use to compare two lines by ID (cards.txt format)
// Helper function for binary search
bool binaryCardSearch(std::string a, std::string b)
{
    if ((a.substr(0, 4) == b.substr(0, 4))) {
        return true;
    }
    return false;
}

// Load cardEdit.txt into memory
void CardEdit::loadEditList()
{
    editList.clear();
    //fill editList with contents of cardEdit.txt
    std::ifstream inFile;
    std::string lineContent{""};

    inFile.open("cardEdit.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, lineContent);
        if (lineContent != "") {
            editList.push_back(lineContent);
        }
    }
}

// Load current cards.txt file into memory
void CardEdit::loadOldList()
{
    //fill oldList with contents of cards.txt
    std::ifstream inFile;
    std::string lineContent{""};

    inFile.open("cards.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, lineContent);
        oldList.push_back(lineContent);
    }
}

// Create new list in memory using cardEdit cards with cards.txt format
void CardEdit::createNewList()
{
    std::vector<std::string> fields;
    // for each element in editList, do createCardLine and add to newList
    for (int i{0}; i < editList.size(); i += 9) {
        for (int j{0}; j < 9; ++j) {
            fields.push_back( editList[i + j].substr(editList[i + j].find_first_of(":") + 2));
        }
        newList.push_back(createCardLine(fields));
        fields.clear();
    }
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
std::string CardEdit::createCardLine(std::vector<std::string> fields)
{
    std::string line{""};
    for (int i{0}; i < fields.size(); ++i) {
        line += fields[i] + "|";
    }
    return line;
}

// Use newList to update cards.txt with new additions or removals
void CardEdit::updateCardFile()
{
    // if card ID exists, check if info the same
    // if card ID doesn't exist, insert new card sorted
    // do a pass through cards.txt - if any IDs not in newList, remove from cards.txt

    std::ofstream outFile;
    outFile.open("cards.txt", std::ios::out | std::ios::trunc);
    for (int i{ 0 }; i < newList.size(); ++i) {
        outFile << newList[i] + "\n";
    }
    outFile.close();
}

// Repopulate cardEdit.txt using current cards.txt
void CardEdit::repopulateEditFile()
{
    //load cards.txt into currentList
    std::ifstream inFile;
    std::string lineContent{""};
    std::vector<std::string> fields;

    inFile.open("cards.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, lineContent);
        currentList.push_back(lineContent);
    }

    for (size_t i{0}; i < currentList.size(); ++i) {
        fields = split(currentList[i]);
        editList.push_back("Card ID: " + fields[0]);
        editList.push_back("Season: " + fields[1]);
        editList.push_back("Name: " + fields[2]);
        editList.push_back("Description: " + fields[3]);
        editList.push_back("Effect: " + fields[4]);
        editList.push_back("Target: " + fields[5]);
        editList.push_back("Value: " + fields[6]);
        editList.push_back("Cost: " + fields[7]);
        editList.push_back("Initial Face Value: " + fields[8] + "\n");
    }
    inFile.close();

    std::ofstream outFile;
    outFile.open("cardEdit.txt", std::ios::out | std::ios::trunc);
    for (int i{0}; i < editList.size(); ++i) {
        outFile << editList[i] + "\n";
    }
    outFile.close();
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
