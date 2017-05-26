// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23
// Updated: 2017-05-26

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"
#include <vector>
#include <algorithm>

class Deck
{
public:
    Deck();
    ~Deck();

    //* Getters / Setters *//

    unsigned long getDeckSize(void);

    //* Methods *//

    virtual void print(void);
    void print(std::string);
    void shuffleDeck(void);
    int dealCard(std::string);
    std::vector<int>* pointTo(std::string);
    void addCard(int);
    Card dealCardObject(std::string);
    void fillDecks(void);

private:
    std::vector<int> deck;
    std::vector<int> springDeck;
    std::vector<int> summerDeck;
    std::vector<int> autumnDeck;
    std::vector<int> winterDeck;
    std::vector<int> seedDeck;
    std::vector<int> toolDeck;
    std::vector<int> livestockDeck;
};

#endif /* Deck_hpp */
