/* Project name: Harvest Card Game
 * Author: Brandon Seals
 * Last revised: 2016-12-04
 * Description: CLI version of farming card game
 */

#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"

/* Game Rules */
const std::string gameTitle{"Harvest Card Game"};
const std::string gameDescription{"A terminal-based farming card game for 1 - 4 players.\n"};
const int seasonLength{2};
const int gameLength{seasonLength * 4}; // use multiples of 4 to play full years
const int startingGold{100};

int main()
{
    Game harvestGame(gameTitle, gameDescription, seasonLength, gameLength, startingGold);
	harvestGame.beginGame();

	system("pause");
    return 0;
}