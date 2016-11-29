//
//  Player.cpp
//  Harvest Game
//
//  Created by Bran Seals on 10/23/16.
//  Copyright © 2016 Brandon Seals. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

Player::Player()
{
    //std::cout << "\n> Player constructed\n";
}

Player::Player(int playerNum, std::string name, int age, int gold) :
playerNumber{playerNum}, playerName{name}, playerAge{age}, playerGold{gold}
{
    //std::cout << "\n> Player constructed\n";
}

Player::~Player()
{
    //std::cout << "\n> Player destructed\n";
}

//* Getters / Setters *//

/* Player order number */
int Player::getPlayerNumber(void)
{
    return playerNumber;
}

void Player::setPlayerNumber(int number)
{
    playerNumber = number;
}

/* Player name */
std::string Player::getPlayerName(void)
{
    return playerName;
}

void Player::setPlayerName(std::string name)
{
    playerName = name;
}


/* Player age */
int Player::getPlayerAge(void)
{
    return playerAge;
}

void Player::setPlayerAge(int age)
{
    playerAge = age;
}


/* Player gold */
int Player::getPlayerGold(void)
{
    return playerGold;
}

void Player::setPlayerGold(int gold)
{
    playerGold = gold;
}


//* Methods *//

void Player::addGold(int gold)
{
    playerGold += gold;
}

void Player::removeGold(int gold)
{
    playerGold -= gold;
}

void Player::print(void)
{
    std::cout << "\nPlayer " << playerNumber;
    std::cout << "\nName:\t" << playerName;
    std::cout << "\nAge:\t" << playerAge;
    std::cout << "\nGold:\t" << playerGold;
    std::cout << "\n";
}

void Player::buy(Card card)
{
	// remove money (card cost)
	playerFarm.addCard(card);
}

void Player::sell(Card card)
{
	// collect money (card value)
	// flip over card
	// do for all cards ready to be sold
}
