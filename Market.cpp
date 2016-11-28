//
//  Market.cpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Market.hpp"
#include "Card.hpp"
#include <iostream>

Market::Market()
{
    //std::cout << "\n> Market constructed\n";
}

Market::~Market()
{
    //std::cout << "\n> Market destructed\n";
}

//void Market::print(void)
//{
//	//
//}

void Market::fillDecks(void)
{
	/*int tempCard;
	while (getDeckSize() > 0) {
		tempCard = Deck::dealCard();
		if ((tempCard / 1000) == 1) {
			
		}
	}*/
	// while deck not empty
	// deal card to deck it matches
}

// NEEDS TESTING
int Market::dealCard(std::vector<int>* deck)
{
	int dealtCard{(*deck)[(*deck).size() - 1]};
	(*deck).pop_back();
	return dealtCard;
}

// NEEDS TESTING
void Market::refillEmptyStall(void)
{
	while (seedStall.size() < 3) {
		seedStall.push_back(dealSeedCard());
	}
	while (toolStall.size() < 3) {
		toolStall.push_back(dealToolCard());
	}
	while (livestockStall.size() < 3) {
		livestockStall.push_back(dealLivestockCard());
	}
}
