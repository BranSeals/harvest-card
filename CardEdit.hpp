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
    void loadCardList();
    void convertEditToCardList();
    void verifyEditList();
    void verifyCardList();
    std::string createCardLine(std::vector<std::string>);
    void writeCardFile();
    void writeEditFile();
    std::vector<std::string> split(std::string);
    void updateCardFile();
private:
    std::vector<std::string> editList;
    std::vector<std::string> cardList;
};
#endif
