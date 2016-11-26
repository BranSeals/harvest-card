//
//  Card.cpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Card.hpp"
#include <iostream>

Card::Card()
{
    //std::cout << "\n> Card constructed\n";
}

Card::Card(int id)
{
	createByID(id);
}

Card::~Card()
{
    //std::cout << "\n> Card destructed\n";
}

//* Getters / Setters *//

/* Name of card */
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

/* Effect on card, referring to list of effects */
int Card::getCardEffect(void)
{
    return cardEffect;
}

void Card::setCardEffect(int effect)
{
    cardEffect = effect;
}

/* Cost of card in Market */
int Card::getCardCost(void)
{
    return cardCost;
}

void Card::setCardCost(int cost)
{
    cardCost = cost;
};

/* Value of card when sold */
int Card::getCardValue(void)
{
    return cardValue;
}

void Card::setCardValue(int value)
{
    cardValue = value;
}

/* Season of card */
int Card::getCardSeason(void)
{
	return cardSeason;
}
void Card::setCardSeason(int season)
{
	cardSeason = season;
}

/* Description of card */
std::string Card::getCardDescription(void)
{
    return cardDescription;
}

void Card::setCardDescription(std::string description)
{
    cardDescription = description;
}

//* Methods *//

void Card::flipCard(void)
{
    if (cardFaceUp == true) {
        cardFaceUp = false;
    } else {
        cardFaceUp = true;
    }
}

void Card::createByID(int id)
{
	/* Set Season attribute */
	if (((id / 1000) > 0) && ((id / 1000) < 5)) {
		setCardSeason(id / 1000);
	}
	if ((id / 1000) == 5) {
		setCardSeason((id - 5000) / 100);
	}


}

