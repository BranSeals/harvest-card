//
//  Market.hpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Market_hpp
#define Market_hpp

#include "Deck.hpp"
#include "Card.hpp"

class Market : public Deck
{
public:
    Market();
    ~Market();
    
    //* Getters / Setters *//
    
    
    
    //* Methods *//

	virtual void printDeck(void);
    
    /* Check for empty slots in market */
    int checkEmptyStall(void);
    void fillEmptyStall(void);
    
private:
    Deck seedDeck;
    Deck toolDeck;
    Deck livestockDeck;
    Deck springDeck;
    Deck summerDeck;
    Deck autumnDeck;
    Deck winterDeck;
};
#endif /* Market_hpp */
