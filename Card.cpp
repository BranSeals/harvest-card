//
//  Card.cpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Card.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

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

/* ID of card */
int Card::getCardID(void)
{
    return cardID;
}

void Card::setCardID(int id)
{
    cardID = id;
}

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

/* Target of card effect */
int Card::getCardTarget(void)
{
    return cardTarget;
}

void Card::setCardTarget(int target)
{
    //std::cout << "target value: " << cardTarget << std::endl;
    if (target == 50000) {
        cardTarget = 5000;
    } 
	if (target > 70000) {
        cardTarget = target - 70000;
    }
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

/* Resets card to default value */
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

/* Assigns default values to card object from text file */
void Card::createByID(int id)
{
    /* Set ID attribute */
    setCardID(id);

    std::ifstream file;
    std::string lineContent{""};
    
    file.open("C:\\Users\\brand\\Desktop\\harvest-card\\cards.txt", std::ifstream::in);
    //file.open("cards.txt", std::ifstream::in);

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

