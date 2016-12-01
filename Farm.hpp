//
//  Farm.hpp
//  harvest-card
//
//  Created by Brandon Seals on 11/8/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#ifndef Farm_hpp
#define Farm_hpp

#include <iostream>
#include <vector>
#include "Card.hpp"

class Farm
{
public:
    Farm();
    ~Farm();

    void addCard(Card);
    void removeCard(Card);
    virtual void print(void);
    std::vector<Card>* pointTo(std::string);
    void print(std::string);
	void printFarm(void);
    int sellProduct(int);
    void workFarm(int, int);
    //void moveCard(Card*, std::string);
	int sizeOf(std::string);
	bool canSelectTool(int);

private:
    std::vector<Card> playerSeed;
    std::vector<Card> playerTool;
    std::vector<Card> playerLivestock;
    std::vector<Card> playerTarget;
	std::vector<Card> playerCrop;
};

#endif /* Farm_hpp */
