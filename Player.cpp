// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23

#include "Player.hpp"
#include <iostream>

Player::Player()
{
}

Player::Player(int playerNum, std::string name, int age, int gold) :
playerNumber{playerNum}, playerName{name}, playerAge{age}, playerGold{gold}
{
}

Player::~Player()
{
}

int Player::getPlayerNumber(void)
{
    return playerNumber;
}

void Player::setPlayerNumber(int number)
{
    playerNumber = number;
}

std::string Player::getPlayerName(void)
{
    return playerName;
}

void Player::setPlayerName(std::string name)
{
    playerName = name;
}

int Player::getPlayerAge(void)
{
    return playerAge;
}

void Player::setPlayerAge(int age)
{
    playerAge = age;
}

int Player::getPlayerGold(void)
{
    return playerGold;
}

void Player::setPlayerGold(int gold)
{
    playerGold = gold;
}

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

    if (selection == 0) {
	advancePhase();
	return;
    }

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

int Player::advancePhase(void)
{
    return ++playerPhase;
}

int Player::getPlayerPhase(void)
{
    return playerPhase;
}
void Player::setPlayerPhase(int phase)
{
    playerPhase = phase;
}

void Player::sellProduct()
{
    addGold(playerFarm.sellProduct());
    advancePhase();
}

int Player::select(std::string message, int low, int high) {
    if (low > high) {
	std::cout << "\n*** Error, first number must be lower than second ***\n";
	return 0;
    }

    int selection{0};
    do {
	if (low == high) {
	    std::cout << "\n" << message << " [" << high << ", 0 to cancel] ";
	} else {
	    std::cout << "\n" << message << " [" << low << "-" << high << ", 0 to cancel] ";
	}
	std::cin >> selection;
	std::cin.clear();
	std::cin.ignore();
    } while ((selection < low || selection > high) && (selection != 0));
    return selection;
}

void Player::work(void)
{
    printFarm();

    /* Make sure there are tools to work with */
    if (playerFarm.sizeOf("Tool") == 0) {
	std::cout << "\n> No tools to work with.\n";
	advancePhase();
	return;
    }

    /* Player selects a tool - automatically reduces number to proper tool index */
    // TODO : separate selection and selected tool variables; use selection in case it is 0 to cancel
    int selection = select("Use which tool?", 1 + playerFarm.sizeOf("Seed"), playerFarm.sizeOf("Seed") + playerFarm.sizeOf("Tool"));
    if (selection == 0) {
	advancePhase();
	return;
    }

    int selectedTool = selection - playerFarm.sizeOf("Seed") - 1;

    /* Checks if a tool can be used */
    if (!playerFarm.canSelectTool(selectedTool)) {
	return;
    }

    /* Player selects a target */
    int selectedTarget = select("Use tool on which card?", 1, playerFarm.sizeOf("Seed") + playerFarm.sizeOf("Tool") + playerFarm.sizeOf("Livestock"));

    /* Work farm - if target is improper; workFarm will say so */
    playerFarm.workFarm(selectedTool, selectedTarget);
}

void Player::refreshTools(void)
{
    playerFarm.refreshTools();
}

void Player::harvestCrops(int season)
{
    addGold(playerFarm.harvest(season));
}
