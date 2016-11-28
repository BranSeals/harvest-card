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

	virtual void print(void);
	void printStall(std::vector<Card>*, std::string);

    
    /* Check and fill empty slots in market */
    void fillStalls(void);
    
private:
	std::vector<Card> seedStall;
	std::vector<Card> toolStall;
	std::vector<Card> livestockStall;
};
#endif /* Market_hpp */
