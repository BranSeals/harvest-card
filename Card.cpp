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
    } else {
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
    std::string lineContent{""};
    
	file.open("..\\cards.txt", std::ifstream::in);

    while (!file.eof()) {
        getline(file, lineContent);
        if (std::to_string(id) == lineContent) {

            getline(file, lineContent);
            setCardSeason(atoi(lineContent.c_str()));

            getline(file, lineContent);
            setCardName(lineContent);

            getline(file, lineContent);
            setCardDescription(lineContent);

            getline(file, lineContent);
            setCardEffect(atoi(lineContent.c_str()));

            getline(file, lineContent);
            setCardTarget(atoi(lineContent.c_str()));

            getline(file, lineContent);
            setCardValue(atoi(lineContent.c_str()));

            getline(file, lineContent);
            setCardCost(atoi(lineContent.c_str()));

            getline(file, lineContent);
            setCardFaceUp(std::stoi(lineContent.c_str()));
        }
    }

    file.close();
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