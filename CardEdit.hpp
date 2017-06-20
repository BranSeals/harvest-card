// Copyright (C) 2016. All rights reserved.
// Created: 2017-06-19

// Purpose: Update cards.txt using cards_edit.txt or vice-versa.
//          cards_edit.txt is formatted for easy editing.

#ifndef CardEdit_hpp
#define CardEdit_hpp

#include <iostream>
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
    void convertCardToEditList();

    void verifyEditList();
    void verifyCardList();

    void writeEditFile();
    void writeCardFile();

    void updateEditFile();
    void updateCardFile();

    std::string shrink(std::vector<std::string>);
    std::vector<std::string> split(std::string);

private:
    std::vector<std::string> editList;
    std::vector<std::string> cardList;
};
#endif
