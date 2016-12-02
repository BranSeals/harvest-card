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
#include <iomanip>

Market::Market()
{
    //std::cout << "\n> Market constructed\n";
}

Market::~Market()
{
    //std::cout << "\n> Market destructed\n";
}

/* Basic print function for testing */
void Market::print(void)
{
    std::cout << "\n-- Market --";
    print("Seed");
    print("Tool");
    print("Livestock");
	print("Target");
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

/* Formatted Market for game display */
// TO DO: express i + 4 and i + 7 in terms of numberInStall
// TO DO: save top and bottom border into bar output
void Market::printMarket(void)
{
	std::cout << std::left;
	std::cout << std::endl;
	std::cout.fill('-');
	std::cout << std::setw(50) << "-- Market ";
	std::cout.fill(' ');
	std::cout << std::endl;
	std::cout << std::right;
	std::cout << std::setw(10) << "Seeds:" << std::setw(17) << "Tools:" 
		<< std::setw(21) << "Livestock:" << std::endl;
	std::cout << std::left;
	for (int i{0}; i < numberInStall; ++i) {
		if (seedStall.size() > i) {
			std::cout << "[" << i + 1 << "] " << std::setw(13);
			std::cout << seedStall[i].getCardName();	
		} else {
			std::cout << "[" << " " << "] " << std::setw(13);
			std::cout << "";
		}
		if (toolStall.size() > i) {
			std::cout << "[" << i + 4 << "] " << std::setw(13);
			std::cout << toolStall[i].getCardName();
		} else {
			std::cout << "[" << " " << "] " << std::setw(13);
			std::cout << "";
		}
		if (livestockStall.size() > i) {
			std::cout << "[" << i + 7 << "] " << std::setw(13);
			std::cout << livestockStall[i].getCardName();
		} else {
			std::cout << "[" << " " << "] " << std::setw(13);
			std::cout << "";
		}
		std::cout << std::endl;
	}
	std::cout.fill('-');
	std::cout << std::setw(50) << "";
	std::cout.fill(' ');
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
        seedStall.push_back(dealCardObject("Seed"));
    }
    while (toolStall.size() < 3) {
        toolStall.push_back(dealCardObject("Tool"));
    }
    while (livestockStall.size() < 3) {
        livestockStall.push_back(dealCardObject("Livestock"));
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
        seedStall.erase(seedStall.begin() + (selection - 1));
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

bool Market::canSelect(int selection) {

	if ((selection == 1 || selection == 2 || selection == 3)
		&& (selection <= seedStall.size())) {
		return true;
	} else if ((selection == 4 || selection == 5 || selection == 6)
		&& (selection - 3 <= toolStall.size())) {
		return true;
	} else if ((selection == 7 || selection == 8 || selection == 9)
		&& (selection - 6 <= livestockStall.size())) {
		return true;
	} else {
		std::cout << "\n> Cannot select.\n";
		return false;
	}
}