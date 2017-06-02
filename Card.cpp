// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23
// Updated: 2017-05-26

#include "Card.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

Card::Card()
{
}

Card::Card(int id)
{
    createByID(id);
}

Card::~Card()
{
}

int Card::getCardID(void) const
{
    return cardID;
}

void Card::setCardID(int id)
{
    cardID = id;
}

std::string Card::getCardName(void)
{
    return cardName;
}

void Card::setCardName(std::string name)
{
    cardName = name;
}

bool Card::isCardFaceUp(void)
{
    return cardFaceUp;
}

void Card::setCardFaceUp(bool tf)
{
    cardFaceUp = tf;
}

int Card::getCardEffect(void)
{
    return cardEffect;
}

void Card::setCardEffect(int effect)
{
    cardEffect = effect;
}

int Card::getCardTarget(void)
{
    return cardTarget;
}

void Card::setCardTarget(int target)
{
    if (target == 50000) {
        cardTarget = 5000;
    } 
	if (target > 70000) {
        cardTarget = target - 70000;
    }
}

int Card::getCardCost(void)
{
return cardCost;
}

void Card::setCardCost(int cost)
{
	cardCost = cost;
};

int Card::getCardValue(void)
{
	return cardValue;
}

void Card::setCardValue(int value)
{
	cardValue = value;
}

int Card::getCardSeason(void)
{
	return cardSeason;
}
void Card::setCardSeason(int season)
{
	cardSeason = season;
}

std::string Card::getCardDescription(void)
{
	return cardDescription;
}

void Card::setCardDescription(std::string description)
{
	cardDescription = description;
}

void Card::flipCard(void)
{
	if (cardFaceUp == true) {
		cardFaceUp = false;
	}
	else {
		cardFaceUp = true;
	}
}

void Card::resetCard(void)
{
	createByID(getCardID());
}

void Card::print(void)
{
	std::cout << "\nName: " << getCardName() << "\nDescription: " << getCardDescription()
		<< "\nEffect: " << getCardEffect() << "\nTarget: " << getCardTarget() << "\nValue: " << getCardValue()
		<< "\nCost: " << getCardCost() << "\nFace-up: " << isCardFaceUp() << std::endl;
}

void Card::createByID(int id)
{
	setCardID(id);

	std::ifstream file;
	std::string lineContent{ "" };
	std::vector<std::string> fields;

	file.open("..\\cards.txt", std::ifstream::in);

	while (!file.eof()) {
		getline(file, lineContent);

		/* When ID matched, create Card object using data from file*/
		if (std::to_string(id) == lineContent.substr(0, 4)) {
			fields = split(lineContent);
			
			setCardID(std::stoi(fields[0].c_str()));
			setCardSeason(atoi(fields[1].c_str()));
			setCardName(fields[2]);
			setCardDescription(fields[3]);
			setCardEffect(atoi(fields[4].c_str()));
			setCardTarget(atoi(fields[5].c_str()));
			setCardValue(atoi(fields[6].c_str()));
			setCardCost(std::stoi(fields[7].c_str()));
			setCardFaceUp(atoi(fields[8].c_str()));
		}
		// TODO: use boolean flag and protect against case where ID not found
		// This should not be an issue since cards are manually selected, but 
		// this will be useful in case of a typo during balancing card choice
	}
	file.close();
}

std::vector<std::string> Card::split(std::string cardInfo)
{
	// Referencing vincenzo-pii from:
	// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c

	std::vector<std::string> fields;
	std::string delim = "|";
	size_t pos = 0;

	/* Split data between | - requires final | at end of record */
	while ((pos = cardInfo.find(delim)) != std::string::npos) {
		fields.push_back(cardInfo.substr(0, pos));
		cardInfo.erase(0, pos + delim.length());
	}
	return fields;
}

/* These are used for linked lists during evaluation */
bool Card::operator==(const Card& otherCard) const
{
	return getCardID() == otherCard.getCardID();
}

bool Card::operator!=(const Card& otherCard) const
{
	return !(getCardID() == otherCard.getCardID());
}