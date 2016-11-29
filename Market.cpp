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
	printStall("Seed");
	printStall("Tool");
	printStall("Livestock");
}

void Market::printDecks(void)
{
	Deck::print();
}

void Market::printStall(std::string stallName)
{
	std::vector<Card>* stallPtr{Market::pointTo(stallName)};
	std::cout << "\n" << stallName << ":\n";
	for (size_t i{0}; i < (*stallPtr).size(); ++i) {
		std::cout << (*stallPtr)[i].getCardName() << "\n";
	}
}

std::vector<Card>* Market::pointTo(std::string stallName)
{
	if (stallName == "Seed") {
		return &seedStall;
	} else if (stallName == "Tool") {
		return &toolStall;
	} else if (stallName == "Livestock") {
		return &livestockStall;
	} else {
		std::cout << "\n*** Error in Market::pointTo() ***\n";
	}
}

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