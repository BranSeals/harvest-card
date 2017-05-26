// Copyright © 2016 Bran Seals. All rights reserved.
// Created: 2016-10-23
// Updated: 2017-12-04

#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"

/* Game Rules */
const std::string gameTitle{"Harvest Card Game"};
const std::string gameDescription{"A terminal-based farming card game for 1 - 4 players.\n"};
const int seasonLength{2};	// use multiples of the number of players to be fair
const int gameLength{seasonLength * 4}; // use multiples of 4 to play full years
const int startingGold{100};

int main()
{
    Game harvestGame(gameTitle, gameDescription, seasonLength, gameLength, startingGold);
	harvestGame.beginGame();

	system("pause");
    return 0;
}