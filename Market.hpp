// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23

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
#endif
