// Copyright (C) 2016. All rights reserved.
// Created: 2017-06-19

#include "CardEdit.hpp"

CardEdit::CardEdit()
{
}

CardEdit::~CardEdit()
{
}

// Load cards_edit.txt into memory
void CardEdit::loadEditList()
{
    editList.clear();
    std::string line{""};

    std::ifstream inFile;
    inFile.open("cards_edit.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, line);
        if (line != "") {
            editList.push_back(line);
        }
    }
    verifyEditList();
}

// Load cards.txt file into memory
void CardEdit::loadCardList()
{
    cardList.clear();
    std::string line{""};

    std::ifstream inFile;
    inFile.open("cards.txt", std::ifstream::in);

    while (!inFile.eof()) {
        getline(inFile, line);
        if (line != "") {
            cardList.push_back(line);
        }
    }
    verifyCardList();
}

// Convert editList items to cards.txt format and push to cardList
void CardEdit::convertEditToCardList()
{
    cardList.clear();
    std::vector<std::string> fields;

    for (int i{0}; i < editList.size(); i += 9) {
        for (int j{0}; j < 9; ++j) {
            fields.push_back(editList[i + j].substr(editList[i + j].find_first_of(":") + 2));
        }
        cardList.push_back(shrink(fields));
        fields.clear();
    }
}

// Convert cardList items to card_edit.txt format and push to editList
void CardEdit::convertCardToEditList()
{
    editList.clear();
    std::vector<std::string> fields;

    for (int i{0}; i < cardList.size(); ++i) {
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
        fields.clear();
    }
}

// If editList improperly formatted, exit program
void CardEdit::verifyEditList()
{
    // every line not empty or a comment needs ":"
    // line with data must be found in list of attributes
    // data after colon must be able to be specific data type
    // if all aren't met, output formatting error and exit
}

// If cardList improperly formatted, exit program
void CardEdit::verifyCardList()
{
    // split line by delimiter and check data for types
    // if anything fails, output formatting error and exit
}

// Write cards_edit.txt using current cards.txt
void CardEdit::writeEditFile()
{
    editList.clear();
    std::vector<std::string> fields;

    if (!cardList.size()) {
        loadCardList();
    }

    convertCardToEditList();

    std::ofstream outFile;
    outFile.open("cards_edit.txt", std::ios::out | std::ios::trunc);
    for (int i{0}; i < editList.size(); ++i) {
        outFile << editList[i] + "\n";
    }
    outFile.close();
}

// Write cards.txt using current cards_edit.txt
void CardEdit::writeCardFile()
{
    cardList.clear();
    std::vector<std::string> fields;

    if (!editList.size()) {
        loadEditList();
    }

    convertEditToCardList();

    std::ofstream outFile;
    outFile.open("cards.txt", std::ios::out | std::ios::trunc);
    for (int i{0}; i < cardList.size(); ++i) {
        outFile << cardList[i] + "\n";
    }
    outFile.close();
}

// Call function to update cards.txt using cards_edit.txt
void CardEdit::updateCardFile()
{
    loadEditList();
    writeCardFile();
    writeEditFile(); // with new sorting
    std::cout << "> cards.txt updated successfully\n";
}

// Call function to update cards_edit.txt using cards.txt
void CardEdit::updateEditFile()
{
    loadCardList();
    writeEditFile(); 
    writeCardFile(); // with new sorting
    std::cout << "> cards_edit.txt updated successfully\n";
}

// Helper function for convertEditToCardList()
std::string CardEdit::shrink(std::vector<std::string> fields)
{
    std::string line{""};
    for (int i{0}; i < fields.size(); ++i) {
        line += fields[i] + "|";
    }
    return line;
}

// Helper function for convertCardToEditList()
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