//
//  Farm.cpp
//  harvest-card
//
//  Created by Brandon Seals on 11/8/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Farm.hpp"
#include <iostream>
#include <iomanip>

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
	//print("Crop");
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
		return &playerTarget;
	} else if (playerLot == "Crop") {
		return &playerCrop;
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

void Farm::workFarm(int selectedTool, int selectedTarget)
{
	/* Make sure to not use card on itself */
	if (selectedTool + playerSeed.size() + 1 == selectedTarget) {
		std::cout << "\n> Cannot use card on itself.\n";
		return;
	}

	/* Get the ID of what can be targeted */
	int targetID = playerTool[selectedTool].getCardTarget();

	/* Point to deck of cards that tool card will target */
	/* Makes sure there is something to target */
	std::vector<Card>* lotPtr{nullptr};
	if (targetID == 5000) {
		if (playerSeed.size() == 0) {
			std::cout << "\n> Nothing to work on.\n";
			return;
		} else {
			lotPtr = Farm::pointTo("Seed");
		}
	} else if (targetID > 7000) {
		if (playerLivestock.size() == 0) {
			std::cout << "\n> Nothing to work on.\n";
			return;
		} else {
			lotPtr = Farm::pointTo("Livestock");
		}
	} else {
		std::cout << "\n*** Error in assigning pointer in workFarm() ***\n";
	}

	// get target selection from player


	// flip card if it can be flipped


	/* Exhaust tool card by turning face-down after use */
	playerTool[selectedTool].flipCard();

	// put livestock back into livestock lot and flipped seeds into crops

	// TO DO: get selection from player
	// TO DO: turn fill playerTarget bit into its own function
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

void Farm::printFarm(void)
{
	/* Find how many number selectors to use */
	/* Pull this out into own function */
	std::vector<int> intCompare;
	intCompare.push_back(playerSeed.size());
	intCompare.push_back(playerTool.size());
	intCompare.push_back(playerLivestock.size());
	int biggestLotSize{0};
	for (int i{0}; i < 3; ++i) {
		if (intCompare[i] > biggestLotSize) {
			biggestLotSize = intCompare[i];
		}
	}

	/* Start Farm formatting */
	std::cout << std::left;
	std::cout << std::endl;
	std::cout.fill('-');
	std::cout << std::setw(50) << "-- Farm ";
	std::cout.fill(' ');
	std::cout << std::endl;
	std::cout << std::right;
	std::cout << std::setw(10) << "Seeds:" << std::setw(19) << "Tools:"
		<< std::setw(21) << "Livestock:" << std::endl;
	std::cout << std::left;
	for (int i{0}; i < biggestLotSize; ++i) {
		if (playerSeed.size() > i) {
			std::cout << "[" << i + 1 << "] " << std::setw(15);
			std::cout << playerSeed[i].getCardName();
		} else {
			std::cout << "[" << " " << "] " << std::setw(15);
			std::cout << "";
		}
		if (playerTool.size() > i) {
			std::cout << "[" << i + playerSeed.size() + 1 << "] " << std::setw(15);
			std::cout << playerTool[i].getCardName();
		} else {
			std::cout << "[" << " " << "] " << std::setw(15);
			std::cout << "";
		}
		if (playerLivestock.size() > i) {
			std::cout << "[" << i + playerSeed.size() + playerTool.size() + 1 << "] " << std::setw(15);
			std::cout << playerLivestock[i].getCardName();
		} else {
			std::cout << "[" << " " << "] " << std::setw(15);
			std::cout << "";
		}
		std::cout << std::endl;
	}
	std::cout.fill('-');
	std::cout << std::setw(50) << "";
	std::cout.fill(' ');
}

int Farm::sizeOf(std::string playerLot)
{
	std::vector<Card>* lotPtr{Farm::pointTo(playerLot)};
	return (*lotPtr).size();

}

/* TO DO: implement pointer function to choose from multiple types of decks */
/* TO DO: add flag to check which bool value is required to use */
bool Farm::canSelectTool(int selection)	
{
	if (selection <= playerTool.size() && playerTool[selection].isCardFaceUp()) {	
		if (playerTool[selection].getCardTarget() == 5000 && playerSeed.size() == 0) {
			std::cout << "\n> No seeds can be worked on.\n";
			return false;
		} else if (playerLivestock.size() == 0) {
			std::cout << "\n> No livestock can be worked on.\n";
			return false;
		} else {
			return true;
		}
	} else if (!playerTool[selection].isCardFaceUp()) {
		std::cout << "\n> Tool already used this turn.\n";
		return false;
	} else {
		std::cout << "\n> Cannot select.\n";
		return false;
	}
}