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
	// use card ID to place into deck using pointTo
	if (card.getCardID() < 5000) {
		std::cout << "\n*** Season Card cannot be placed into Farm ***\n";
	} else if (card.getCardID() < 6000) {
		playerSeed.push_back(card);
	} else if (card.getCardID() < 7000) {
		playerTool.push_back(card);
	} else if (card.getCardID() < 8000) {
		playerLivestock.push_back(card);
	} else {
		std::cout << "\n*** Error in Farm::addCard() ***\n";
	}
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