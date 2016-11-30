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

void Farm::removeCard(Card card)
{

}

void Farm::print(void)
{
	std::cout << "\n-- Farm --";
	print("Seed");
	print("Tool");
	print("Livestock");
	//print("Target"); // hide until time for selection
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
	} else if (playerLot == "Target") {
		return &targetBuffer;
	} else {
		std::cout << "\n*** Error in Farm::pointTo() ***\n";
	}
}

int Farm::sellProduct(int seasonCards)
{ 
	int goldEarned{0};
	if (seasonCards) {
		for (size_t i{0}; i < playerLivestock.size(); ++i) {
			if (playerLivestock[i].isCardFaceUp()) {
				goldEarned += playerLivestock[i].getCardValue();
				playerLivestock[i].resetCard();
			}
		}
	} else {
		for (size_t i{0}; i < playerSeed.size(); ++i) {
			if (playerSeed[i].isCardFaceUp()) {
				goldEarned += playerSeed[i].getCardValue();
				playerSeed[i].resetCard();
			}
		}
	}
	return goldEarned;
}

void Farm::workFarm(int selection)
{
	if (!playerTool[selection - 1].isCardFaceUp()) {							
		std::cout << "\n> Tool already used this turn.\n";
	} else {
		int targetID = playerTool[selection - 1].getCardTarget();

		std::vector<Card>* lotPtr{nullptr};

		if (targetID == 5000) {
			lotPtr = Farm::pointTo("Seed");
		} else if (targetID > 7000) {
			lotPtr = Farm::pointTo("Livestock");
		} else {
			std::cout << "\n*** Error in assigning pointer in workFarm() ***\n";
		}

		/* Fill targetBuffer vector */	
		for (size_t i{0}; i < (*lotPtr).size(); ++i) {
			if (targetID == 5000 && !(*lotPtr)[i].isCardFaceUp()) {
				targetBuffer.push_back((*lotPtr)[i]);
				(*lotPtr).erase((*lotPtr).begin() + i);
			}
			if (targetID == (*lotPtr)[i].getCardID() && !(*lotPtr)[i].isCardFaceUp()) {
				targetBuffer.push_back((*lotPtr)[i]);
				(*lotPtr).erase((*lotPtr).begin() + i);
			}
		}

		// if anything exists in target buffer, then print and get selection
		// print number of targets with a number to select
		if (targetBuffer.size() > 0) {
			print("Target"); // but with numbers to select
		}

		// flip card if it can be flipped


		/* Exhaust tool card by turning face-down after use */
		playerTool[selection - 1].flipCard();

		// put cards back into original lots
	}

	// TO DO: get selection from player
	// TO DO: turn fill target buffer bit into its own function
	// TO DO: add flag to print functions that show number selection by each item
}

//void Farm::moveCard(Card* cardToMove, std::string sendTo)
//{
//	//Card movedCard = *cardToMove;
//	std::vector<Card>* sendToPtr{Farm::pointTo(sendTo)};
//	
//	(*sendToPtr).push_back(movedCard); // NEEDS TESTING
//
//
//}

//		removedCard = seedStall[selection - 1];
//		seedStall.erase(seedStall.begin() + (selection));
