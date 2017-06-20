// Copyright (C) 2016. All rights reserved.
// Created: 2017-06-19

// Purpose: takes file named editCards.txt used for easier editing of cards
// and translates into format used in the project. Can be used to quickly
// add, update, or remove cards.

#ifndef CardEdit_hpp
#define CardEdit_hpp

#include <string>
#include <vector>
#include <fstream>

class CardEdit
{
public:
    CardEdit();
    ~CardEdit();
    void loadEditList();
    void loadOldList();
    void createNewList();
    bool verifyEditList();
    bool verifyOldList();
    std::string createCardLine(std::vector<std::string>);
    void updateCardFile();
    void repopulateEditFile();
    std::vector<std::string> split(std::string);
private:
    std::vector<std::string> editList;
    std::vector<std::string> oldList;
    std::vector<std::string> newList;
    std::vector<std::string> currentList;
    std::string cardLine;
};
#endif
