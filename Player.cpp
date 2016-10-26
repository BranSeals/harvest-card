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
    std::cout << "\n> Player constructed\n";
}

Player::~Player()
{
    std::cout << "\n> Player destructed\n";
}

//* Getters / Setters *//

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
