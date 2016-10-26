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
    std::cout << "\n> Card constructed\n";
}

Card::~Card()
{
    std::cout << "\n> Card destructed\n";
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

