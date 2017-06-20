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
    editList.clear();
    std::string lineContent{""};

    std::ifstream inFile;
    inFile.open("cardEdit.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, lineContent);
        if (lineContent != "") {
            editList.push_back(lineContent);
        }
    }
    verifyEditList();
}

// Load cards.txt file into memory
void CardEdit::loadCardList()
{
    cardList.clear();
    std::string lineContent{""};

    std::ifstream inFile;
    inFile.open("cards.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, lineContent);
        if (lineContent != "") {
            cardList.push_back(lineContent);
        }
    }
    verifyCardList();
}

// Convert editList items to cardList with cards.txt formatting
void CardEdit::convertEditToCardList()
{
    cardList.clear();
    std::vector<std::string> fields;

    for (int i{0}; i < editList.size(); i += 9) {
        for (int j{0}; j < 9; ++j) {
            fields.push_back(editList[i + j].substr(editList[i + j].find_first_of(":") + 2));
        }
        cardList.push_back(createCardLine(fields));
        fields.clear();
    }
}

// Returns true if cardEdit.txt is properly formatted
void CardEdit::verifyEditList()
{
    // every line not empty or a comment needs ":"
    // line with data must be found in list of attributes
    // data after colon must be able to be specific data type
    // if all aren't met, output formatting error and exit
}

// Returns true if cards.txt is properly formatted and sorted
void CardEdit::verifyCardList()
{
    // split line by delimiter and check data for types
    // if anything fails, output formatting error and exit
}

// Create cards.txt format using vector of attributes
std::string CardEdit::createCardLine(std::vector<std::string> fields)
{
    std::string line{""};
    for (int i{0}; i < fields.size(); ++i) {
        line += fields[i] + "|";
    }
    return line;
}

// Rewrite cards.txt with cardList
void CardEdit::writeCardFile()
{
    //TODO: sort cardList by CardID here
    std::ofstream outFile;
    outFile.open("cards.txt", std::ios::out | std::ios::trunc);

    for (int i{ 0 }; i < cardList.size(); ++i) {
        outFile << cardList[i] + "\n";
    }
    outFile.close();
    writeEditFile(); // with new sorting
}

// Repopulate cardEdit.txt using current cards.txt
void CardEdit::writeEditFile()
{
    editList.clear();
    std::vector<std::string> fields;

    if (!cardList.size()) {
        loadCardList();
    }

    for (size_t i{0}; i < cardList.size(); ++i) {
        fields = split(cardList[i]);
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

void CardEdit::updateCardFile()
{
    loadEditList();
    convertEditToCardList();
    writeCardFile();
}