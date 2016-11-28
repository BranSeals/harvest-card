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

class Deck : public Card
{
public:
    Deck();
    ~Deck();
    
    //* Getters / Setters *//
    
    unsigned long getDeckSize(void);
    
    //* Methods *//
    
    void addCard(int);
    virtual void print(void);
    void shuffleDeck(void);
    int dealCardInt(void);
	Card dealCardObject(int);
    
private:
    std::vector<int> deck;
};

#endif /* Deck_hpp */
