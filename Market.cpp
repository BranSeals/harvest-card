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

void Market::print(void)
{
	std::cout << "\n-- Market --";
	printStall(&seedStall, "Seeds");
	printStall(&toolStall, "Tools");
	printStall(&livestockStall, "Livestock");
}

void Market::printDecks(void)
{
	Deck::print();
}

void Market::printStall(std::vector<Card>* stall, std::string name)
{
	std::cout << "\n" << name << ":\n";
	for (size_t i{0}; i < (*stall).size(); ++i) {
		std::cout << (*stall)[i].getCardName() << "\n";
	}
}

// NEEDS TESTING
void Market::fillStalls(void)
{
	while (seedStall.size() < 3) {
		seedStall.push_back(dealCard("Seed"));
	}
	while (toolStall.size() < 3) {
		toolStall.push_back(dealCard("Tool"));
	}
	while (livestockStall.size() < 3) {
		livestockStall.push_back(dealCard("Livestock"));
	}
}