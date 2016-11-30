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
	int sellProduct(int);
	void workFarm(int);
	//void moveCard(Card*, std::string);

private:
	std::vector<Card> playerSeed;
	std::vector<Card> playerTool;
	std::vector<Card> playerLivestock;
	std::vector<Card> targetBuffer;
};

#endif /* Farm_hpp */
