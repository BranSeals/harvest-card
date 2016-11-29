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
	print("Seed");
	print("Tool");
	print("Livestock");
}

void Market::print(std::string stallName)
{
	if (stallName == "Decks") {
		Deck::print();
	} else {
		std::vector<Card>* stallPtr{Market::pointTo(stallName)};
		std::cout << "\n" << stallName << ":\n";
		for (size_t i{0}; i < (*stallPtr).size(); ++i) {
			std::cout << (*stallPtr)[i].getCardName() << "\n";
		}
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

int Market::getCostAt(int selection)
{
	return livestockStall[selection].getCardCost();
}

Card Market::removeFromStall(int selection)
{
	Card removedCard = livestockStall[selection];
	livestockStall.erase(livestockStall.begin() + (selection - 1));
	return removedCard;
}