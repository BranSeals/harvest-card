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
    std::cout << "\n-- Player " << playerNumber << " --";
    std::cout << "\nName:\t" << playerName;
    std::cout << "\nAge:\t" << playerAge;
    std::cout << "\nGold:\t" << playerGold;
    std::cout << "\n";
}

void Player::printFarm(void)
{
    playerFarm.printFarm();
}

void Player::buy(Market* market)
{
	int selection = select("Buy anything?", 1, 9);

	if (selection && market->canSelect(selection)) {
		if (getPlayerGold() > market->getCostAt(selection)) {
			boughtCard = market->removeFromStall(selection);
			removeGold(boughtCard.getCardCost());
			playerFarm.addCard(boughtCard);
			std::cout << "\n> Bought " << boughtCard.getCardName() << " for "
				<< boughtCard.getCardCost() << " gold.\n";
		} else {
			std::cout << "\nNot enough gold.";
		}
	}
}

void Player::sell(int seasonCards)
{
    addGold(playerFarm.sellProduct(seasonCards));
}

void Player::useTool(int selection) {
    playerFarm.workFarm(selection);
}

int Player::select(std::string message, int low, int high) {
	if (low > high) {
		std::cout << "\n*** Error, first number must be lower than second ***\n";
		return 0;
	}
	int selection{low - 1};
	while (selection < low || selection > high) {
		if (low == high) {
			std::cout << "\n" << message << " [" << high << "] ";
		} else {
			std::cout << "\n" << message << " [" << low << "-" << high << "] ";
		}
		std::cin >> selection;
		std::cin.clear();
		std::cin.ignore();
	}
	return selection;
}

void Player::work(void)
{
	printFarm();
	playerFarm.sizeOf("Seed");

	/* Finds if a player can select a tool to use */
	int selection = select("Use which tool? ",
		1 + playerFarm.sizeOf("Seed"), playerFarm.sizeOf("Seed")
		+ playerFarm.sizeOf("Tool")) - playerFarm.sizeOf("Seed");

	if (playerFarm.canSelect(selection)) {
		playerFarm.workFarm(selection);
	}
	
	//playerFarm.workFarm();

	//playerFarm.workFarm(); // use this when I have a selection to make
	/*if (playerFarm.sizeOf("Target")) {
		playerFarm.print("Target");
		select("Use which tool? ", 1, playerFarm.sizeOf("Tool"));
	} else {
		std::cout << "\n> No tools to work with.\n";
	}*/
}