//
//  Farm.cpp
//  harvest-card
//
//  Created by Brandon Seals on 11/8/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Farm.hpp"
#include <iostream>

Farm::Farm()
{
}

Farm::~Farm()
{
}

void Farm::addCard(Card card)
{
	playerLivestock.push_back(card);
}

void Farm::print(void)
{
	std::cout << "\n-- Farm --";
	print("Seed");
	print("Tool");
	print("Livestock");
}

void Farm::print(std::string playerLot)
{
	std::vector<Card>* lotPtr{Farm::pointTo(playerLot)};
	std::cout << "\n" << playerLot << ":\n";
	for (size_t i{0}; i < (*lotPtr).size(); ++i) {
		std::cout << (*lotPtr)[i].getCardName() << "\n";
	}
}
std::vector<Card>* Farm::pointTo(std::string playerLot)
{
	if (playerLot == "Seed") {
		return &playerSeed;
	} else if (playerLot == "Tool") {
		return &playerTool;
	} else if (playerLot == "Livestock") {
		return &playerLivestock;
	} else {
		std::cout << "\n*** Error in Farm::pointTo() ***\n";
	}
}