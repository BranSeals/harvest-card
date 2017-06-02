// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-11-08

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
	/* TODO: unsure if needed, but could be useful */
}

void Farm::print(void)
{
	std::cout << "\n-- Farm --";
	print("Seed");
	print("Tool");
	print("Livestock");
	print("Crop");
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
	} else if (playerLot == "Crop") {
		return &playerCrop;
	} else {
		std::cout << "\n*** Error in Farm::pointTo() ***\n";
		return nullptr;
	}
}

int Farm::sellProduct()
{
	int goldEarned{0};
	for (size_t i{0}; i < playerLivestock.size(); ++i) {
		if (playerLivestock[i].isCardFaceUp()) {
			goldEarned += playerLivestock[i].getCardValue();
			playerLivestock[i].resetCard();
		}
	}
	std::cout << "\n> Earned " << goldEarned << " gold from livestock \n";
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
	/* Internal if statements make sure there is something to target */
	std::vector<Card>* lotPtr{nullptr};

	if (targetID == 5000) {
		if (playerSeed.size() == 0) {
			std::cout << "\n> Nothing to work on\n";
			return;
		} else if (selectedTarget > sizeOf("Seed")) {
			std::cout << "\n> Wrong target selected\n";
			return;
		}else {
			lotPtr = Farm::pointTo("Seed");
			--selectedTarget;
		}
	} else if (targetID > 7000) {
		if (playerLivestock.size() == 0) {
			std::cout << "\n> Nothing to work on\n";
			return;
		} else if (selectedTarget < sizeOf("Seed")) {
			std::cout << "\n> Wrong target selected\n";
			return;
		}else {
			lotPtr = Farm::pointTo("Livestock");
			selectedTarget = selectedTarget - playerSeed.size() - playerTool.size() - 1;
		}
	} else {
		std::cout << "\n*** Error in assigning pointer in workFarm() ***\n";
	}

  /* See if card has already been worked on */
	if ((*lotPtr)[selectedTarget].isCardFaceUp()) {
		std::cout << "\n> Target already face-up\n";
		return;
	} else {
		(*lotPtr)[selectedTarget].flipCard();
	}

	std::cout << "\n> Used " << playerTool[selectedTool].getCardName() << " on "
		<< (*lotPtr)[selectedTarget].getCardName() << std::endl;

	/* Exhaust tool card by turning face-down after use */
	playerTool[selectedTool].flipCard();

	/* Send flipped seed card to crop field */
	if (targetID == 5000) {
		playerCrop.push_back((*lotPtr)[selectedTarget]);
		(*lotPtr).erase((*lotPtr).begin() + (selectedTarget));
	}
}

void Farm::printFarm(void)
{
	/* Find how many number selectors to use */
	/* TODO: Pull this out into own function */
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
		<< std::setw(23) << "Livestock:" << std::endl;
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
	std::cout << std::endl;
	std::cout.fill('-');

	if (playerCrop.size() > 0) {
		std::cout << std::setw(50) << "-- Crop ";
		std::cout.fill(' ');
		std::cout << std::endl;
		//playerCrop.sortByName() // sort crops alphabetically
		for (int i{0}; i < playerCrop.size(); ++i) {
			std::cout << playerCrop[i].getCardName() << " ";
		}
		std::cout << std::endl;
		std::cout.fill('-');
		std::cout << std::setw(50) << "";
	} else {
		std::cout << std::setw(50) << "";
	}
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
			std::cout << "\n> No seeds can be worked on\n";
			return false;
		} else if (playerTool[selection].getCardTarget() >= 7000 && playerLivestock.size() == 0) {
			std::cout << "\n> No livestock can be worked on\n";
			return false;
		} else {
			return true;
		}
	} else if (!playerTool[selection].isCardFaceUp()) {
		std::cout << "\n> Tool already used this turn\n";
		return false;
	} else {
		std::cout << "\n> Cannot select\n";
		return false;
	}
}

void Farm::refreshTools(void) {
	for (size_t i{0}; i < playerTool.size(); ++i) {
		if (!playerTool[i].isCardFaceUp()) {
			playerTool[i].flipCard();
		}
	}
}

// TO DO: use clear to empty crop field after harvest
int Farm::harvest(int season) {
	int earnedGold{0};
	int bonusGold{0};
	for (size_t i{0}; i < playerCrop.size(); ++i) {
		earnedGold += playerCrop[i].getCardValue();
		if (playerCrop[i].getCardSeason() == season) {
			bonusGold += seasonBonus;
		}
	}
	if (playerCrop.size()) {
		playerCrop.erase(playerCrop.begin() + playerCrop.size() - 1);
	}
	earnedGold += bonusGold;
	std::cout << " made " << earnedGold << " gold during the harvest (+" 
		<< bonusGold << " bonus gold for seasonal crops)\n";
	return earnedGold;
}
