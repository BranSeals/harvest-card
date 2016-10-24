//
//  Deck.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"
#include <vector>

class Deck
{
public:
    Deck();
    ~Deck();
    
    //* Getters / Setters *//
    
    /* Size of deck */
    int getDeckSize(void);
    void setDeckSize(int);
    
    /* Deck pointer; unsure if needed */
    Card* getDeckPtr(void);
    void setDeckPtr(Card*);
    
    //* Methods *//
    
    void addCard(Card);
    void printDeck(void);
    void shuffleDeck(void);
    Card dealCard(void);
    
private:
    std::vector<Card> deck;
    Card* deckPtr; // not sure yet if fully needed or wanted
    int deckSize{0}; // not sure if this will be useful; maybe
};

#endif /* Deck_hpp */
