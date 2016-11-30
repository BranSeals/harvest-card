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
		return nullptr; 
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
	if (selection == 1 || selection == 2 || selection == 3) {
		return seedStall[selection - 1].getCardCost();
	} else if (selection == 4 || selection == 5 || selection == 6) {
		return toolStall[selection - 4].getCardCost();
	} else if (selection == 7 || selection == 8 || selection == 9) {
		return livestockStall[selection - 7].getCardCost();
	} else {
		std::cout << "\n*** Error in getCostAt() ***\n";
		return 0;
	}
}

Card Market::removeFromStall(int selection)
{
	Card removedCard;

	if (selection == 1 || selection == 2 || selection == 3) {
		removedCard = seedStall[selection - 1];
		seedStall.erase(seedStall.begin() + (selection));
	} else if (selection == 4 || selection == 5 || selection == 6) {
		removedCard = toolStall[selection - 4];
		toolStall.erase(toolStall.begin() + (selection - 4));
	} else if (selection == 7 || selection == 8 || selection == 9) {
		removedCard = livestockStall[selection - 7];
		livestockStall.erase(livestockStall.begin() + (selection - 7));
	} else {
		std::cout << "\n*** Error in removeFromStall() ***\n";
	}
	return removedCard;
}