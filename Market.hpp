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

class Market
{
public:
    Market();
    ~Market();

    virtual void print(void);
    std::vector<Card>* pointTo(std::string);
    void print(std::string);
	void printMarket(void);
    void fillStalls(Deck*);
    int getCostAt(int);
    Card removeFromStall(int);
	bool canSelect(int);

private:
    std::vector<Card> seedStall;
    std::vector<Card> toolStall;
    std::vector<Card> livestockStall;
	int numberInStall{3};
};
#endif /* Market_hpp */
